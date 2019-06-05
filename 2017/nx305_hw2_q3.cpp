#include <iostream>
#include <string>
using namespace std;

int main() {
	string name;
	int graduation, current;

	cout<<"Please enter your name:"<<endl; 
	cin>>name;
	cout<<"Please enter your graduation year:"<<endl;
	cin>>graduation;
	cout<<"Please enter current year:"<<endl;
	cin>>current;
	
	if(graduation > current+4)
		cout<<name<<", you are not in college yet"<<endl;
	else if(graduation == current+4)
		cout<<name<<", you are a freshman"<<endl;
	else if(graduation == current+3)
		cout<<name<<", you are a sophomore"<<endl;
	else if(graduation == current+2)
		cout<<name<<", you are a junior"<<endl;
	else if(graduation == current+1)
		cout<<name<<", you are a senior"<<endl;
	else
		cout<<name<<", you graduated"<<endl;

	return 0;
}