#include<bits/stdc++.h>
using namespace std;

class myStack {
private:
    int* arr;
    int topIndex;
    int capacity;
public:
    myStack(int n):capacity(n),topIndex(-1),arr(new int[n]){}
    ~myStack(){
        delete[] arr;
    }
    bool isEmpty(){
        return topIndex==-1;
    }
    bool isFull(){
        return topIndex==capacity-1;
    }
    void push(int x){
        if(!isFull()){
            arr[++topIndex]=x;
        }
    }
    void pop(){
        if(!isEmpty()){
            topIndex--;
        }
    }
    int peek(){
        return isEmpty()?-1:arr[topIndex];
    }
};
int main(){
    myStack st(3);
    cout<<"Empty: "<<st.isEmpty()<<"\n";
    st.push(10);
    st.push(20);
    cout<<"Top: "<<st.peek()<<"\n";
    st.pop();
    cout<<"Top: "<<st.peek()<<"\n";
    return 0;
}

// Problem: stacks using arrays