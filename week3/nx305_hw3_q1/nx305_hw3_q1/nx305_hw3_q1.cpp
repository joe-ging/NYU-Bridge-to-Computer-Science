#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    
    float FirstPrice, SecondPrice, tax, base, after, total;
    char card;
    
    cout<<"Enter price of first item: ";
    cin>>FirstPrice;
    cout<<"Enter price of second item: ";
    cin>>SecondPrice;
    cout<<"Does customer have a club card? (Y/N): ";
    cin>>card;
    cout<<"Enter tax rate, e.g. 5.5 for 5.5% tax: ";
    cin>>tax;
    
    base = FirstPrice+SecondPrice;
    
    if(FirstPrice>=SecondPrice)
        after = FirstPrice + .5*SecondPrice;
    else
        after = .5*FirstPrice + SecondPrice;
    
    if(card == 'Y'||card == 'y')
        after *= .9;
    
    total = after*(1+tax/100);

    cout<<"Base price: "<<std::fixed<<setprecision(1)<<base<<endl<<"Price after discounts: "<<after<<endl<<"Total price:"<<std::fixed<<setprecision(5)<<total<<endl;

    return 0;
}
