#include<bits/stdc++.h>
using namespace std;

class MyStack {
private:
    queue<int> q;
public:
    MyStack(){
    }
    void push(int x){
        int s=q.size();
        q.push(x);
        for(int i=0;i<s;i++){
            q.push(q.front());
            q.pop();
        }
    }
    int pop(){
        int tE=q.front();
        q.pop();
        return tE;
    }
    int top(){
        return q.front();
    }
    bool empty(){
        return q.empty();
    }
};
int main(){
    MyStack* sol=new MyStack();
    cout<<"Empty: "<<sol->empty()<<"\n";
    sol->push(10);
    sol->push(20);
    sol->push(30);
    cout<<"Top: "<<sol->top()<<"\n";
    cout<<"Popped: "<<sol->pop()<<"\n";
    cout<<"Top: "<<sol->top()<<"\n";
    cout<<"Empty: "<<sol->empty()<<"\n";
    delete sol;
    return 0;
}

// Problem: stack using queue 
