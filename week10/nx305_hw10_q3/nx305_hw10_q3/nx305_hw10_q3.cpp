#include <iostream>
#include <vector>
using namespace std;

int main1();
int main2();
void searchNum1(int* arr, int n);
void searchNum2();

int main() {
    main1();
    main2();
    return 0;
}

int main1(){
    int n=1;
    int* arr = NULL;
    
    cout<<"Version 1: without vector:\n";
    searchNum1(arr, n);
    cout<<endl;
    return 0;
}

int main2(){
    cout<<"Version 2: with vector:\n";
    searchNum2();
    return 0;
}

void searchNum1(int* arr, int n){
    int search, curr, numCommas, size=0, capacity=1;
    bool end = false;
    vector<int> v;
    int *outArr = new int[n];
    
    cout<<"Please enter a sequence of positive integers, each in a separate line.\nEnd your input by typing -1.\n";
    while (end == false){
        cin>>curr;
        if(curr==-1)
            end=true;
        else{
            if(size == capacity){
                int* newArr = new int[2*capacity];
                for (int i=0; i<size; i++)
                    newArr[i] = outArr[i];
                delete[] outArr;
                capacity*=2;
                outArr = newArr;
                newArr = NULL;
            }
            outArr[size] = curr;
            size++;
        }
    }

    arr = outArr;

    cout<<"Please enter a number you want to search.\n";
    cin>>search;
    for (int i=0;i<size; i++){
        if (search == arr[i])
            v.push_back(i+1);  //v holds line numbers
    }
    numCommas = unsigned(v.size())-1;
    cout<<search<<" shows in lines ";
    for (int i=0; i<=numCommas-1; i++)
        cout<<v[i]<<", ";
    cout<<v[numCommas]<<endl;
}

void searchNum2(){
    vector<int> v;
    bool end = false;
    int curr, search, numCommas;
    vector<int> v1;
    
    cout<<"Please enter a sequence of positive integers, each in a separate line.\nEnd your input by typing -1.\n";
    while (end == false){
        cin>>curr;
        if(curr==-1)
            end=true;
        else
            v.push_back(curr);
    }
    
    cout<<"Please enter a number you want to search.\n";
    cin>>search;
    for (int i=0;i<v.size(); i++){
        if (search == v[i])
            v1.push_back(i+1);  //v holds line numbers
    }
    numCommas = unsigned(v1.size())-1;
    cout<<search<<" shows in lines ";
    for (int i=0; i<=numCommas-1; i++)
        cout<<v1[i]<<", ";
    cout<<v1[numCommas]<<endl;
}
