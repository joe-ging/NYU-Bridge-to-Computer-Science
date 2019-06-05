#include <iostream>
using namespace std;

int main() {
	int n, number, counter;

	cout<<"section a"<<endl;
	cout<<"Please enter a positive integer: ";
	cin>>n;

	number = 0;
	counter = 1;
	while(counter <= n) {
		number = 2*counter;
		cout<<number<<endl;
		counter++;
	}

	cout<<"section b"<<endl;
	cout<<"Please enter a positive integer: ";
	cin>>n;

	for(counter = 1; counter <= n; counter++) {
		number= 2 * counter;
		cout<<number<<endl;
	}

	return 0;
}