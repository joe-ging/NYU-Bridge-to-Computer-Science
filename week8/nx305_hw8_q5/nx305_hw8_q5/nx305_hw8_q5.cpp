#include <iostream>
#include <string>
using namespace std;

int main() {
    string output, input, first, middle, last;
    
    cout << "Enter your name: ";
    cin>>first>>middle>>last;

    cout<<last<<", "<<first<<" "<<middle[0]<<". ";
    cout<<endl;
    
    return 0;
}
