#include <iostream>
#include <string>
using namespace std;

int main() {
    
    int input,original;
    string binaryDigit, output;

    cout<<"Enter decimal number: \n";
    cin>>input;
    original = input;
    
    while(input>0) {
        if (input%2 == 0)
            binaryDigit="0";
        else
            binaryDigit="1";
        output.insert(0,binaryDigit);
        input=input/2;
    }
    
    cout<<"The binary representation of "<<original<<" is "<<output<<endl;
    
    return 0;
}
