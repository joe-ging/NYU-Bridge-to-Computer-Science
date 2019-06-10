#include <iostream>
using namespace std;

void printArray(int arr[], int arrSize);
int* firstPosIntsArr(int n, int* size);

int main(int argc, const char * argv[]) {
    int n;
    int* arr;
    int arrSize;
    
    cout << "Please enter a positive integer:"<<endl;
    cin>>n;
    
    arr = firstPosIntsArr(n, &arrSize);
    
    cout<<"The first "<<arrSize<<" positive integers are: ";
    printArray(arr, arrSize);
    cout<<endl;
    
    delete[] arr;
    return 0;
}

int* firstPosIntsArr(int n, int* size){
    int* temp = new int[n];
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    
    for (int i=0; i<n; i++)
        temp[i] = arr[i];
    
    *size = n;
    return temp;
}

void printArray(int arr[], int arrSize){
    int i;
    for(i=0; i<arrSize; i++)
        cout<<arr[i]<<" ";
}
