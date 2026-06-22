#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(std::vector<int>& nums,int k){
        std::priority_queue<int,std::vector<int>,std::greater<int>> minHeap;
        for(int num:nums){
            minHeap.push(num);
            if(minHeap.size()>k){
                minHeap.pop();
            }
        }
        return minHeap.top();
    }
};
int main(){
    Solution sol;
    std::vector<int> nums1={1,2,3,4,5};
    int k1=2;
    std::cout<<"Example 1 Output: "<<sol.findKthLargest(nums1,k1)<<std::endl;
    std::vector<int> nums2={-5,4,1,2,-3};
    int k2=5;
    std::cout<<"Example 2 Output: "<<sol.findKthLargest(nums2,k2)<<std::endl;
    return 0;
}

// Problem: kth largest element in an array