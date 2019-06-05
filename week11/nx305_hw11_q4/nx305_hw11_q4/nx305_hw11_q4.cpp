#include <iostream>
using namespace std;

int lowest(int* arr, int size);

int main() {
    const int size = 6;
    int arr[size] = {0,300,80,6,57,10};
    
    cout<<"The lowest possible cost is "<<lowest(arr,size-1)+arr[size-1]<<endl;
    return 0;
}

int lowest(int* arr, int size){
    int lowestCost;
    
    if((size==2)||(size==1))
        lowestCost = arr[size-1];
    else{
        lowestCost = lowest(arr, size-2);
            if(arr[size-2]<arr[size-1])
                lowestCost+=arr[size-2];
            else lowestCost+=arr[size-1];
    }
    
    return lowestCost;
}


int jumpingOnClouds(vector<int> c) {
    int steps;

    if (c.size()==2 || c.size()==3)
        steps = 1;
    else {
        if (c.size()==4)
            steps = 2;
        else {
            vector<int> c1(c.begin(), c.end()-5);
            steps = jumpingOnClouds(c1);
            if (c[c.size()-3] == 1)
                steps+=2;
            else steps++;
        }
    }
    return steps;
}
