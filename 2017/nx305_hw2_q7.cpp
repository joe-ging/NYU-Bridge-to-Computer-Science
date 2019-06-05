#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){
	string day;
	char colon;
	int hour, minute, length;
	float rate;

	cout<<"Enter day of the week, time the call started, and length of the call in minutes:"<<endl;
	cin>>day>>hour>>colon>>minute>>length;

	if(day == "Sa" || day == "Su")
		rate = .15; 
	else {
		if(hour < 8 || hour > 18)
			rate = .25;
		else
			rate = .4;

	cout<<"The cost of the call is $"<<rate*length<<endl;
}
	return 0;
}