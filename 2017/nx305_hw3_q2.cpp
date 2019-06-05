#include <iostream>
using namespace std;

int main() {
	int I, V, X, L, C, D, M, n;

	cout<<"Enter decimal number: "<<endl;
	cin>>n;

	I = n%1000%500%100%50%10%5;
	V = n%1000%500%100%50%10/5;
	X = n%1000%500%100%50/10;
	L = n%1000%500%100/50;
	C = n%1000%500/100;
	D = n%1000/500;
	M = n/1000;

	for(count = 1; count <=M; count++) {
		
	}

	return 0;
}