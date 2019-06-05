#include <iostream>
using namespace std;

int main() {
    int int1, int2;
    float add, sub, multi, divide, div, mod;

    cout<<"Please enter two positive integers, separated by a space: "<<endl;
    cin>>int1>>int2;
    add = int1 + int2;
    sub = int1 - int2;
    multi = int1 * int2;
    divide = float(int1)/float(int2);
    div = int1/int2;
    mod = int1%int2;
    
    cout<<int1<<" + "<<int2<<" = "<<add<<endl;
    cout<<int1<<" - "<<int2<<" = "<<sub<<endl;
    cout<<int1<<" * "<<int2<<" = "<<multi<<endl;
    cout<<int1<<" / "<<int2<<" = "<<divide<<endl;
    cout<<int1<<" div "<<int2<<" = "<<div<<endl;
    cout<<int1<<" mod "<<int2<<" = "<<mod<<endl;
    
    return 0;
}
