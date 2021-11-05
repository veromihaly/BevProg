#include "std_lib_facilities.h"
//tokenek létrehozása
struct Token {
	char kind;
	double value;
	string name;
	Token(char ch) :kind(ch), value(0) { } //a ';', ')' stb. karaktereknek
	Token(char ch, double val) :kind(ch), value(val) { } //számoknak
	Token(char ch, string val) :kind(ch), name(val) { } //változókhoz
};

class Token_stream {
	bool full;
	Token buffer;
public:
	Token_stream() :full(0), buffer(0) { 
        }
	Token get();
	void unget(Token t) { 
                buffer=t; full=true; 
        }
	void ignore(char);
};
//token stream függvények definiálása

const char set ='S';
const char let = 'L';
const char quit = 'q'; 
const char print = '=';
const char number = '8';
const char name = 'a';
const char sqr='r';
const char power='P';
const string close = "exit";
const string declarkey = "#";
const string redeclar ="set";
const string squareroot="sqrt";
const string powerof="pow";
//konstansok tokenekhez

Token Token_stream::get() //karakter bekérése az input streamből, majd abból token készítése
{
	if (full) { full=false; return buffer; }
	char ch;
	cin >> ch;
	switch (ch) {
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case print:
	case quit: //'q' szükséges a kilépéshez
	case ',':
		return Token(ch); //első token típus
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9': {	
			cin.unget(); //szám karakter miatt vissza kell tennünk azt az input streambe, hogy ki tudjuk kérni magát a számot
			double val;
			cin >> val; //maga a szám bekérése
			return Token(number,val); //szám típusú token visszaadása
		}
		default:
			if ((isalpha(ch)) || (ch=='#'))  //Változók kezelése
			{
				string s;
				s += ch;
				while(cin.get(ch) && (isalpha(ch) || isdigit(ch))) s+=ch; //hozzá kell fűzni, alapból mindig felülírja az 's' karaktert
				cin.unget();
				if (s == declarkey) return Token(let);
				if (s == redeclar) return Token(set);
				if (s == squareroot) return Token(sqr);
				if (s == powerof) return Token(power);
				if (s == close) return Token(quit);
			return Token(name,s);
			//Különféle föggvényekhez Token rendelése
		}
		cin.putback(';');
		error("Bad token");

	}
	return 0; //error után is vissza kell térnünk
}

void Token_stream::ignore(char c){ //error után további számítási lehetőség
	if (full && c==buffer.kind) {
		full = false;
		return;
	}
	full = false;

	char ch;
	while (cin>>ch)
		if (ch==c) return; //folyamatosan kéri be a változókat a c karakterig
}

struct Variable { //változókhoz szükséges struktúra
	string name;
	double value;
	Variable(string n, double v) :name(n), value(v) { } //Példa változó
};

vector<Variable> names; //változók eltárolása egy vektorban	

double get_value(string s)
{
	for (auto& v : names ) //logikai hiba a változók megadásakor
		if (v.name == s) return v.value;
	cin.putback(';');
	error("get: undefined name ",s);

	return 0; //vissza kell térnünk az error után is valamivel.
}
void set_value(string s, double d) //Változók újradeklarása
{
	for (int i = 0; i<=names.size(); ++i)
		if (names[i].name == s) {
			names[i].value = d;
			return;
		}
	cin.putback(';');
	error("set: undefined name ",s);

}

bool is_declared(string s)  //függvény arra, hogy ne tudjunk kétszer deklarálni egy változót.
{
	for (int i = 0; i<names.size(); ++i)
		if (names[i].name == s) return true;
	return false;
}

Token_stream ts; // deklaráció a Token_stream-ből

double expression(); // deklaráció az expression-ből
// így tudjuk mind a 2-t használni
double primary()
{
	Token t = ts.get();
	switch (t.kind) 
	{
		case '(':
		{	
			double d = expression();
			t = ts.get();
			if (t.kind != ')') error("')' expected");
			return d; 
		}
		case number:
			return t.value;
		case '-':
			return - primary(); //negatív számok kezelése
		case name:
			return get_value(t.name); //változó értékének bekérése
		default:
			cin.putback('=');
			error("primary expected");
	}
	return -1; //visszatárás error után
}

double term()//szorzás és osztás kezelése
	{
	double left = primary();
	Token t = ts.get();  
	while(true) {
		
		switch(t.kind) {
			case '*':
				left *= primary();
				t=ts.get();
				break;
			case '/':
			{	double d = primary();
				if (d == 0) error("cannot divide by zero");
				left /= d;
				t=ts.get();
				break;
			}
			case '%':
			{
				double d = primary();
				if (d == 0) error("%: cannot divide by zero");
				left = fmod (left, d);
				t = ts.get();
				break;
			}
			default:
				ts.unget(t);
				return left;
		}
	}
}
double expression() //összeadás és kivonás kezelése
{
	double left = term();
	Token t = ts.get(); 
	while(true) {
		switch(t.kind) 
		{
			case '+':
				left += term();
				t=ts.get();
				break;
			case '-':
				left -= term();
				t=ts.get();
				break;
			default:
				ts.unget(t);
				return left;
		}
	}
}
double declaration()  //változó deklarálása
{
	Token t = ts.get();
	if (t.kind != 'a') error ("name expected in declaration");
	string name = t.name;
	if (is_declared(name)) error(name, " declared twice");
	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of " ,name);
	double d = expression();
	names.push_back(Variable(name,d));
	return d;
}
double powerx() //hatványozás
{
	Token t1=ts.get();
	if (t1.kind!='(') error("'(' expected at the beginning of pow ");
	double base=expression();
	Token t2=ts.get();
	if (t2.kind!=',') error("',' expected at between the two numbers in pow");
	double tmpexp=expression();
	int exp = narrow_cast<int>(tmpexp);
	Token t3=ts.get();
	if (t3.kind!=')') error("')' expected at the end of pow ");
	if (exp==0) return 1;
	else if (exp ==1 ) return base;
	double result=base;
	for (int i=1; i<exp;i++)
	{
		result*=base;
	}
	return result;
}
double fsqrt() //gyökvönás 
{
	double d=expression();
	if (d <0) error("Can't take the squareroot of a negative number in the domain of real numbers");
	else
		{
		return sqrt(d);
		}
	return 0;
}	
double statement() //mit kaptunk
{
	Token t = ts.get();
	switch(t.kind) {
	case let:
		return declaration();
	case sqr:
		return fsqrt();
	case power:
		return powerx();
	case set: 
		{
		Token t1=ts.get();
		if (is_declared(t1.name))
		{
			Token t2 = ts.get();
			if (t2.kind != '=') error("= missing in redeclaration of " ,name);
			double d=expression();
			set_value(t1.name, d);
		}

		else (error("Can't redeclar a variable if it wasn't declared in the first place."));

		}
	default:
		ts.unget(t);
		return expression();
	}
}
void clean_up_mess()  //error utáni további számolás
{
	ts.ignore(print);
}
const string prompt = "> ";
const string result = "= ";
void calculate()
{
	while(true) try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t=ts.get();  
		if (t.kind == quit) return;
		ts.unget(t);
		cout << result << statement() << endl;
	}
	catch(runtime_error& e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
}
int main()
	try {
		names.push_back(Variable("k",1000)); 
		calculate();
		return 0;
	}
	catch (exception& e) {
		cerr << "exception: " << e.what() << endl;
		char c;
		while (cin >>c&& c!=';') ;
		return 1;
	}
	catch (...) {
		cerr << "exception\n";
		char c;
		while (cin>>c && c!=';');
		return 2;
	}
