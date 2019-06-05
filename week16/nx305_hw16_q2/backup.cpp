class queue{
    vector<T> vec;
public:
    queue(){};
    void push(T newElement) {vec.push_back(newElement);}
    void remove(int indexToRemove){vec.erase(vec.begin(),vec.begin()+indexToRemove);}
    vector<T> getVec()const {return vec;}
};

int main() {
    queue<int> v;
    for (int i=0;i<5;i++)
        v.push(i);
    
    for (int x: v.getVec())
        cout<<x<<" "<<endl;
    
    v.remove(2);
    cout<<"After removal: "<<endl;
    for (int x: v.getVec())
        cout<<x<<" "<<endl;
    
}
