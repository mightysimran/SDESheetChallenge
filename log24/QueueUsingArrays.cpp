#include<bits/stdc++.h>
using namespace std;

class myQueue {
private:
    int* arr;
    int start;
    int end;
    int currLen;
    int maxLen;
public:
    myQueue(int n):maxLen(n),start(-1),end(-1),currLen(0),arr(new int[n]){}
    ~myQueue(){
        delete[] arr;
    }
    bool isEmpty(){
        return currLen==0;
    }
    bool isFull(){
        return currLen==maxLen;
    }
    void enqueue(int x){
        if(isFull()){
            return;
        }
        if(isEmpty()){
            start=0;
            end=0;
        }
        else{
            end=(end+1)%maxLen;
        }
        arr[end]=x;
        currLen++;
    }
    void dequeue(){
        if(isEmpty()){
            return;
        }
        if(currLen==1){
            start=-1;
            end=-1;
        }
        else{
            start=(start+1)%maxLen;
        }
        currLen--;
    }
    int getFront(){
        return isEmpty()?-1:arr[start];
    }
    int getRear(){
        return isEmpty()?-1:arr[end];
    }
};
int main(){
    myQueue q(3);
    cout<<"Empty: "<<q.isEmpty()<<"\n";
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout<<"Full: "<<q.isFull()<<"\n";
    cout<<"Front: "<<q.getFront()<<"\n";
    cout<<"Rear: "<<q.getRear()<<"\n";
    q.dequeue();
    cout<<"New Front: "<<q.getFront()<<"\n";
    return 0;
}

// Problem: queue using arrays
