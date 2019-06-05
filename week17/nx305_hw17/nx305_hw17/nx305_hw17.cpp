#include <iostream>
#include <ctime>
#include <queue>
using namespace std;

template <class T>
class RBT;

template <class T>
class RBTNode{
    RBTNode<T>* parent, *left, *right;
    char color;
    T data;
public:
    friend class RBT<T>;
    RBTNode(const T& newdata = T(), RBTNode<T>* newparent = nullptr, RBTNode<T>* newleft = nullptr, RBTNode<T>* newright = nullptr):
    data(newdata), parent(newparent), left(newleft), right(newright), color('R'){};
    
    int size()const{
        int leftSize = 0;
        int rightSize = 0;
        if (left != nullptr)
            leftSize = left->size();
        if (right != nullptr)
            rightSize = right->size();
        return 1 + leftSize + rightSize;
    }
};

template <class T>
class RBT{
    RBTNode<T>* root;
    void singleCCR(RBTNode<T>*& point);
    void singleCR(RBTNode<T>*& point);
public:
    RBT():root(nullptr){}
    
    RBT(const RBT<T>& rhs): root(nullptr){*this = rhs;}
    RBT& operator=(const RBT<T>& rhs);
    
    void insert(const T&);
    void recolor(RBTNode<T>*& point);
    void printLevelOrder()const{
        queue<RBTNode<T>*> q;
        q.push(root);
        
        while(!q.empty()){
            RBTNode<T>* tmp=q.front();
            cout<<tmp->data<<' '<<tmp->color<<endl;
            q.pop();
            if (tmp->left != nullptr)
                q.push(tmp->left);
            if (tmp->right != nullptr)
                q.push(tmp->right);
        }
    }
};

template <class T>
void RBT<T>::singleCR(RBTNode<T>*& point){
    RBTNode<T>* grandparent = point;
    RBTNode<T>* parent = point->left;
    parent->parent = grandparent->parent;
    grandparent->parent = parent;
    grandparent->left = parent->right;
    parent->right = grandparent;
    if (grandparent->left != nullptr) //if we now have a left child, update its parent pointer
        grandparent->left->parent = grandparent;
    if (parent->parent == nullptr)//if we're the root, update the root!
        root = parent;
    else if (parent->parent->left == parent)
        parent->parent->left = parent;
    else
        parent->parent->right = parent;
}

template <class T>
void RBT<T>::singleCCR(RBTNode<T>*& point){
    RBTNode<T>* grandparent = point;
    RBTNode<T>* parent = point->right;
    parent->parent = grandparent->parent;
    grandparent->parent = parent;
    grandparent->right = parent->left;
    parent->left = grandparent;
    if (grandparent->right != nullptr) //if we now have a right child, update its parent pointer
        grandparent->right->parent = grandparent;
    if (parent->parent == nullptr)//if we were the root, update the root!
        root = parent;
    else if (parent->parent->right == parent)
        parent->parent->right = parent;
    else
        parent->parent->left = parent;
}

template <class T>
void RBT<T>:: recolor(RBTNode<T>*& point){
    RBTNode<T>* parentPtr = nullptr;
    RBTNode<T>* grandparent = nullptr;
    
    while (point!=root && point->parent->color == 'R'){
        parentPtr=point->parent;
        grandparent=point->parent->parent;
        
        if (parentPtr==grandparent->left){
            RBTNode<T>* uncle = grandparent->right;
//            Case 1: uncle is read. Only recoloring is needed
            if (uncle!=nullptr && uncle->color == 'R'){
                grandparent->color='R';
                parentPtr->color='B';
                uncle->color='B';
                point=grandparent;
            }
            else{
//               Case 2: point is parent's right child. Left rotation/CCR needed
                if(point == parentPtr->right){
                    singleCCR(parentPtr);
                    point=parentPtr;
                    parentPtr=point->parent;
                }
//                Case 3: point is parent's left child. Add on right rotation
                singleCR(grandparent);
                swap(parentPtr->color, grandparent->color);
                point=parentPtr;
            }
        }
        else{
            RBTNode<T>* uncle = grandparent->left;
            if(uncle!=nullptr&&uncle->color=='R'){
                grandparent->color='R';
                parentPtr->color='B';
                uncle->color='B';
                point=grandparent;
            }
            else{
                if(point==parentPtr->left){
                    singleCR(parentPtr);
                    point=parentPtr;
                    parentPtr=point->parent;
                }
                singleCCR(grandparent);
                swap(parentPtr->color, grandparent->color);
                point=parentPtr;
            }
        }
    }
    root->color='B';
}

template <class T>
RBT<T>& RBT<T>::operator=(const RBT<T>& rhs){
    if (this == &rhs)
        return *this;
    root = recursiveCopy(rhs.root);
    return *this;
}

template <class T>
void RBT<T>::insert(const T& toInsert){
    if (root == nullptr){
        root = new RBTNode<T>(toInsert);
        root->color='B';
    }
    else{
        RBTNode<T>* temp = root;
        RBTNode<T>* prev = temp;
        while (temp != nullptr){
            prev = temp;
            if (toInsert < temp->data)
                temp = temp->left;
            else
                temp = temp->right;
        }
        if (toInsert < prev->data){
            prev->left = new RBTNode<T>(toInsert, prev);
            recolor(prev->left);
        }
        else{
            prev->right = new RBTNode<T>(toInsert, prev);
            recolor(prev->right);
        }
//        recolor(prev);
    }
}

int main(){
    RBT<int> b;
    srand(unsigned(time(NULL)));
    for (int i = 0; i < 100; i++)
        b.insert(rand() % 1000);
    
    b.printLevelOrder();
    cout << "Got here!" << endl;
    cout << "Got here #2" << endl;
}
