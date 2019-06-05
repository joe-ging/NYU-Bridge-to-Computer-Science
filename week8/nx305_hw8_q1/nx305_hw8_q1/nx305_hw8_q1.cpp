#include <iostream>
#include <string>
using namespace std;

int minInArray(int arr[], int arrSize);
string indexArray(int arr[], int arrSize);

int main() {
    int arr[20], num;
    
    cout<<"Please enter 20 integers separated by a space:\n";
    for (int i=0; i<20; i++) {
        cin>>num;
        arr[i] = num;
    }
  
    cout << "The minimum value is "<<minInArray(arr, 20);
    cout<<", and it is located in the following ";
    cout<<"indices: "<<indexArray(arr, 20)<<endl;
    
    return 0;
}

int minInArray(int arr[], int arrSize){
    int min;
    string indexString;
    
    min = arr[0];
    indexString = "";
    for (int i=0; i<arrSize-1; i++){
        if (arr[i] < arr[i+1])
            min=arr[i];
        else
            min = arr[i+1];
    }
    return min;
}
    
string indexArray(int arr[], int arrSize) {
    string indexString;
    
    indexString = "";
    for (int i=0; i<arrSize-1; i++){
        if (arr[i] == minInArray(arr, 20)){
            indexString+=to_string(i);
            indexString+=" ";
        }
    }
    return indexString;
}
