 #include "std_lib_facilities.h"
 
 int main() {
 	double a = 0;
 	double smallest = 0;
 	double largest = 0;
 	string choice;
 	string unit;
 	constexpr double i = 2.54;
 	constexpr double m = 100;
 	constexpr double ft = 12*2.54;
 	constexpr double cm = 1;
 	vector<double> values;
 	double value = 0;
 	double sum = 0;
 	cout << "Please enter 'S' to enter a value or '|' to quit.\n";
 	cin >> choice;
 		if(choice=="|"){
 			cout << smallest <<" m is the smallest value.\n";
 			cout << largest <<" m is the largest value.\n";
 			cout << "The sum of values is:" << sum <<" m\n";
 			cout << "The number of values entered is:" << values.size() << "\n";
     				sort(values);
     				cout << "The entered values are:\n";
     				for(auto value : values)
          				cout << value << " m\n";
 			return 0;
 			}
 		if(choice=="S"){
 			cout << "Please enter a value.\n";
 			cin >> a >> unit;
 				if (unit == "i"){
 					largest = (a*i/100);
 					smallest = (a*i/100);
 					values.push_back(a*i/100);
 					sum += a*i/100;
 					}
 				else if (unit == "m"){
 					largest = (a*m/100);
 					smallest = (a*m/100);
 					values.push_back(a*m/100);
 					sum += a*m/100;
 					}
 				else if (unit == "ft"){
 					largest = (a*ft/100);
 					smallest = (a*ft/100);
 					values.push_back(a*ft/100);
 					sum += a*ft/100;
 					}
 				else if (unit == "cm"){
 					largest = (a*cm/100);
 					smallest = (a*cm/100);
 					values.push_back(a*cm/100);
 					sum += a*cm/100;
 					}
 				else {
 					simple_error("Wrong unit!");
 				}
 				}
 		cout << smallest <<"m is the smallest so far\n";
		cout << largest <<"m is the largest so far\n";	
 		while(cout << "Please enter 'S' to add another value or enter '|' to quit:\n") {
 		cin >> choice;
 		if(choice=="|"){
 			cout << smallest <<" m is the smallest value.\n";
 			cout << largest <<" m is the largest value.\n";
 			cout << "The sum of values is:" << sum <<" m\n";
 			cout << "The number of values entered is:" << values.size() << "\n";
     				sort(values);
     				cout << "The entered values are:\n";
     				for(auto value : values)
          				cout << value << " m\n";
 			return 0;
 			}
 		if(choice=="S"){
 		cout << "Please enter another value:\n";
 			cin >> a >> unit;
 				if (unit == "i"){
 					a=(a*i/100);
					if (a<smallest) {
						smallest = a;
						values.push_back(a);
						sum += a;
						}
					else if (a>largest){
						largest = a;
						values.push_back(a);
						sum += a;
						}
					}
				else if (unit == "m"){
					a=(a*m/100);
					if (a<smallest) {
						smallest = a;
						values.push_back(a);
						sum += a;
						}
					else if (a>largest){
						largest = a;
						values.push_back(a);
						sum += a;
						}
					}
				else if (unit == "ft"){
					a=(a*ft/100);
					if (a<smallest) {
						smallest = a;
						values.push_back(a);
						sum += a;
						}
					else if (a>largest){
						largest = a;
						values.push_back(a);
						sum += a;
						}
					}
				else if (unit == "cm"){
					a=(a*cm/100);
					if (a<smallest) {
						smallest = a;
						values.push_back(a);
						sum += a;
						}
					else if (a>largest){
						largest = a;
						values.push_back(a);
						sum += a;
						}
					}
				else {
					simple_error("Wrong unit!");
				}
				}
			cout << smallest <<"m is the smallest so far\n";
			cout << largest <<"m is the largest so far\n";
 			}	
 	return 0;
 }
