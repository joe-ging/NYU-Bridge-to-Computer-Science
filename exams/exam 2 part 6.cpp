#include <iostream>
using namespace std;

bool isPalindrome(int seq[], int seqSize);
void reverseArray(int seq[], int seqSize);

int main() {
    const int size = 6;
    int seq[size] = {3, 4, 5, 5, 4, 3};
    
    if (isPalindrome(seq, size) == true)
        cout<<"The sequence is a palindrome.\n";
    else
        cout<<"The sequence is not a palindrome.\n";
    
    return 0;
}

bool isPalindrome(int seq[], int seqSize){
    bool res=false;
    int newArr[seqSize];
    
    for(int i=0; i<seqSize; i++)
        newArr[i]= seq[i];
    
    reverseArray(seq, seqSize);
    
    for(int i=0; i<seqSize; i++){
        if(newArr[i] == seq[i])
            res=true;
    }
    
    return res;
}

void reverseArray(int seq[], int seqSize){
    int temp;
    
    if(seqSize==1)
        return;
    else{
        reverseArray(seq,seqSize-1);
        temp = seq[seqSize-1];
        for (int i=seqSize-2; i>=0;i--)
            seq[i+1] = seq[i];
        seq[0] = temp;
    }
}
