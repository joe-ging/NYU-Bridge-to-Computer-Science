#include <iostream>
#include <cmath>
using namespace std;

int main() {
	float a, b, c, res1, res2;

	cout<<"Please enter value of a:"<<endl; 
	cin>>a;
	cout<<"Please enter value of b:"<<endl;
	cin>>b;
	cout<<"Please enter value of c:"<<endl;
	cin>>c;

	res1 = (sqrt(pow(b,2) - 4*a*c) - b)/(2*a);
	res2 = (-sqrt(pow(b,2) - 4*a*c) - b)/(2*a);
	
	if(a == 0 && b == 0)
		cout<<"No solution"<<endl;
	else if(a == 0 && b == 0 && c == 0)
		cout<<"Infinite number of solutions"<<endl;
	else if(pow(b,2) - 4*a*c < 0)
		cout<<"No real solution"<<endl;
	else if(pow(b,2) - 4*a*c == 0)
		cout<<"This equation has a single real solution x= "<<res1<<endl;
	else
		cout<<"This equation has two real solutions x= "<<res1<<" and x= "<<res2<<endl;


	return 0;
}