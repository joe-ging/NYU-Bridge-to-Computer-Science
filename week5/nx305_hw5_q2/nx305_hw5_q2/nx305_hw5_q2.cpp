#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

int main() {
    int x4, guess, guessUsed, upper, lower;
    bool wrong;
    
    srand(unsigned(time(0)));
    x4 = (rand() % 100) + 1;
//    cout<<50x4<<"\n";
    cout<<"I thought of a number between 1 and 100! Try to guess it.\n";
    
    guessUsed = 1;
    upper = 100;
    lower = 1;
    wrong = true;
    while((guessUsed<5)&&(wrong == true)){
        cout<<"Range: ["<<lower<<", "<<upper<<"], Number of guesses left: "<<6-guessUsed<<endl;
        cout<<"Your guess: ";
        cin>>guess;
        
        if (guess<x4) {
            cout<<"Wrong! My number is bigger.\n"<<endl;
            ++guessUsed;
            lower = guess+1;
        }
        else if (guess>x4) {
            cout<<"Wrong! My number is smaller.\n"<<endl;
            ++guessUsed;
            upper = guess-1;
        }
        else {
            if (guessUsed==1){
                cout<<"Congrats! You guessed my number in 1 guess.\n";
                wrong = false;}
            else {
                cout<<"Congrats! You guessed my number in "<<guessUsed<<" guesses.\n";
                wrong = false;}
        }
    }
    if ((wrong == true)&&(guessUsed==5)){
        cout<<"Range: ["<<lower<<", "<<upper<<"], Number of guesses left: 1"<<endl;
        cout<<"Your guess: ";
        cin>>guess;
        if (guess==x4)
            cout<<"Congrats! You guessed my number in 5 guesses.\n";
        else
            cout<<"Out of guesses! My number is "<<x4<<endl;
    }
    return 0;
}
