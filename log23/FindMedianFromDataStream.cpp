#include<bits/stdc++.h>
using namespace std;

class MedianFinder {
private:
    priority_queue<int> maxHeap;
    priority_queue<int,vector<int>,greater<int>> minHeap;
public:
    MedianFinder(){
    }
    void addNum(int num){
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        if(minHeap.size()>maxHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    double findMedian(){
        if(maxHeap.size()==minHeap.size()){
            return (maxHeap.top()+minHeap.top())/2.0;
        }
        return maxHeap.top();
    }
};
int main(){
    MedianFinder* sol=new MedianFinder();
    vector<int> stream={5,15,1,3,2,8,7,9,10,6,11,4};
    cout<<fixed<<setprecision(1);
    for(int num:stream){
        sol->addNum(num);
        double median=sol->findMedian();
        cout<<"Added: "<<setw(2)<<num<<" | Current Median: "<<median<<"\n";
    }
    delete sol;
    return 0;
}

// Problem: find median from data stream