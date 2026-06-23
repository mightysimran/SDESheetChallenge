#include<bits/stdc++.h>
using namespace std;

struct HeapNode {
    int value; // value
    int arrayIndex; // row
    int elementIndex; // index
    bool operator>(const HeapNode& other) const {
        return value>other.value;
    }
};
class Solution {
public:
    vector<int> mergeKSortedArrays(vector<vector<int>>& arr,int k){
        priority_queue<HeapNode,vector<HeapNode>,greater<HeapNode>> minHeap;
        vector<int> result;
        for(int i=0;i<k;++i){
            if(!arr[i].empty()){
                minHeap.push({arr[i][0],i,0});
            }
        }
        while(!minHeap.empty()){
            HeapNode current=minHeap.top();
            minHeap.pop();
            result.push_back(current.value);
            int nextElementIndex=current.elementIndex+1;
            if(nextElementIndex<arr[current.arrayIndex].size()){
                minHeap.push({arr[current.arrayIndex][nextElementIndex],current.arrayIndex,nextElementIndex});
            }
        }
        return result;
    }
};
int main(){
    Solution sol;
    vector<vector<int>> arr={
        {1,4,7},
        {2,5,8},
        {3,6,9}
    };
    int k=arr.size();
    vector<int> mergedArray=sol.mergeKSortedArrays(arr,k);
    cout<<"Merged Array: [";
    for(int i=0;i<mergedArray.size();++i){
        std::cout<<mergedArray[i]<<(i==mergedArray.size()-1?"":", ");
    }
    cout<<"]\n";
    return 0;
}

// Problem: merge k sorted arrays