#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1,vector<int>& nums2){
        stack<int> st;
        unordered_map<int,int> next_greater;
        for(int i=nums2.size()-1;i>=0;i--){
            while(!st.empty()&&st.top()<=nums2[i]){
                st.pop();
            }
            if(st.empty()){
                next_greater[nums2[i]]=-1;
            } 
            else{
                next_greater[nums2[i]]=st.top();
            }
            st.push(nums2[i]);
        }
        vector<int> res;
        for(int num:nums1){
            res.push_back(next_greater[num]);
        }
        return res;
    }
};
int main(){
    Solution sol;
    vector<int> nums1={4,1,2};
    vector<int> nums2={1,3,4,2};
    vector<int> result=sol.nextGreaterElement(nums1,nums2);
    cout<<"Result: [";
    for(size_t i=0;i<result.size();i++){
        cout<<result[i]<<(i==result.size()-1?"":", ");
    }
    cout<<"]\n";
    return 0;
}

// Problem: next greater element