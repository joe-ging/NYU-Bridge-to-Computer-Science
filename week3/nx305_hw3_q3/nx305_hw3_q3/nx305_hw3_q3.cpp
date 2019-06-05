#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {

    double a, b, c, deter, solution1, solution2;
    string result;
    
    cout<<"Please enter value of a: ";
    cin>>a;
    cout<<"Please enter value of b: ";
    cin>>b;
    cout<<"Please enter value of c: ";
    cin>>c;
    
    deter = sqrt(pow(b,2) - 4*a*c);
    
    if (a == 0 && b == 0 && c == 0)
        cout<<"This equation has an infinite number of solutions\n";
    else if (a == 0 && b == 0 && c != 0)
        cout<<"This equation has no solution\n";
    else if (deter < 0)
        cout<<"This equation has no real solution\n";
    else if (deter == 0) {
        solution1 = -b/2*a;
        cout<<"This equation has a single real solution x="<<std::fixed<<setprecision(1)<<solution1<<endl;
    }
    else {
        solution1 = (-b+deter)/2*a;
        solution2 = (-b-deter)/2*a;
        cout<<"This equation has two real solutions: x="<<std::fixed<<setprecision(1)<<solution1;
        cout<<"and x="<<std::fixed<<setprecision(1)<<solution2<<endl;
}
    
    return 0;
}
