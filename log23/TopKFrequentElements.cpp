#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums,int k){
        unordered_map<int,int> counts;
        for(int num:nums){
            counts[num]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap;
        for(auto& [num,freq]:counts){
            minHeap.push({freq,num});
            if(minHeap.size()>k){
                minHeap.pop();
            }
        }
        vector<int> result;
        while(!minHeap.empty()){
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return result;
    }
};
int main(){
    Solution sol;
    vector<int> nums1={1,1,1,2,2,3};
    int k1=2;
    vector<int> result1=sol.topKFrequent(nums1,k1);
    cout<<"Test Case 1 Output: [";
    for(int i=0;i<result1.size();++i){
        cout<<result1[i]<<(i==result1.size()-1?"":", ");
    }
    cout<<"]\n";
    vector<int> nums2={4,4,4,4,2,2,9,9,9,1};
    int k2=3;
    vector<int> result2=sol.topKFrequent(nums2,k2);
    cout<<"Test Case 2 Output: [";
    for(int i=0;i<result2.size();++i){
        cout<<result2[i]<<(i==result2.size()-1?"":", ");
    }
    cout<<"]\n";
    return 0;
}

// Problem: top k frequent elements