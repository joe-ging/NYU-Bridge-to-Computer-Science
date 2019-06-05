/* Question 7 */

#include <iostream>
using namespace std;

int main()
{
    int dollars, cents, total;
    int quarters, dimes, nickels, pennies;
    
    cout<<"Please enter your amount in the format of dollars and cents separated by a space:\n";
    cin>>dollars>>cents;
    
    total = dollars*100 + cents;
    
    quarters = total/25;
    dimes = total%25/10;
    nickels = total%25%10/5;
    pennies = total%25%10%5;
    
    cout<<dollars<<" dollars and "<<cents<<" cents are:\n"<<quarters<<" quarters, "<<dimes<<" dimes, "<<nickels<<" nickels and"<<pennies<<" pennies.";
    
    return 0;
}
