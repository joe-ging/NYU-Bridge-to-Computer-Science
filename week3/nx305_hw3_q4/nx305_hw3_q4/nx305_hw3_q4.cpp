#include <iostream>
#include <string>
using namespace std;

int main() {
    
    float input;
    int method;

    const int FLOOR_ROUND = 1;
    const int CEILING_ROUND = 2;
    const int ROUND = 3;
    
    cout<<"Please enter a Real number: \n";
    cin>>input;
    cout<<"Choose your rounding method: \n1.Floor round\n2.Ceiling round\n3.Round to thte nearest whole number\n";
    cin>>method;
    
    switch(method){
        case FLOOR_ROUND:
            cout<<int(input)<<endl;
            break;
        case CEILING_ROUND:
            cout<<int(input+1)<<endl;
            break;
        case ROUND:
            if(input-int(input)<0.5)
                cout<<int(input)<<endl;
            else
                cout<<int(input+1)<<endl;
            break;

    }

    return 0;
}
