#include <iostream>
using namespace std;

int main() {
	float price1, price2, tax, base, discount, total;
	char card;

	cout<<"Enter price of first item:"<<endl; 
	cin>>price1;
	cout<<"Enter price of second item:"<<endl;
	cin>>price2;
	cout<<"Does customer have a club card? (Y/N):"<<endl;
	cin>>card;
	cout<<"Enter tax rate, e.g. 5.5 for 5.5% tax:"<<endl;
	cin>>tax;

	base = price1 + price2;

	if(price1 >= price2)
		discount = price1 + .5*price2;
	else
		discount = .5*price1 + price2;

	if(card == 'y' || card == 'Y')
		discount *= .9;

	total = discount*(1+tax/100); 

	cout<<"Base price: "<<base<<endl;
	cout<<"Price after discounts: "<<discount<<endl;
	cout<<"Total price: "<<total<<endl;

	return 0;
}