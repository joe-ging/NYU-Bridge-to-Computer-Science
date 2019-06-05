#include <iostream>
#include <vector>
using namespace std;

int* findMissing(int arr[], int n, int& resArrSize);

int main() {
    int n;
    
    cout<<"Enter the size of the array: ";
    cin>>n;
    int resArrSize=n;
    int* arr = new int[n];
    cout << "Enter an array of "<<n<<" integers:\n";
    for (int i=0; i<n; i++)
        cin>>arr[i];

    findMissing(arr, n, resArrSize);
    
    cout<<"The new array size is "<<resArrSize<<" and the elements are:\n";
    for (int i=0; i<resArrSize; i++)
        cout<<*(findMissing(arr, n, resArrSize)+i)<<" ";

    delete[] arr;
    cout<<endl;
    delete[] findMissing(arr, n, resArrSize);
    return 0;
}

int* findMissing(int arr[], int n, int& resArrSize){
    vector<int> v;
    vector<int> v1;
    int count = 0;
    
    for (int i=0; i <= n; i++)
        v.push_back(false);
    
    for (int i=0; i < n; i++)
        v[arr[i]] = true;
    
    for (int i=0; i<=n; i++)
        if (v[i] == false){
            count++;
            v1.push_back(i);
        }
    
    resArrSize = count;

    int* newArr = new int[resArrSize];
    for (int i=0; i<resArrSize; i++)
        newArr[i] = v1[i];

    return newArr;
}
