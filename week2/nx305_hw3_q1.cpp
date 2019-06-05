#include <iostream>
#include <string>
using namespace std;

int main(){
    int hour24, minutes;
    int hour12;
    string period;
    char temp;
    
    cout<<"Please enter a time in the 24-hour format: \n";
    cin>>hour24>>temp>>minutes;
    
    if(hour24>=0 && hour24 <= 11){
        period = "am";
        if(hour24 == 0)
            hour12 = 12;
        else
            hour12 = hour24;
    }
    else{
        period = "pm";
        if(hour24 == 12)
            hour12 = 12;
        else
            hour12 = hour24 - 12;
    }
    
    cout<<hour24<<":"<<minutes<<" is "<<hour12<<":"<<minutes<<period<<endl;

    return 0;
}
