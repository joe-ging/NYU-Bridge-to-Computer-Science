#include <iostream>
#include <vector>
using namespace std;

int* findCommon(int arr1[], int arr2[], int n, int& outArrSize);

int main() {
    int arr1[6] = {3,1,3,2,6,4};
    int arr2[6] = {5,4,4,3,3,3};
    int outArrSize;
    
    findCommon(arr1, arr2, 6, outArrSize);
    cout<<"There are "<<outArrSize<<" common elements in these two arrays. They are:\n";
    for (int i=0; i<outArrSize; i++)
        cout<<(*findCommon(arr1, arr2, 6, outArrSize)+i)<<" ";
    
    cout <<endl;
    return 0;
}

int* findCommon(int arr1[], int arr2[], int n, int& outArrSize){
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    
    for (int i=0; i<n; i++){
        v1.push_back(false);
        v2.push_back(false);
    }
    
    for (int i=0; i<n; i++){
        v1[arr1[i]] = true;
        v2[arr2[i]] = true;
    }

    for(int i = 0; i<n; i++)
        if((v1[i] == true) && (v2[i] == true))
            v3.push_back(i);

    outArrSize = unsigned(v3.size());
    int* temp = new int[outArrSize];
    for (int i=0; i<outArrSize; i++)
        temp[i] = v3[i];

    return temp;
}
