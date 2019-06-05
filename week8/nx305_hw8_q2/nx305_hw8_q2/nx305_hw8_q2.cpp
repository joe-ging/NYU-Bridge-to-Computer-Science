#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string str);

int main() {
    string input;
    
    cout << "Please enter a word: ";
    cin>>input;
    if (isPalindrome(input) == true)
        cout<<input<<" is a palindrome\n";
    else cout<<input<<" is not a palindrome\n";
    
    return 0;
}

bool isPalindrome(string str){
    bool palindrome;
    string reverse;
    
    reverse = "";
    for (int i=(str.length()-1); i >= 0; i--) {
        reverse += str[i];
    }
    if (reverse == str)
        palindrome = true;
    else palindrome = false;
    
    return palindrome;
}
