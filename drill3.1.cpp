 #include "std_lib_facilities.h"
 
 int main() {
 	double a = 0, b= 0;
 	string choice;
 	while (cout <<  "Please enter 'S' to enter 2 values or '|' to quit.\n"){
 	
 	cin >> choice;
 		if (choice=="|") {
 			break;
 			}
 		if (choice=="S") {
 			cout << "Please enter 2 values.\n";
 			cin >> a >> b;
 				if( a < b){
 					cout << "The smaller value is:" << a << ", the larger value is:"<< b <<"\n";
 					if ( b-a <= 0.01)
 						cout << "The numbers are almost equal.\n";
 			}
 				else if( a == b ){
 					cout << "The numbers are equal.\n";
 				}
 				else {
 					cout << "The smaller value is:" << b << ", the larger value is:"<< a <<"\n";
 					if ( a-b <= 0.01)
 						cout << "The numbers are almost equal.\n";
 					}
 				}
 			}
 	return 0;
 }
