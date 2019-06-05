#include <iostream>
using namespace std;

int main()
{
    int Jdays, Jhours, Jminutes, Bdays, Bhours, Bminutes;
    int days, hours, minutes, total;
    
    cout<<"Please enter the number of days John has worked: ";
    cin>>Jdays;
    cout<<"Please enter the number of hours John has worked: ";
    cin>>Jhours;
    cout<<"Please enter the number of minutes John has worked: ";
    cin>>Jminutes;
    cout<<endl;
    cout<<"Please enter the number of days Bill has worked: ";
    cin>>Bdays;
    cout<<"Please enter the number of hours Bill has worked: ";
    cin>>Bhours;
    cout<<"Please enter the number of minutes Bill has worked: ";
    cin>>Bminutes;
    
    total = Jminutes + Bminutes + (Jhours + Bhours)*60 + (Jdays+Bdays)*24*60;
    days = total/24/60;
    hours = total%(24*60)/60;
    minutes = total%(24*60)%60;
    
    cout<<endl;
    cout<<"The total time both of them worked together is: "<<days<<" days, "<<hours<<" hours and "<<minutes<<" minutes.";
    
    return 0;}
