#include <iostream>
#include <string>
using namespace std;

int main() {
 
    string name, status;
    int gradYear, currentYear, diffYear;
    
    cout<<"Please enter your name: ";
    cin>>name;
    cout<<"Please enter your grduation year: ";
    cin>>gradYear;
    cout<<"Please enter current year: ";
    cin>>currentYear;
    diffYear = gradYear-currentYear;
    
    if (diffYear > 4)
        status = "not in college yet";
    else if (diffYear == 4)
        status = "a freshman";
    else if (diffYear == 3)
        status = "a sophomore";
    else if (diffYear == 2)
        status = "a junior";
    else if (diffYear == 1)
        status = "a senior";
    else
        status = "graduated";
    
    cout<<name<<", you are "<<status<<endl;
    
    return 0;
}
