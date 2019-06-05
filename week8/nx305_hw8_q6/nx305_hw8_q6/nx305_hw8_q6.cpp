#include <iostream>
#include <string>
using namespace std;

void whitespaceArray(string input);
void elementArray(string input, int counter, int arr[]);
void allNumbers(string arr[], int arrSize);

int main() {
    string input;
    
    cout << "Please enter a line of text:\n";
    getline(cin,input);
    whitespaceArray(input);

    cout<<endl;
    
    return 0;
}
    
void whitespaceArray(string input){
    int counter, i, whitespace[9999];
    
    counter=-1;
    for (i=0; i<input.length(); i++){
        if (input[i] == ' '){
            counter++;
            whitespace[counter] = i;
        }
    }
    
    elementArray(input, counter, whitespace);
}
    
void elementArray(string input, int counter, int arr[]){
    string firstElement, element, elementArray[9999];
    int i;
    
    firstElement=input.substr(0, arr[0]);
    elementArray[0] = firstElement;
        
    for(i=0; i<counter+1; i++){
        element = input.substr(arr[i]+1,arr[i+1]-arr[i]-1);
        elementArray[i+1] = element;
    }
    
    allNumbers(elementArray, counter+2);
}

void allNumbers(string arr[], int arrSize){
    int i, numCount, element;

    for (element=0; element<arrSize; element++){
        numCount=0;
        for (i=0; i<arr[element].length(); i++){
            if ((arr[element][i]=='0')||(arr[element][i]=='1')||(arr[element][i]=='2')||(arr[element][i]=='3')||(arr[element][i]=='4')||(arr[element][i]=='5')||(arr[element][i]=='6')||(arr[element][i]=='7')||(arr[element][i]=='8')||(arr[element][i]=='9'))
                numCount++;
            
            if (numCount == arr[element].length()){
                for (i=0; i<numCount; i++){
                    arr[element][i] = 'x';
                    }
                }
            }
        }
    for(i=0; i<arrSize; i++){
        cout<<arr[i]<<" ";
    }
}
