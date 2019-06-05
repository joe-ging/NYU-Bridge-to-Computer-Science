#include <iostream>
#include <vector>
using namespace std;

void oddsKeepEvensFlips(int arr[], int arrSize);
void splitParity(int arr[], int arrSize, int& outOddCount);

int main() {
    const int size = 6;
    int arr[size] = {4, 3, 1, 7, 6, 8};

    oddsKeepEvensFlips(arr,size);

    for (int i=0; i<size; i++)
        cout<<arr[i]<<" ";
    cout <<endl;
    return 0;
}

void oddsKeepEvensFlips(int arr[], int arrSize){
    int oddSize;
    vector<int> v;
    int* array = new int[arrSize];
    for (int i=0; i<arrSize; i++)
        array[i] = arr[i];
    
    splitParity(array, arrSize, oddSize);
    for (int i=0; i<oddSize; i++)
        v.push_back(array[i]);

    for (int i=arrSize-1; i>=arrSize-oddSize; i--)
        v.push_back(array[i]);

    for (int i = 0; i<arrSize; i++)
        arr[i] = v[i];
    
    delete[] array;
}

void splitParity(int arr[], int arrSize, int& outOddCount){
    int i, j, k, oddCount;
    
    j = 0;
    k = 1;
    oddCount = 0;
    for (i=0; i<arrSize; i++){
        if (arr[i]%2==0) {
            arr[10-k] = arr[i];
            k++; // k is even number count
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
    outOddCount = oddCount;
}
