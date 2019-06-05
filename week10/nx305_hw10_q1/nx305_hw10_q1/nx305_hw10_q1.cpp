#include <iostream>
#include <cctype>
#include <vector>
using namespace std;

class Money{
public:
    Money(long dollars, int cents);
    Money(long dollars);
    Money();
    double getValue() const;
    friend istream& operator >>(istream& ins, Money& amount);
private:
    long allCents;
};

Money:: Money(long dollars, int cents){
    if (dollars<0||cents<0){
        cout<<"Illegal value\n";
        exit(1);
    }
    allCents = dollars*100+cents;
}

Money:: Money(long dollars){
    if (dollars<0){
        cout<<"Illegal value\n";
        exit(1);
    }
    allCents = dollars*100;
}

Money:: Money(): allCents(0){}

double Money:: getValue() const{
    return (allCents*.01);
}

int digitToInt(char c);

istream& operator >>(istream& ins, Money& amount){
    char oneChar, decimalPoint, digit1, digit2;
    long dollars;
    int cents;
    bool negative = false;
    
    ins>>oneChar; // could be '$' if positive, or '-' if negative
    
    if (oneChar == '-'){
        negative = true;
        ins >> oneChar; // now reading '$'
    }
    
    ins>>dollars>>decimalPoint>>digit1>>digit2;
    
    if (oneChar != '$' || decimalPoint != '.' || !isdigit(digit1) || !isdigit(digit2)){
        cout<<"Illegal value entered/n";
        exit(1);
    }
    
    cents = digitToInt(digit1)*10+digitToInt(digit2);
    amount.allCents = dollars*100+cents;
    return ins;
}

class Check{
public:
    Check(Money check);
    Check();
    
    friend double operator +(const Check& amount1, const Check& amount2);
    friend double operator -(const Check& amount1, const Check& amount2);
    friend istream& operator >>(istream& ins, Check& check);
    friend ostream& operator <<(ostream& outs, const Check& check); //returns check number and its amount
    double getAmount() const;
    void setAmount(Money amount);
    void checkCashed();
    bool cashedStatus() const;
    void setCheckNum(int number);
    
private:
    int checkNum;
    Money checkAmount;
    bool cashed;
};

Check:: Check(Money check){
    checkAmount = check.getValue();
    cashed = false;
}

Check:: Check(): checkAmount(0), cashed(false){};

double operator +(const double& balance, const Money& check){
    double temp;
    temp = balance+check.getValue();
    return temp;
}

double operator -(const double& balance, const Money& check){
    double temp;
    temp = balance-check.getValue();
    return temp;
}

void Check:: checkCashed(){
    cashed = true;
}

bool Check:: cashedStatus() const{
    return cashed;
}

void Check:: setAmount(Money amount){
    checkAmount = amount.getValue();
}

void Check:: setCheckNum(int number){
    checkNum = number;
}

double Check:: getAmount() const{
    return checkAmount.getValue();
}

istream& operator >>(istream& ins, Check& check){
    ins>>check.checkAmount;
    return ins;
}

ostream& operator <<(ostream& outs, const Check& check){
    outs<<check.checkNum<<check.checkAmount.getValue();
    return outs;
}

void sort(double* arr, int size);

int main(){
    double oldBalance, newBalance, totalDeposits=0.0, totalCashed=0.0, bankBalance;
    char cash;
    Money curr;
    int totalChecks, checksCashed=0;
    
    cout<<"Enter your bank account balanace last time it was balanced:\n";
    cin>>oldBalance;
    cout<<"How many checks in total have you written since last time you balanced your account?\n";
    cin>>totalChecks;
    Check checkBook[totalChecks];
    cout<<"One by one, enter these "<<totalChecks<<" amounts of checks and a 'y' to indicate if a check has been cashed";
    cout<<" or a 'n' to indicate it hasn't.\n";
    vector<Check> cashedChecks;
    vector<Check> nonCashedChecks;
    for (int i=0; i<totalChecks; i++){
        cin>>curr;
        checkBook[i].setAmount(curr);
        checkBook[i].setCheckNum(i+1);
        cin>>cash;
        if (cash == 'y'){
            checkBook[i].checkCashed();
            totalCashed+= checkBook[i].getAmount();
            cashedChecks.push_back(checkBook[i]);
            checksCashed++;
        }
        else{
            nonCashedChecks.push_back(checkBook[i]);
        }
    }
    cout<<"Cashed checks are the following:\n";
    for (int i=0; i<checksCashed; i++)
        cout<<cashedChecks[i];
    
    cout<<"Non-cashed checks are the following:\n";
    for (int i=0; i<totalChecks; i++){
        if (!checkBook[i].cashedStatus())
            cout<<checkBook[i];
    }
    
    cout<<"Enter deposits made since last time you balanced your account:\n";
    vector<Money> deposits;
    cin>>curr;
    deposits.push_back(curr);
    for (int i=0; i<unsigned(deposits.size()); i++)
        totalDeposits+= deposits[i].getValue();
    
    for (int i=0; i<totalChecks; i++)
        if (checkBook[i].cashedStatus())
            totalCashed+= checkBook[i].getAmount();
    
    bankBalance = oldBalance + totalDeposits - totalCashed;
    newBalance = oldBalance + totalDeposits;
    for (int i=0; i<totalChecks; i++)
        newBalance-= checkBook[i].getAmount();
    
    cout<<"Total amount of checks cashed, total amount of deposits, new balance, and bank balance are as follows, in that order:\n";
    cout<<totalCashed<<", "<<totalDeposits<<", "<<newBalance<<", "<<bankBalance<<endl;
    
    double arr[checksCashed];
    for (int i=0; i<checksCashed; i++)
        arr[i]=cashedChecks[i].getAmount();
    cout<<"The list of checks cashed, sorted in ascending order, is as follows:\n";
    sort(arr, checksCashed);
    for (int i=0; i<checksCashed; i++)
        cout<<arr[i]<<" ";
    
    double arr1[totalChecks-checksCashed];
    for (int i=0; i<totalChecks-checksCashed; i++)
        arr1[i] = nonCashedChecks[i].getAmount();
    cout<<"The list of checks not cashed, sorted in ascending order, is as follows:\n";
    sort(arr1, totalChecks-checksCashed);
    for (int i=0; i<totalChecks-checksCashed; i++)
        cout<<arr1[i]<<" ";
    return 0;
}

void sort(double* arr, int size){
    for (int i=0; i<size; i++)
        for (int j=0; j<i; j++)
            if(arr[j]>arr[j+1]){
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
}
