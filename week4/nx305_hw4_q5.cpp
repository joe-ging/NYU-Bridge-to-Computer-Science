#include <iostream>
using namespace std;

int main() {
    
    int n, lineNum, starCount, spaceCount, spaceCount2;
    
    cout<<"Enter a positive integer:\n";
    cin>>n;
    
    for (lineNum=1; lineNum<=n; lineNum++){
        for (spaceCount=1; spaceCount<=lineNum-1; spaceCount++)
            cout<<" ";
        for (starCount=1; starCount <=2*(n-lineNum)+1; starCount++)
            cout<<"*";
        for (spaceCount2=1; spaceCount2<=lineNum; spaceCount2++)
            cout<<" ";
        cout<<endl;
    }
    for (lineNum=1; lineNum<=n; lineNum++){
        for (spaceCount=1; spaceCount<=n-lineNum; spaceCount++)
            cout<<" ";
        for (starCount=1; starCount <=2*lineNum-1; starCount++)
            cout<<"*";
        for (spaceCount2=1; spaceCount2<=n-lineNum; spaceCount2++)
            cout<<" ";
        cout<<endl;
    }
    return 0;
}
