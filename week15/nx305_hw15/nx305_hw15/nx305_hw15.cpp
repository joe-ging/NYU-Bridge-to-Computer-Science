#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

void openFile(ifstream& infile);

typedef class employeeNode{
    int ID;
    string name;
    double rate;
    double hours;
    double total;
    employeeNode* next;
public:
    employeeNode(): next(nullptr), hours(0), rate(0), ID(0), name("Nobody"), total(hours*rate){};
    void setID(int newID) {ID = newID;}
    void setName(string newName) {name = newName;}
    void setRate(double newRate) {rate = newRate;}
    void addHours(double newHours) {hours += newHours;}
    void setTotal() {total = hours*rate;}
    int getID() const {return ID;}
    string getName()const {return name;}
    double getRate()const {return rate;}
    double getHours()const {return hours;}
    double getTotal()const {return total;}
    employeeNode* getNext()const {return next;}
    friend class linkedList;
    friend class rate;
}* nodePtr;

class rates{
    int ID;
    double hours;
public:
    rates(): ID(0), hours(0) {}
    int getID()const {return ID;}
    double getHours()const {return hours;}
    void setID(int newID) {ID = newID;}
    void setHours(int newHours) {hours = newHours;}
};

class linkedList{
    nodePtr head;
public:
    linkedList(): head(nullptr) {};
    ~linkedList(){delete head;}
    void insert(employeeNode E);
    void sort(employeeNode **head);
    void search(rates target);
    nodePtr getHead() {return head;}
};

int main() {
    string name;
    double rate, hours;
    int ID;
    vector<rates> v1;
    ifstream infile1, infile2;
    linkedList L;
    
    cout<<"Enter your first file path containing employees' IDs, rates, and names: ";
    openFile(infile1);
    while(infile1>>ID>>rate){
        employeeNode E;
        E.setID(ID);
        E.setRate(rate);
        infile1.ignore(1);
        getline(infile1, name);
        E.setName(name);
        L.insert(E);
    }
    infile1.close();

    cout<<"Enter your second file path containing employees' IDs and hours worked: ";
    openFile(infile2);
    while(infile2>>ID>>hours){
        rates R;
        R.setID(ID);
        R.setHours(hours);
        v1.push_back(R);
    }
 
    for (rates R: v1)
        L.search(R);
    
    vector<double> salary;
    nodePtr tmp = L.getHead();
    while (tmp!= nullptr){
        salary.push_back(tmp->getTotal());
        tmp=tmp->getNext();
    }

    for (int i=unsigned(salary.size()); i>0; i--)
        for (int j=0; j<i; j++)
            if (salary[j]<salary[j+1]){
                double t = salary[j+1];
                salary[j+1] = salary[j];
                salary[j] = t;
            }

    vector<string> names;
    tmp = L.getHead();
    for (int s=0; s<unsigned(salary.size());s++){
        while (tmp!=nullptr){
            if (tmp->getTotal()==salary[s])
                names.push_back(tmp->getName());
            tmp=tmp->getNext();
        }
        tmp=L.getHead();
    }
    
    ofstream outfile("output.txt");
    if(outfile.fail()){
        cout<<"Output file opening failed. Please re-try.\n";
        exit(1);
    }
    
    outfile<<"*********Payroll Information********\n";
    for (int i=0; i<unsigned(salary.size());i++)
        outfile<<names[i]<<", $"<<salary[i]<<endl;
    outfile<<"*********End payroll**************\n";
    outfile.close();
    cout<<"Payroll information has been saved in the file \"output.txt\" in your current directory.\n";
}

void openFile(ifstream& infile){
    string file;
    cin>>file;
    infile.open(file);
    while(!infile){
        cout<<"Invalid file path. Re-enter: ";
        cin>>file;
        infile.clear();
        infile.open(file);
    }
}

void linkedList:: insert(employeeNode E){
    nodePtr tmp = new employeeNode;
    tmp->ID = E.getID();
    tmp->rate = E.getRate();
    tmp->name = E.getName();
    tmp->next = head;
    head=tmp;
}

void linkedList:: search(rates target){
    nodePtr here=head;
    
    if (here == nullptr)
        return;
    else {
        while (here->ID != target.getID() && here->next != nullptr)
            here = here->next;
        if (here->ID == target.getID()){
            here->addHours(target.getHours());
            here->setTotal();
            }
        else return;
    }
}
