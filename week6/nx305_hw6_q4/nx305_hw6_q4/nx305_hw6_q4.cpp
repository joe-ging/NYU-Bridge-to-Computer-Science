#include <iostream>
#include <cmath>
#include <string>
using namespace std;

void printDivisors(int num);

int main() {
    int num;
    
    cout<<"Please enter a positive integer >= 2: ";
    cin>>num;
    printDivisors(num);
    
    return 0;
}

void printDivisors(int num){
    int counter;
    string output, output1, output2;
    
    for (counter = 1; counter <= sqrt(num); counter++){
        if (num%counter == 0){
            output1 += to_string(counter);
            output1 += " ";
            if (counter != num/counter){
            output2.insert(0, (to_string(num/counter)+" "));
            }
        }
        output = output1+output2;
    }
    cout<<output<<endl;
}
