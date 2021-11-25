#include "../std_lib_facilities.h"


int main(){

	int birth_year = 2002;

	cout << "Decimal:\t" << birth_year << "\n";
    cout << "Hexadecimal:\t" << hex << birth_year << "\n";
    cout << "Octal:\t\t" << oct << birth_year << "\n";
    

	
    int age = 19;
	cout << "Decimal:\t" << age << "\n"; // octalban maradt a kiírási formátum.
    cout << "Hexadecimal:\t" << hex << age << "\n";
    cout << "Octal:\t\t" << oct << age << "\n";
    

    cout << "Age:";
    cout << dec << "\t" << age << "\t(Decimal)\n";


    int a, b, c, d;
    
    cin >> a >> oct >> b >> hex >> c >> d; // dec(a) oct(b) hex(c,d)

    cout << a << "\t" << b << "\t" << c << "\t" << d << endl;



    cout << defaultfloat << 1234567.89 << "\t" << fixed << 1234567.89 << "\t" << scientific << 1234567.89 << "\n";
    // fiexed - most accurate


 cout << "|" << setw(2) << "Last_name"<< "\t|"<< setw(8) << "First_name" << "\t|" << setw(16) << "Telephone number" << "\t|" << setw(25) << "Email address" << "|\n";
    cout << "|" << setw(2) << "Papp"<< "\t|" << setw(8) << "Dávid"  << "\t|" << setw(16) << "06306618148" << "\t|" << setw(25) << "pappdavid32@gmail.com"      << "|\n";
    cout << "|" << setw(2) << "Verő"<< "\t|" << setw(8) << "Mihály" << "\t|" << setw(16) << "06703153243" << "\t|" << setw(25) << "veromihaly18@gmail.com"    << "|\n";
    cout << "|" << setw(2) << "Pető"<< "\t|" << setw(8) << "Roland"  << "\t|" << setw(16) << "06705423442" << "\t|" << setw(25) << "petoroli96@gmail.com"   << "|\n";
    cout << "|" << setw(2) << "Tyur" << "\t|" << setw(8) << "Alex" << "\t|" << setw(16) << "06703918210" << "\t|" << setw(25) << "tyuro@gmail.com" << "|\n";
    cout << "|" << setw(2) << "Marrex"<< "\t|" << setw(8) << "Márton"<< "\t|" << setw(16) << "06703620861" << "\t|" << setw(25) << "marrex11@gmail.com"   << "|\n";
    cout << "|" << setw(2) << "Tálas" << "\t|" << setw(8) << "András"<< "\t|" << setw(16) << "06300918187" << "\t|" << setw(25) << "bunduwave@gmail.com"<< "|\n";
    




	return 0;
}