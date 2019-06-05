#include <iostream>
using namespace std;

int main() {
    
    int daysJohn, hoursJohn, minutesJohn, daysBill, hoursBill, minutesBill;
    int totalDays, totalHours, totalMinutes;
    int sumMinutes;

    cout<<"Please enter the number of days John has worked: \n";
    cin>>daysJohn;
    cout<<"Please enter the number of hours John has worked: \n";
    cin>>hoursJohn;
    cout<<"Please enter the number of minutess John has worked: \n";
    cin>>minutesJohn;
    cout<<endl;
    
    cout<<"Please enter the number of days Bill has worked: \n";
    cin>>daysBill;
    cout<<"Please enter the number of hours Bill has worked: \n";
    cin>>hoursBill;
    cout<<"Please enter the number of minutes Bill has worked: \n";
    cin>>minutesBill;
    
    sumMinutes = (daysJohn + daysBill)*24*60 + (hoursJohn + hoursBill)*60 + minutesBill + minutesJohn;
    totalDays = sumMinutes/(24*60);
    totalHours = sumMinutes%(24*60)/60;
    totalMinutes = sumMinutes%(24*60)%60;
    
    cout<<endl;
    cout<<"The total time both of them worked together is: "<<totalDays<<" days, ";
    cout<<totalHours<<" hours and "<<totalMinutes<<" minutes.";
    
    return 0;
}
