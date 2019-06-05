#include <iostream>
using namespace std;

int main() {
	const int FLOOR_ROUND = 1;
	const int CEILING_ROUND = 2;
	const int ROUND = 3;
	int method, round;
	float number;

	cout<<"Please enter a Real number:"<<endl; 
	cin>>number;
	cout<<"Choose your rounding method:\n1. Floor round\n2. Ceiling round\n3. Round to the nearest whole number"<<endl;
	cin>>method;

	switch(method){
		case FLOOR_ROUND:
			round = (int)number;
			cout<<round<<endl;
			break;
		case CEILING_ROUND:
			round = 1 + (int)number;
			cout<<round<<endl;
			break;
		case ROUND:{
			if((number - (int)number) > .5)
				round = 1 + (int)number;
			else
				round = (int)number;
			cout<<round<<endl;
			break;}
		default:
			cout<<"Invalid method"<<endl;

	}

	return 0;
}