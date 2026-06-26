#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> nextSmallerElement(vector<int>& arr){
        int n=arr.size();
        vector<int> ans(n,-1);
        stack<int> st; 
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&st.top()>=arr[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i]=st.top();
            }
            st.push(arr[i]);
        }
        return ans;
    }
};
int main(){
    Solution sol;
    vector<int> arr={4,8,5,2,25};
    vector<int> result=sol.nextSmallerElement(arr);
    cout<<"Result: [";
    for(size_t i=0;i<result.size();++i){
        cout<<result[i]<<(i==result.size()-1?"":", ");
    }
    cout<<"]\n";
    return 0;
}

// Problem: next smaller element