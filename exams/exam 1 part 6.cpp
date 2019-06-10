#include <iostream>
using namespace std;

int main() {
    int n, sequence,input,evenNum, oddNum, count;
    bool flag;
    
    cout<<"How many sequences do you wish to enter?\n";
    cin>>n;
    cout<<"Please enter "<<n<<" lines, each with a sequence of positive integers. ";
    cout<<"For each sequence, separate the elements by a space, and end it by typing -1:\n";
    
    evenNum = 0;
    oddNum = 0;
    
    for(sequence = 1;sequence<=n; sequence++){
        cout<<"Sequence #"<<sequence<<": ";
        count=0;
        flag=false;
        while(flag==false) {
            cin>>input;
            if (input != -1){
                count++;}
            else {
                flag = true;}
        }
        if(count%2 == 0){
            evenNum++;}
        else {oddNum++;}
    }
    
    cout<<"There were "<<evenNum<<" with even number of elements, and "<<oddNum<<" with odd number of elements.\n";
        
    return 0;
}