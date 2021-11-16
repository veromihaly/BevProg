#include "std_lib_facilities.h"

void swap_v(int a,int b) //nem működik
{
int temp;
temp = a;
a = b;
b = temp;
}

void swap_r(int& a,int& b)
{
int temp;
temp = a;
a = b;
b = temp;
}

//void swap_cr(const int& a, const int& b)
//{
//int temp;
//temp = a;
//a = b;
//b = temp;
//}

int main()
{
	int x= 7;
	int y =9;
	const int cx = 7;
	const int cy = 9;
	double dx = 7.7;
	double dy = 9.9;
	
	
	//swap_v(x,y); 
	//cout << "the value of x= "<< x <<" \n";
	//cout << "the value of y= "<< y <<" \n";
	
	swap_r(x,y); 
	cout << "the value of x= "<< x <<" \n";
	cout << "the value of y= "<< y <<" \n";
	
	//swap_cr(x,y); 
	//cout << "the value of x= "<< x <<" \n";
	//cout << "the value of y= "<< y <<" \n";
	
	swap_v(7,9);
	cout << "the value of x= "<< x <<" \n";
	cout << "the value of y= "<< y <<" \n";
	
	//swap_r(7,9);
	//cout << "the value of x= "<< x <<" \n";
	//cout << "the value of y= "<< y <<" \n";
	
	//swap_cr(7,9);
	//cout << "the value of x= "<< x <<" \n";
	//cout << "the value of y= "<< y <<" \n";
	
	
	//swap_v(cx,cy);
	//cout << "the value of cx= "<< cx <<" \n";
	//cout << "the value of cy= "<< cy <<" \n";
	
	//swap_r(cx,cy);
	//cout << "the value of cx= "<< cx <<" \n";
	//cout << "the value of cy= "<< cy <<" \n";
	
	//swap_cr(cx,cy);
	//cout << "the value of cx= "<< cx <<" \n";
	//cout << "the value of cy= "<< cy <<" \n";
	
	
	//swap_v(7.7,9.9);
	//cout << "the value of x= "<< x <<" \n";
	//cout << "the value of y= "<< y <<" \n";
	
	//swap_r(7.7,9.9);
	//cout << "the value of x= "<< x <<" \n";
	//cout << "the value of y= "<< y <<" \n";
	
	//swap_cr(7.7,9.9);
	//cout << "the value of x= "<< x <<" \n";
	//cout << "the value of y= "<< y <<" \n";
	
	
	//swap_v(dx,dy);
	//cout << "the value of dx= "<< dx <<" \n";
	//cout << "the value of dy= "<< dy <<" \n";
	
	//swap_r(dx,dy);
	//cout << "the value of dx= "<< dx <<" \n";
	//cout << "the value of dy= "<< dy <<" \n";
	
	//swap_cr(dx,dy);
	//cout << "the value of dx= "<< dx <<" \n";
	//cout << "the value of dy= "<< dy <<" \n";

	return 0;
}
 
