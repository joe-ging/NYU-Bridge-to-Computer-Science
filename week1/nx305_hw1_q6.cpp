/* Question 6 */

#include <iostream>
using namespace std;

int main()
{
    int quarters, dimes, nickels, pennies;
    int dollars, cents;
    cout<<"Please enter number of coins:\n# of quarters: ";
    cin>>quarters;
    cout<<"# of dimes: ";
    cin>>dimes;
    cout<<"# of nickles: ";
    cin>>nickels;
    cout<<"# of pennies: ";
    cin>>pennies;
    
    cents = (quarters%4*25 + dimes%10*10 + nickels%20*5 + pennies%100)%100;
    dollars = quarters/4 + dimes/10 + nickels/20 + pennies/100 + (quarters%4*25 + dimes%10*10 + nickels%20*5 + pennies%100)/100;
    
    cout<<"The total is "<<dollars<<" dollars and "<<cents<<" cents."<<endl;
    return 0;
}
