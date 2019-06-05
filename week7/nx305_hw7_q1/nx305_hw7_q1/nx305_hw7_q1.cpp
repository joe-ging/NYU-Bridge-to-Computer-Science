#include <iostream>
#include <string>
using namespace std;

int printMonthCalendar(int numOfDays, int startingDay);
bool leapYear(int year);
void printYearCalendar(int year, int startingDay);

int main() {
    int numOfDays, startingDay, lastDay, startingDayYear;
    bool leap;
    int year, calYear;
    
    cout<<"Part A:\nEnter number of days and starting day of the month: ";
    cin>>numOfDays>>startingDay;
    lastDay = printMonthCalendar(numOfDays, startingDay);
    cout<<endl<<"Last day of the month is: "<<lastDay<<"\n"<<endl;
    
    cout<<"Part B:\nEnter a year to determine whether it's a leap year: ";
    cin>>year;
    leap = leapYear(year);
    if (leap == true)
        cout<<year<<" is a leap year.\n"<<endl;
    else
        cout<<year<<" is not a leap year.\n"<<endl;
    
    cout<<"Part C:\nEnter the year and starting day of the year: ";
    cin>>calYear>>startingDayYear;
    printYearCalendar(calYear, startingDayYear);
    
    return 0;
}

int printMonthCalendar(int numOfDays, int startingDay) {
    int numSpaces, i, lastDay, firstLine, nextLine;

    cout<<"Mon\tTue\tWed\tThu\tFri\tSat\tSun\n";
    for (numSpaces = 1; numSpaces <= startingDay-1; numSpaces++)
        cout<<" \t";
    
    for (firstLine = 1; firstLine <= 8-startingDay; firstLine++)
        cout<<firstLine<<"\t";
    cout<<endl;
    
    nextLine = firstLine;
    while (nextLine<=numOfDays){
        for (i = nextLine; (i <= nextLine+6)&&(i<=numOfDays); i++)
            cout<<i<<"\t";
        cout<<endl;
        nextLine+=7;
    }
    
    lastDay = startingDay+numOfDays%7-1;
    if (lastDay > 7)
        lastDay -= 7;
    if (lastDay == 0)
        lastDay = 7;
    return lastDay;
}

bool leapYear(int year){
    bool leap;
    leap = false;
    
    if ((year % 4 == 0) && ((year % 100 != 0)||(year % 400 == 0)))
        leap = true;
    else leap = false;
    
    cout<<endl;
    
    return leap;
}

void printYearCalendar(int year, int startingDay) {
    int lastDay;
    
    cout<<"January "<<year<<endl;
    lastDay = printMonthCalendar(31, startingDay);
    if (lastDay == 7)
        lastDay = 0; // To avoid setting the first of the next month to 8.
    cout<<endl;
    
    cout<<"Febuary "<<year<<endl;
    if (leapYear(year) == true)
        lastDay = printMonthCalendar(29, lastDay+1);
    else
        lastDay = printMonthCalendar(28, lastDay+1);
    if (lastDay == 7)
        lastDay = 0;
    cout<<endl;
    
    cout<<"March "<<year<<endl;
    lastDay = printMonthCalendar(31, lastDay+1);
    if (lastDay == 7)
        lastDay = 0;
    cout<<endl;
    
    cout<<"April "<<year<<endl;
    lastDay = printMonthCalendar(30, lastDay+1);
    if (lastDay == 7)
        lastDay = 0;
    cout<<endl;

    cout<<"May "<<year<<endl;
    lastDay = printMonthCalendar(31, lastDay+1);
    if (lastDay == 7)
        lastDay = 0;
    cout<<endl;
    
    cout<<"June "<<year<<endl;
    lastDay = printMonthCalendar(30, lastDay+1);
    if (lastDay == 7)
        lastDay = 0;
    cout<<endl;
    
    cout<<"July "<<year<<endl;
    lastDay = printMonthCalendar(31, lastDay+1);
    if (lastDay == 7)
        lastDay = 0;
    cout<<endl;
    
    cout<<"August "<<year<<endl;
    lastDay = printMonthCalendar(31, lastDay+1);
    if (lastDay == 7)
        lastDay = 0;
    cout<<endl;
    
    cout<<"September "<<year<<endl;
    lastDay = printMonthCalendar(30, lastDay+1);
    if (lastDay == 7)
        lastDay = 0;
    cout<<endl;
    
    cout<<"October "<<year<<endl;
    lastDay = printMonthCalendar(31, lastDay+1);
    if (lastDay == 7)
        lastDay = 0;
    cout<<endl;
    
    cout<<"November "<<year<<endl;
    lastDay = printMonthCalendar(30, lastDay+1);
    if (lastDay == 7)
        lastDay = 0;
    cout<<endl;
    
    cout<<"December "<<year<<endl;
    lastDay = printMonthCalendar(31, lastDay+1);
    if (lastDay == 7)
        lastDay = 0;
    cout<<endl;
    
}
