#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    
    int input, product, count;
    double length;
    bool flag;
    
    cout<<"Version a: "<<endl;
    cout<<"Please enter the length of the sequence: ";
    cin>>length;
    cout<<"Please enter your sequence:\n";
    
    product = 1;
    for (count = 1; count<=length; count++){
        cin>>input;
        product*=input;
    }
    
    cout<<"The geometric mean is: "<<std::fixed<<setprecision(4)<<pow(product,double(1)/length)<<endl;
    
    cout<<"Version b:"<<endl;
    cout<<"Please enter a non-empty sequence of positive integers, each one in a";
    cout<<"separate line. End your sequence by typing -1:\n";
    
    product = 1;
    flag = true;
    while(flag == true){
        cin>>input;
        if (input != -1)
            product*=input;
        else
            flag = false;
    }
    
    cout<<"The geometric mean is: "<<std::fixed<<setprecision(4)<<pow(product,double(1)/length)<<endl;
    
    return 0;
}
