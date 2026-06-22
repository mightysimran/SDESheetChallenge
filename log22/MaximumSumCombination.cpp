#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    std::vector<int> maxCombinationSum(std::vector<int>& nums1,std::vector<int>& nums2,int k){
        int n=nums1.size();
        std::sort(nums1.begin(),nums1.end(),std::greater<int>());
        std::sort(nums2.begin(),nums2.end(),std::greater<int>());
        std::priority_queue<std::pair<int,std::pair<int,int>>> maxHeap;
        std::set<std::pair<int,int>> visited;
        maxHeap.push({nums1[0]+nums2[0],{0,0}});
        visited.insert({0,0});
        std::vector<int> result;
        while(k>0&&!maxHeap.empty()){
            auto top=maxHeap.top();
            maxHeap.pop();
            int currentSum=top.first;
            int i=top.second.first;
            int j=top.second.second;
            result.push_back(currentSum);
            k--;
            if(i+1<n&&visited.find({i+1,j})==visited.end()){
                maxHeap.push({nums1[i+1]+nums2[j],{i+1,j}});
                visited.insert({i+1,j});
            }
            if(j+1<n&&visited.find({i,j+1})==visited.end()){
                maxHeap.push({nums1[i]+nums2[j+1],{i,j+1}});
                visited.insert({i,j+1});
            }
        }
        return result;
    }
};
int main(){
    Solution sol;
    std::vector<int> nums1_ex1={7,3};
    std::vector<int> nums2_ex1={1,6};
    int k1=2;
    std::vector<int> res1=sol.maxCombinationSum(nums1_ex1,nums2_ex1,k1);
    std::cout<<"Example 1 Output: [";
    for(size_t i=0;i<res1.size();++i){
        std::cout<<res1[i]<<(i==res1.size()-1?"":", ");
    }
    std::cout<<"]\n";
    std::vector<int> nums1_ex2={3,4,5};
    std::vector<int> nums2_ex2={2,6,3};
    int k2=2;
    std::vector<int> res2=sol.maxCombinationSum(nums1_ex2,nums2_ex2,k2);
    std::cout<<"Example 2 Output: [";
    for(size_t i=0;i<res2.size();++i){
        std::cout<<res2[i]<<(i==res2.size()-1?"":", ");
    }
    std::cout<<"]\n";
    return 0;
}

// Problem: maximum sum combination