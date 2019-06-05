#include <iostream>
using namespace std;

int main() {
	int int1, int2;

	cout<<"Please enter two positive integers, separated by a space:"<<endl;
	cin>>int1>>int2;

	cout<<int1<<" + "<<int2<<" = "<<int1+int2<<endl;
	cout<<int1<<" - "<<int2<<" = "<<int1-int2<<endl;
	cout<<int1<<" * "<<int2<<" = "<<int1*int2<<endl;
	cout<<int1<<" / "<<int2<<" = "<<(float)int1/(float)int2<<endl;
	cout<<int1<<" div "<<int2<<" = "<<int1/int2<<endl;
	cout<<int1<<" mod "<<int2<<" = "<<int1%int2<<endl;

	return 0;
}