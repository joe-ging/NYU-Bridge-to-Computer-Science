#include <iostream>
#include <vector>
using namespace std;

template<class T>
class node{
    T element;
    node* next;
public:
    node(): next(nullptr){};
    T getElement() {return element;}
    void setElement(T newElement) {element=newElement;}
    node* getNext() {return next;}
    void setNext(node* newNext) {next = newNext;}
};

template<class T>
class queue{
    vector<node<T>> vec;
    node<T>* head;
    int size;
public:
    queue(): head(nullptr){}
    void push(node<T> newNode);
    node<T> pop();
    int getSize() {return unsigned(vec.size());}
    vector<T> getVec()const {return vec;}
    node<T>* getHead() {return head;}
    void setHead(node<T>* newHead) {head = newHead;}
    vector<node<T>> getVec() {return vec;}
};

int main() {
    queue<int> v;

    for (int i=0;i<5;i++){
        node<int>* newNode = new node<int>;
        newNode->setElement(i);
        v.push(*newNode);
    }
    cout<<"The elements in the vector are initially:\n";
    for (int i=0; i<v.getSize();i++)
        cout<<v.getVec()[i].getElement()<<" ";
    cout<<"\nAfter popping, the popped element is "<<v.pop().getElement()<<endl;
}

template<class T>
node<T> queue<T>:: pop(){
    node<T>* tmp = head;
    head=head->getNext();
    return *tmp;
}

template<class T>
void queue<T>:: push(node<T> newNode){
    if (head==nullptr){
        node<T>* newPtr = new node<T>;
        newPtr->setElement(newNode.getElement());
        head=newPtr;
    }
    else{
        node<T>* newPtr = new node<T>;
        newPtr->setElement(newNode.getElement());
        node<T>* end = head;
        while (end->getNext() != nullptr)
            end=end->getNext();
        end->setNext(newPtr);
    }
    vec.push_back(newNode);
}
