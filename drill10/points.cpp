#include "std_lib_facilities.h"


struct Point{

	double x;
	double y;
};



int main()
try {
	

	vector<Point> points;
	double x;
	double y;
	int db = 0;

	

	while (db != 7){
		cout << "Please enter an x value." << endl;
		cin >> x;
		cout << "Please enter an y value." << endl;
		cin >> y;
		points.push_back(Point{x,y});
		db ++;
	}


	cout << "Please enter output file name: \n";
	string oname;
	cin >> oname;

	ofstream ost {oname};

	if (!ost) error ("can't open output file ", oname);

	for (const auto& t : points)
		ost << t.x << ' ' << t.y << endl;

	cout << "Please enter input file name: ";
	string iname;
	cin >> iname;

	ifstream ist {iname};

	if (!ist) error ("can't open input file ", iname);

	vector<Point> processed;
	double k;
	double g;
	while (ist >> k >> g){
		processed.push_back(Point{k,g});
	}

	for(const auto& l : processed)
		cout << l.x << " " << l.y << endl;




	return 0;

} catch (runtime_error& e) {
	cout << "Error: " << e.what() << endl;
	return 1;
} catch (...) {
	cout << "Some error happened\n";
	return 2;
}
