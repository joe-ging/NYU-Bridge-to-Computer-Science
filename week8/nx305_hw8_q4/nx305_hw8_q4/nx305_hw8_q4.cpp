#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void generateRandom(int password);
void convertPassword(string str, int pwd, int array[]);

int main() {
    int password1;
    const int password=38120;
    
    password1 = password;
    
    cout<<"Please enter your PIN according to the following mapping:\n";
    cout<<"PIN: 0 1 2 3 4 5 6 7 8 9"<<endl<<"NUM: ";
    generateRandom(password1);
    
    return 0;
}

void generateRandom(int password){
    int i, random[10];
    string input;
    
    srand(unsigned(time(0)));
    for(i=0; i<10; i++){
        random[i]=(rand()%3)+1;
        cout<<random[i];
        cout<<" ";
    }
    cout<<endl;
    cin>>input;
    convertPassword(input, password, random);
}

void convertPassword(string str, int pwd, int array[]){
    int converted[5], i;
    string guess;
    
    for (i=0; i<5; i++){
        converted[i]=pwd%10;
        pwd/=10;
    }
    
    guess="";
    for (i=4; i>=0; i--){
        guess+= to_string(array[converted[i]]);
    }
    
    if (guess == str)
        cout << "Your PIN is correct\n";
    else cout<<"Your PIN is incorrect\n";
}
