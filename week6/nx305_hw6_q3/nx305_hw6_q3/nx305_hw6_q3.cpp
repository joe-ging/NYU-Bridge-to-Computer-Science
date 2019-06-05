#include <iostream>
using namespace std;

double eApprox(int n);

int main() {
    cout.precision(30);
    
    for (int n = 1; n<=15; n++)
        cout<<"n= "<<n<<'\t'<<eApprox(n)<<endl;
    
    return 0;
}

double eApprox(int n) {
    int counter;
    double addend, output, factorial;

    output = 1;
    
    for (counter = 1,factorial = 1; counter <= n; counter++, factorial*=counter){
        addend = 1/factorial;
        output += addend;
    }
    return output;
}
