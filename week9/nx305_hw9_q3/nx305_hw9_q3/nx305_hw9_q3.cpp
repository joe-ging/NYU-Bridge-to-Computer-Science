#include <iostream>
#include <vector>
using namespace std;

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize);
void getPosNums2(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize);
int* getPosNums3(int* arr, int arrSize, int* outPosArrSizePtr);
void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr);

int main() {
    int size, outPosArrSize, outSize;
    int sizePtr;
    
    cout<<"Enter size of the array, no more than 10: ";
    cin>>size;
    int* arr = new int[size];
    cout << "Enter the list of integers:\n";
    for (int i = 0; i<size; i++){     // -3 5 3 -8 9 2
        cin>>arr[i];
    }
    
    cout<<endl;
    cout<<"Version a: \n";
    getPosNums1(arr, size, outPosArrSize);
    cout<<"The array has now been changed to the following elements: ";
    for (int i=0; i<outPosArrSize; i++)
        cout<<*(getPosNums1(arr, size, outPosArrSize)+i)<<" ";
    cout<<"\nAnd it now has "<<outPosArrSize<<" elements.";
    int* temp = new int[size];
    temp = arr;
    delete[] arr;
    cout<<endl;

    cout<<"\nVersion b: \n";
    outSize = size;
    int *outArr=new int[outSize];
    getPosNums2(arr, size, outArr, outSize);
    cout<<"The array has now been changed to the following elements: ";
    for (int i=0; i<outSize; i++)
        cout<<outArr[i]<<" ";
    cout<<"\nAnd it now has "<<outSize<<" elements.";
    cout<<endl;
    delete[] outArr;
    cout<<endl;

    cout<<"Version c:\n";
    getPosNums3(arr, size, &sizePtr);
    cout<<"The array has now been changed to the following elements: ";
    for (int i=0; i<outPosArrSize; i++)
        cout<<*(getPosNums3(temp, size, &sizePtr)+i)<<" ";
    cout<<"\nAnd it now has "<<sizePtr<<" elements.";
    cout<<endl;

    cout<<"\nVersion d:\n";
    int* outArrPtr = new int[size];
    getPosNums4(arr, size, &outArrPtr, &sizePtr);
    cout<<"The array has now been changed to the following elements: ";
    for (int i=0; i<sizePtr; i++)
        cout<<outArrPtr[i]<<" ";
    cout<<"\nAnd it now has "<<sizePtr<<" elements.\n";
    delete[] outArrPtr;
    cout<<endl;
    
    return 0;
}

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize){
    outPosArrSize = 0;
    vector<int> v;
    
    for (int i=0; i<arrSize; i++){
        if (arr[i]>0)
            v.push_back(arr[i]);
    }
    
    outPosArrSize = unsigned(v.size());
    
    int* temp = new int[outPosArrSize];
    for (int i=0; i<outPosArrSize; i++){
        temp[i] = v[i];
    }
    
    return temp;
}

void getPosNums2(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize){
    outPosArrSize = 0;
    vector<int> v;
    
    for (int i=0; i<arrSize; i++){
        if (arr[i]>0)
            v.push_back(arr[i]);
    }
    
    outPosArrSize = unsigned(v.size());
    
    int* temp = new int[outPosArrSize];
    for (int i=0; i<outPosArrSize; i++){
        temp[i] = v[i];
    }
    
    outPosArr = temp;
}

int* getPosNums3(int* arr, int arrSize, int* outPosArrSizePtr){
    int outPosArrSize = 0;
    vector<int> v;
    
    for (int i=0; i<arrSize; i++){
        if (arr[i]>0)
            v.push_back(arr[i]);
    }
    
    outPosArrSize = unsigned(v.size());
    
    int* temp = new int[outPosArrSize];
    for (int i=0; i<outPosArrSize; i++){
        temp[i] = v[i];
    }
    
    *outPosArrSizePtr = outPosArrSize;
    return temp;
}

void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr){
    int outPosArrSize = 0;
    vector<int> v;
    
    for (int i=0; i<arrSize; i++){
        if (arr[i]>0)
            v.push_back(arr[i]);
    }
    
    outPosArrSize = unsigned(v.size());
    
    int* temp = new int[outPosArrSize];
    for (int i=0; i<outPosArrSize; i++){
        temp[i] = v[i];
    }
    
    *outPosArrSizePtr = outPosArrSize;
    *outPosArrPtr = temp;
}
