#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    
    float weight, height, bmi;

    cout<<"Please enter weight (in pounds): ";
    cin>>weight;
    cout<<"Please enter height (in inches): ";
    cin>>height;
    
    bmi = weight*0.453592/pow(height*0.0254,2);
    
    if(bmi< 18.5)
        cout<<"The weight status is: Underweight\n";
    else if((bmi>=18.5) && (bmi<25))
        cout<<"The weight status is: Normal\n";
    else if((bmi>=25) && (bmi<30))
        cout<<"The weight status is: Overweight\n";
    else
        cout<<"The weight status is: Obese\n";
    
    return 0;
}
