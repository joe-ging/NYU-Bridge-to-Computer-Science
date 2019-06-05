#include <iostream>
using namespace std;

int main() {
    
    int dollars, cents, totalCents;
    int quarters, dimes, nickels, pennies;

    cout<<"Please enter your amount in the format of dollars and cents separated by a space: "<<endl;
    cin>>dollars>>cents;
    
    totalCents = dollars*100+cents;
    quarters = totalCents/25;
    dimes = totalCents%25/10;
    nickels = totalCents%25%10/5;
    pennies = totalCents%25%10%5;
    
    cout<<dollars<<" and "<<cents<<" cents are: "<<quarters<<" quarters, "<<dimes<<" dimes, ";
    cout<<nickels<<" nickels and "<<pennies<<" pennies."<<endl;
    
    return 0;
}
