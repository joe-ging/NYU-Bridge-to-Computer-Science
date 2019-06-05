#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	int weight, height;
	float bmi;
	string status;

	cout<<"Please enter weight (in pounds):"<<endl;
	cin>>weight;
	cout<<"Please enter height (in inches):"<<endl;
	cin>>height;

	bmi = weight*0.453592/pow(height*.0254,2);

	if(bmi<18.5)
		status = "Underweight";
	else if(bmi >= 18.5 && bmi < 25)
		status = "Normal";
	else if(bmi >= 25 && bmi < 30)
		status = "Overweight";
	else
		status = "Obese";

	cout<<"The weight status is: "<<status<<endl;

	return 0;
}
