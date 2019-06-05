#include <iostream>
#include <fstream>
#include <stack>
using namespace std;

bool delimiterMatch(string input);

int main() {
    string input;

    cout << "Enter your input file path: ";
    cin>>input;
    if (delimiterMatch(input))
        cout<<"File is properly formatted.";
    else cout<<"File is not properly formatted.";
}

bool delimiterMatch(string input){
    char c;
    string begin;
    ifstream file;
    stack<char> myStack;
    
    file.open(input);
    while(!file){
        cout<<"Invalid file path. Please re-enter: ";
        cin>>input;
        file.clear();
        file.open(input);
    }
    
    file>>begin>>c; //consumes the word "begin" and space after it
    while(file>>c){
        if (c=='['||c=='{'||c=='(')
            myStack.push(c);
        else if (c==')'||c=='}'||c==']'){
            if (myStack.empty())
                return false;
            else if ((c==')'&&myStack.top()=='(')||(c==']'&&myStack.top()=='[')||(c=='}'&&myStack.top()=='{'))
                myStack.pop();
        }
    }
    file.close();
    if (myStack.empty())
        return true;
    else return false;
}
