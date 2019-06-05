#include <iostream>
using namespace std;

int main() {

    int input, currDigit, numEven, numOdd, counter, num;
    
    cout<<"Enter a positive integer: ";
    cin>>input;
    
    for (num = 1; num<=input; num++){
        counter = num;
        for(currDigit=counter%10, numEven=0, numOdd=0;
            counter>0;
            counter = counter/10, currDigit=counter%10){
            if (currDigit%2==0)
                numEven++;
            else
                numOdd++;
        }
        if (numEven>numOdd)
            cout<<num<<endl;
    }
    
    return 0;
}
