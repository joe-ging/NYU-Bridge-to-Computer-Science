#include <iostream>
using namespace std;

void printShiftedTriangle(int n, int m, char symbol);
void printPineTree(int n, char symbol);

int main() {
    
//    test my functions here:
//    printShiftedTriangle(3,4,'*');
    printPineTree(3,'@');
    return 0;
}

void printShiftedTriangle(int n, int m, char symbol) {
    int lineNum, numSpaces, numSymbols;
    
    for (lineNum = 1; lineNum <= n; lineNum++) {
        for (numSpaces = 1; numSpaces <= m + n - lineNum; numSpaces++)
            cout << " ";
        for (numSymbols = 1; numSymbols <= 2 * lineNum - 1; numSymbols++)
            cout << symbol;
        cout << endl;
    }
    return;
}

void printPineTree(int n, char symbol) {
    int treeNum, indent;
    
    for (treeNum = 1, indent = n-1; treeNum <= n; treeNum++, indent--) {
        printShiftedTriangle(treeNum+1, indent, symbol);
    }
    return;
}
