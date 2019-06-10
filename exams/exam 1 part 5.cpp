#include <iostream>
using namespace std;

int main() {

    int n, lineNum, starCount, poundCount;
    
    cout<<"Please enter a positive integer: \n"<<endl;
    cin>>n;
    cout<<endl;
    
    for(lineNum=1; lineNum<=n; lineNum++)
        if (lineNum%2 != 0){
            for(starCount=1; starCount<=n; starCount++){
                cout<<"*";
                }
            cout<<endl;
        }
        else {
            for(poundCount=1; poundCount<=n; poundCount++){
                cout<<"#";
            }
            cout<<endl;
        }
    return 0;
}