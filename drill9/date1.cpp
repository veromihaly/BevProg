#include "std_lib_facilities.h"



struct Date{

	int y, m,d;
};



void init_date(Date& dd, int y, int m, int d){


	if(y > 0)


		dd.y = y;


	else

		error("invalid year");


	if(m <= 12 and m > 0)


		dd.m = m;

	else

		error("invalid month");


	if(d <= 31 and d > 0)


		dd.d = d;


	else


		error("invalid day");

}

void add_day(Date& dd, int n){


	dd.d += n;


	if(dd.d > 31){

		dd.m += 1;
		dd.d -= 31;


		if(dd.m > 12){

			dd.y += 1;
			dd.m -= 12;
		}
	}

}


int main(){

try{

	Date today;

	today.y = 2002;
	today.m = 4;
	today.d = 5;


	cout << "Date : " << today.y << '.' << today.m << '.' << today.d << endl;


	Date x;

	init_date(x, 2021, 11, 17);


	cout << "Date : " << x.y << '.' << x.m << '.' << x.d << endl;



	add_day(x, 12);


	cout << "Date : " << x.y << '.' << x.m << '.' << x.d << endl;


	return 0; 

}catch(exception& e){
	cout << e.what() << endl;
	return	1;
}
}
