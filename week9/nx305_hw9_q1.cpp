#include <iostream>
#include <string>
using namespace std;

void countWords(string input);
bool isLetter(char input);
bool isDelimiter(char input);
void stripDelimiters(string& input);
void reorder(string& input);
int smallestIndex(string input, int start);
void countLetters(string input);

int main() {
    string input;
    
    cout << "Please enter a line of text:\n";
    getline(cin, input);
    countWords(input);
    stripDelimiters(input);
    reorder(input);
    countLetters(input);
    
    cout<<endl;
    return 0;
}

void countWords(string input){
    int count;
    
    count = 0;
    for (int i = 0; i<input.length(); i++){
        if ((isLetter(input[i])) && ((isDelimiter(input[i+1]))||(i == input.length()-1)))
            count++;
    }
    
    cout<<count<<"\twords"<<endl;
}

bool isLetter(char input){
    bool letter;
    int asciLower, asciHigher;
    
    letter = false;
    asciLower = 'a';
    asciHigher = 'A';
    if (((input - asciHigher < 26)&&(input>=asciHigher))||((input-asciLower<26)&&(input>=asciLower)))
        letter = true;
    
    return letter;
}

bool isDelimiter(char input) {
    bool delimiter;
    
    delimiter = false;
    if ((input=='.')||(input==',')||(input==' ')||(input=='\n'))
        delimiter = true;
    
    return delimiter;
}

void stripDelimiters(string& input){
    string lettersOnly="";
    
    for (int i=0; i<input.length(); i++){
        if (isLetter(input[i]))
            lettersOnly+= input[i];
        }
    input = lettersOnly;
}

void reorder(string& input){
    int indexSmallest;
    char temp;

    for (int i=0; i<input.length(); i++){
        input[i] = tolower(input[i]);
    }

    for (int i=0; i<input.length()-1; i++){
        indexSmallest = smallestIndex(input, i);
        temp = input[i];
        input[i] = input[indexSmallest];
        input[indexSmallest] = temp;
    }
}

int smallestIndex(string input, int start){
    char min;
    int minIndex;
    
    min = input[start];
    minIndex = start;
    for (int i=start+1; i<input.length(); i++){
        if (input[i] < min){
            min = input[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void countLetters(string input){
    int count, j;

    for (int i=0; i<input.length(); i+=j){
        count=1;
        j = 1;
        while (input[i+j] == input[i]){
            count++;
            j++;
        }
        cout<<count<<"\t"<<input[i]<<endl;
    }
}
