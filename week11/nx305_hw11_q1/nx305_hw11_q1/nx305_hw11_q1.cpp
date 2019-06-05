#include <iostream>
using namespace std;

void printTriangle(int n);
void printUpsideDownTriangles(int n);
void printOppositeTriangles(int n);
void printRuler(int n);

int main() {
    int n;
    
    cout << "Enter a number to print: ";
    cin>>n;
    
    printTriangle(n);
    cout<<endl<<endl;
    printOppositeTriangles(n);
    cout<<endl<<endl;
    printRuler(n);
    return 0;
}

void printTriangle(int n){
    if(n==1)
        cout<<"*";
    else{
        printTriangle(n-1);
        cout<<endl;
        for (int i=0; i<n; i++)
            cout<<"*";
    }
}

void printUpsideDownTriangles(int n){
    if(n==1)
        cout<<"*";
    else{
        for (int i=0; i<n; i++)
            cout<<"*";
        cout<<endl;
        printUpsideDownTriangles(n-1);
    }
}

void printOppositeTriangles(int n){
    printUpsideDownTriangles(n);
    cout<<endl;
    printTriangle(n);
}

void printRuler(int n){
    if(n==1)
        cout<<"-";
    else{
        printRuler(n-1);
        cout<<endl;
        for (int i=0; i<n; i++)
            cout<<"-";
        cout<<endl;
        printRuler(n-1);
    }
}
