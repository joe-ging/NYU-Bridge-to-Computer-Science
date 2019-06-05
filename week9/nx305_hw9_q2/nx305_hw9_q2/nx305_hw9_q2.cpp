#include <iostream>
#include <string>
using namespace std;

bool isLetter(char input);
void stripDelimiters(string& input);
bool anagram(string word1, string word2);
int countLetters(string input);

int main() {
    string word1, word2;
    
    cout << "Enter the first string: ";
    getline(cin,word1);
    cout<<"Enter the second string: ";
    getline(cin,word2);
    stripDelimiters(word1);
    stripDelimiters(word2);
    if (anagram(word1, word2) == true)
        cout<<"These two words are anagrams.\n";
    else
        cout<<"These two words are not anagrams.\n";
    
    return 0;
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

void stripDelimiters(string& input){
    string lettersOnly="";
    
    for (int i=0; i<input.length(); i++){
        if (isLetter(input[i]))
            lettersOnly+= input[i];
    }
    input = lettersOnly;
}

int countLetters(string input){
    int count, j, total=0;
    
    for (int i=0; i<input.length(); i+=j){
        count=1;
        j = 1;
        while (input[i+j] == input[i]){
            count++;
            j++;
        }
        total+= count;
    }
    return total;
}

bool anagram(string word1, string word2){
    bool anagram = false;
    
    if (countLetters(word1) == countLetters(word2))
        anagram = true;
    return anagram;
}
