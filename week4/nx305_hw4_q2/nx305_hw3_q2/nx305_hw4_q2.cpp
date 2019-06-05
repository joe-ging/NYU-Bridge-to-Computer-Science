#include <iostream>
#include <string>
using namespace std;

int main() {

    const int V=5, X=10, L=50, C=100, D=500, M=1000;
    int input, i, v, x, l, c, d, m;
    string output;

    cout<<"Enter decimal number: \n";
    cin>>input;

    for(m=0; m<input/M; m++)
        output+="M";
    for(d=0; d<input%M/D; d++)
        output+="D";
    for(c=0; c<input%M%D/C; c++)
        output+="C";
    for(l=0; l<input%M%D%C/L; l++)
        output+="L";
    for(x=0; x<input%M%D%C%L/X; x++)
        output+="X";
    for(v=0; v<input%M%D%C%L%X/V; v++)
        output+="V";
    for(i=0; i<input%M%D%C%L%X%V; i++)
        output+="I";
    
    cout<<input<<" is "<<output<<endl;

    return 0;
}
