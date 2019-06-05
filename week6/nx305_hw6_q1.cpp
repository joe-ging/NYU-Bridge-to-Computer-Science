#include <iostream>
using namespace std;
    
    int fib(int n);
    
    int main() {
        int num, output;
        
        cout << "Please enter a positive integer: ";
        cin >> num;
        
        if ((num == 1) || (num == 2))
            output = 1;
        else
            output = fib(num);
        
        cout << output << endl;
        return 0;
    }
    
    int fib(int n) {
        
        int output, output1, output2, count;
        
        output = 0;
        output1 = 1;
        output2 = 1;
        for (count = 3; count <= n; count++) {
            output = output1 + output2;
            output1 = output2;
            output2 = output;
        }
        return output;
    }
