#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrack(vector<int>& nums, vector<bool>& used, vector<int>& current, vector<vector<int>>& result) {
        if(current.size()==nums.size()){
            result.push_back(current);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(used[i]){
                continue;
            }
            used[i]=true;
            current.push_back(nums[i]);
            backtrack(nums,used,current,result);
            current.pop_back();
            used[i]=false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        vector<bool> used(nums.size(),false);
        backtrack(nums,used,current,result);
        return result;
    }
};
int main() {
    vector<int> nums={1,2,3};
    Solution sol;
    vector<vector<int>> permutations=sol.permute(nums);
    for(auto& perm:permutations){
        for(int num:perm) {
            cout<<num<<" ";
        }
        cout<<"\n";
    }
    return 0;
}

// Problem: permutations of a string