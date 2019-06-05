#include <iostream>
using namespace std;

int main() {

    int input, lineNum, output;
    
    cout << "Please enter a positive integer:\n";
    cin>>input;
    
    for (lineNum = 1; lineNum<=input; lineNum++){
        for (output = lineNum; output<=lineNum*input; output+=lineNum)
            cout<<output<<"\t";
        cout<<endl;
    }
    return 0;
}
