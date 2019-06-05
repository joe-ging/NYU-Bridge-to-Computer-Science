#include <iostream>
#include <string>
using namespace std;

int main() {
    
    string day;
    int length, hour, minute;
    char colon;
    
    cout<<"Enter the day of the week your call started: ";
    cin>>day;
    cout<<"Enter the time of the day the call started: ";
    cin>>hour>>colon>>minute;
    cout<<"Enter the length of the call in minutes: ";
    cin>>length;
    
    if ((day == "Sa") || (day == "Su"))
        cout<<"The cost of the call is "<<length*0.15<<endl;
    else if ((hour < 8) || (hour > 18))
        cout<<"The cost of the call is "<<length*0.25<<endl;
    else
        cout<<"The cost of the call is "<<length*0.4<<endl;
    
    return 0;
}
