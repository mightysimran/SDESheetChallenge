#include<bits/stdc++.h>
using namespace std;

class MyQueue {
private:
    stack<int> input;
    stack<int> output;
    void shiftStacks(){
        if(output.empty()){
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }
    }
public:
    MyQueue(){
    }
    void push(int x){
        input.push(x);
    }
    int pop(){
        shiftStacks();
        int fE=output.top();
        output.pop();
        return fE;
    }
    int peek(){
        shiftStacks();
        return output.top();
    }
    bool empty(){
        return input.empty()&&output.empty();
    }
};
int main(){
    MyQueue* sol=new MyQueue();
    cout<<"Empty: "<<sol->empty()<<"\n";
    sol->push(10);
    sol->push(20);
    sol->push(30);
    cout<<"Front: "<<sol->peek()<<"\n";
    cout<<"Popped: "<<sol->pop()<<"\n";
    cout<<"Front: "<<sol->peek()<<"\n";
    cout<<"Empty: "<<sol->empty()<<"\n";
    delete sol;
    return 0;
}

// Problem: queue using stack