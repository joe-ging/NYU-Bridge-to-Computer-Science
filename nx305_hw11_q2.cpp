#include <iostream>
#include <cmath>
using namespace std;

int sumOfSquares(int arr[], int arrSize);
bool isSorted(int arr[], int arrSize);

int main() {
    const int size = 6;
    int arr[size] = {-2,-1,1,2,3,5};
    
    cout<<sumOfSquares(arr, size)<<endl;
    if (isSorted(arr, size))
        cout<<"The array is sorted.";
    else cout<<"The array is not sorted.";
    cout<<endl;
    return 0;
}

int sumOfSquares(int arr[], int arrSize){
    int res = 0;
    
    if (arrSize == 1)
        res = pow(arr[0],2);
    else{
        res = sumOfSquares(arr, arrSize-1);
        res+= pow(arr[arrSize-1],2);
    }
    return res;
}

bool isSorted(int arr[], int arrSize){
    bool result;

    if (arrSize == 1)
        result = true;
    else{
        result = isSorted(arr, arrSize-1);
        if (result == true){
            if (arr[arrSize-1]>arr[arrSize-2]){
                result = true;
            }
            else {
                result = false;
            }
        }
        else result = false;
    }
    return result;
}
