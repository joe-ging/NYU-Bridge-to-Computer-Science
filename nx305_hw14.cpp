#include <iostream>
#include <vector>
using namespace std;

vector<double> minMax(vector<double> v, int size);
vector<double> compare(vector<double> v1, vector<double> v2);

int main() {
    double curr, size=0;
    bool end = false;
    vector<double> v;
    
    cout << "Enter a list of numbers to find the max and min. Enter -1 to end.\n";
    while (end == false) {
        cin >> curr;
        if (curr == -1) end=true;
        else{
            v.push_back(curr);
            size++;
        }
    }
    
    cout<<"The minimum is "<<minMax(v, size)[0]<<" and the maximum is "<<minMax(v, size)[1]<<endl;
}

vector<double> minMax(vector<double> v, int size) {
    int low=0, high=size, mid = (low+high)/2, i, max, min;
    vector<double> res, res1, res2, firstHalf, secondHalf;
    
    if (size == 1){
        min = max = v[size-1];
        res.push_back(min);
        res.push_back(max);
    }
    else if (size==2) {
        if (v[0] >= v[1]){
            min = v[1];
            max = v[0];
        }
        else {
            min = v[0];
            max = v[1];
        }
        res.push_back(min);
        res.push_back(max);
    }
    else {
        for (i=0; i<=mid; i++)
            firstHalf.push_back(v[i]);
        for (i=mid+1; i<high; i++)
            secondHalf.push_back(v[i]);
        res1=minMax(firstHalf, unsigned(firstHalf.size()));
        res2=minMax(secondHalf, unsigned(secondHalf.size()));
        res=compare(res1, res2);
    }
    
    return res;
}

vector<double> compare(vector<double> v1, vector<double> v2){
    vector<double> res;

    if (v1[0] <= v2[0])
        res.push_back(v1[0]);
    else res.push_back(v2[0]);
    if (v1[1] >= v2[1])
        res.push_back(v1[1]);
    else res.push_back(v2[1]);
    
    return res;
}
