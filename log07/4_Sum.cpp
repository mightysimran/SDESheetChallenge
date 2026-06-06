#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> solve4Sum(vector<int>& nums,int target) {
    int n=nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(),nums.end());
    for(int i=0;i<n;i++){
        if(i>0&&nums[i]==nums[i-1]){
            continue;
        }
        for(int j=i+1;j<n;j++) {
            if(j>(i+1)&&nums[j]==nums[j-1]){
                continue;
            }
            int k=j+1;
            int l=n-1;
            
            while(k<l) {
                long long sum=nums[i];
                sum+=nums[j];
                sum+=nums[k];
                sum+=nums[l];
                
                if(sum==target){
                    vector<int> temp={nums[i],nums[j],nums[k],nums[l]};
                    ans.push_back(temp);
                    k++; 
                    l--;
                    while(k<l&&nums[k]==nums[k-1]) k++;
                    while(k<l&&nums[l]==nums[l+1]) l--;
                }
                else if(sum < target){
                    k++;
                }
                else{
                    l--;
                }
            }
        }
    }
    return ans;
}

int main() {
    // Test Case 1
    vector<int> nums1 = {1,0,-1,0,-2,2};
    int target1=0;
    cout<<"Test Case 1 Output:"<<endl;
    vector<vector<int>> result1=solve4Sum(nums1,target1);
    for(auto quad:result1){
        cout<<"[";
        for(int i=0;i<quad.size();i++){
            cout<<quad[i]<<(i<quad.size()-1?", ":"");
        }
        cout<<"]"<<endl;
    }
    cout<<endl;

    // Test Case 2 (with repetition)
    vector<int> nums2={2,2,2,2,2};
    int target2=8;
    
    cout<<"Test Case 2 Output:"<<endl;
    vector<vector<int>> result2=solve4Sum(nums2,target2);
    for(auto quad:result2){
        cout<<"[";
        for(int i=0;i<quad.size();i++) {
            cout<<quad[i]<<(i<quad.size()-1?", ":"");
        }
        cout<<"]"<<endl;
    }
    return 0;
}

// Problem: 4 sum