#include <iostream>
#include <cmath>
using namespace std;

void analyzeDividors(int num, int& outCountDivs, int& outSumDivs);
bool isPerfect(int num);
void amicable(int num);

int main() {
    int num, divCount, divSum, perf, amicableNum;
    
    cout << "Part A:\nEnter a positive integer greater than 1: ";
    cin >> num;
    divCount = 0;
    divSum = 0;
    analyzeDividors(num, divCount, divSum);
    cout<<"Number of proper divisors is "<<divCount<<" and their sum is "<<divSum<<endl;

    cout<<"Part B:\nEnter a positive integer greater than 1 to find out whether it's perfect: ";
    cin >> perf;
    if (isPerfect(perf) == true)
        cout<<"The number is perfect."<<endl;
    else
        cout<<"The number is not perfect."<<endl;

    cout<<"Part C:\nEnter a positive integer greater than 2 to print out its perfect numbers and amicable pairs: ";
    cin>>amicableNum;
    amicable(amicableNum);
    
    return 0;
}

void analyzeDividors(int num, int& outCountDivs, int& outSumDivs) {
    int i, subtractCount, subtractSum;
    
    outCountDivs = 0;
    outSumDivs = 0;
    subtractCount = 0;
    subtractSum = 0;
    for (i=1; i<=sqrt(num); i++){
        if (num%i == 0){
            outCountDivs++;
            outSumDivs+= i+num/i;
            if (i == num/i) {
                subtractCount = 1;
                subtractSum = i;
            }
        }
    }
    outCountDivs = outCountDivs*2 - 1 - subtractCount;
    outSumDivs -= num+subtractSum;
}

bool isPerfect(int num) {
    int count, sum;
    bool perfect;
    
    perfect = false;
    analyzeDividors(num, count, sum);
    if (num == sum)
        perfect = true;
    
    return perfect;
}

void amicable(int num){
    int i, count, sum, comp, sumComp;
    
    count = 0;
    sum = 0;
    cout<<"Perfect numbers from 2 to "<<num<<" are: ";
    for (i=2; i<= num; i++){
        if (isPerfect(i) == true)
            cout<<i<<" ";}
    
    cout<<"\nAmicable pairs from 2 to "<<num<<" are:\n";
    for (i=2; i<= num; i++){
        analyzeDividors(i, count, sum);
            for (comp=2; comp<= num; comp++){
                analyzeDividors(comp, count, sumComp);
                if ((comp == sum) && (i == sumComp) && (i < comp))
                    cout<<i<<" "<<sum<<endl;
        }
    }

    cout<<endl;
}
