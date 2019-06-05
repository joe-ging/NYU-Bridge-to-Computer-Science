#include <iostream>
using namespace std;

int main() {

    int input, counter;
    
    cout<<"Please enter a positive integer: ";
    cin>>input;

    cout<<"section a\n";
    counter=1;
    while(counter <= input){
        cout<<2*counter<<endl;
        counter++;
    }
    
    cout<<"section b\n";
    
    for(counter=1; counter<=input; counter++)
        cout<<2*counter<<endl;
    
    return 0;
}
