#include "std_lib_facilities.h"



class Date{

	int year, month,day;

public:

	class Invalid {};
	Date(int y, int m, int d): year(y), month(m), day(d) {if (!is_valid()) throw Invalid {}; }
	bool is_valid();
	void add_day(int n);
	int get_year(){return year;}
	int get_month(){return month;}
	int get_day(){return day;}

};


bool Date::is_valid()
{
	if(month < 1 or month > 12 or year < 0 or day < 1 or day > 31) return false;
	return true;
}





void Date::add_day(int n){


	day += n;


	if(day > 31){

		month += 1;
		day -= 31;


		if(month > 12){

			year += 1;
			month -= 12;
		}
	}

}


int main(){

try{

	Date today { 2021, 11, 17};



	cout << "Date : " << today.get_year() << '.' << today.get_month() << '.' << today.get_day() << endl;


	today.add_day(1);


	cout << "Date : " << today.get_year() << '.' << today.get_month() << '.' << today.get_day() << endl;




	


	return 0; 

}catch(Date::Invalid){
	cout << "Error: Invlaid date" << endl;
	return	1;
}catch(exception& e){
	cout << "Error: " << e.what() << endl;
	return 2;
}
}
