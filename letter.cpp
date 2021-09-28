 #include "std_lib_facilities.h"
 
 int main() {
 
 	cout << "Enter  the  name  of the  person  you  want to  write  to:\n";
 	string first_name;
 	cin >> first_name;
 	cout << "Enter the name of the other friend:\n";
 	string friend_name;
 	cin >> friend_name;
 	cout << "Enter the gender of the other friend(m if male, f if female):\n";
 	char friend_sex = 0;
 	cin >> friend_sex;
 	cout << "Enter the age of the person you are writing to:\n";
 	int age;
 	cin >> age;
 		if(age<0 or age>110)
 			simple_error("you're kidding!");
 	cout << "Please enter your name:\n";
 	string your_name;
 	cin >> your_name;
 	
 	cout << endl;
 	cout << "Dear " << first_name << "," << "\n";
 	 
 	cout << "\t" << "How  are  you?  I  am  fine.  I  miss you.It's like we haven't seen each other in ages. I can't wait to see you next week. I have just bought a new car so we should check out the new drive in in my hometown if you would like to."<< endl;
 	cout << "\t" << "Have you seen "<<friend_name<<" lately?";
 	if(friend_sex == 'm')
 		cout <<" If you see "<<friend_name<<" please ask him to call me.I have something really important to tell him. It's about his girlfriend."<<'\n';
 	if(friend_sex == 'f')
 		cout <<" If you see "<<friend_name<<" please ask her to call me.I have something really important to tell her. It's about her boyfriend."<< endl;
 	cout << "\t" <<"I hear you just had a birthday and you are "<<age<<" years old.";
 	if (age<12)
 		cout << "Next year you will be "<< age+1 <<"."<< endl;
 	else if (age==17)
 		cout << "Next year you will be able to vote."<< endl;
 	else if (age>70)
 		cout << "I hope you are enjoying retirement."<< endl;
 	else{
 		cout << endl;
 	}
 	cout << "Yours sincerely,"<< endl;
 	cout << endl;
 	cout << endl;
 	
 	cout << ""<<your_name<<"" << endl;	
 	return 0;
 }
