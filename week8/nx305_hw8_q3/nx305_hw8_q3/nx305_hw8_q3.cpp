#include <iostream>
#include <string>
using namespace std;

void reverseArray(int arr[], int arrSize);
void removeOdd(int arr[], int& arrSize);
void splitParity(int arr[], int arrSize);
void printArray(int arr[], int arrSize);

int main() {
    int testArray[10] = {9, 2, 14, 12, -3};
    int size = 5;
    
    int testArray1[10] = {21, 12, 6, 7, 14};
    int size1 = 5;

    int testArray2[10] = {3, 6, 4, 1, 12};
    int size2 = 5;
    
    reverseArray(testArray, size);
    printArray(testArray, size);

    removeOdd(testArray1, size1);
    printArray(testArray1, size1);

    splitParity(testArray2, size2);
    printArray(testArray2, size2);

    return 0;
}

void reverseArray(int arr[], int arrSize){
    int i, temp;

    for (i = 0; i < arrSize/2; i++){
        temp = arr[i];
        arr[i] = arr[arrSize-1-i];
        arr[arrSize-1-i] = temp;
    }
}

void removeOdd(int arr[], int& arrSize){
    int remaining, i, j;
    
    remaining = 0;
    j = 0;
    for (i=0; i<arrSize; i++){
        if (arr[i]%2 == 0){
            arr[j] = arr[i];
            remaining++;
            j++;
        }
    }
    arrSize = remaining;
}

void splitParity(int arr[], int arrSize){
    int i, j, k, oddCount;
    
    j = 0;
    k = 1;
    oddCount = 0;
    for (i=0; i<arrSize; i++){
        if (arr[i]%2==0) {
            arr[10-k] = arr[i];
            k++;
            }
        else {
            arr[j] = arr[i];
            j++;
            oddCount++;
        }
    }
    
    j = 0;
    k = 1;
    for (i = 0; i<(arrSize-oddCount); i++){
        arr[oddCount+i] = arr[10-k];
        k++;
    }
}

void printArray(int arr[], int arrSize){
    int i;
    
    for(i=0; i<arrSize; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
