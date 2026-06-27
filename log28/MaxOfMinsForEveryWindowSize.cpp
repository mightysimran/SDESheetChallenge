#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> maxOfMins(vector<int>& arr) {
        int n=arr.size();
        vector<int> res(n+1,0);
        stack<int> st;
        for(int i=0;i<=n;i++){
            while(!st.empty()&&(i==n||arr[st.top()]>=arr[i])){
                int val=arr[st.top()];
                st.pop();
                int left=st.empty()?-1:st.top();
                int right=i;
                int len=right-left-1;
                res[len]=max(res[len],val);
            }
            st.push(i);
        }
        for(int i=n-1;i>=1;i--){
            res[i]=max(res[i],res[i+1]);
        }
        res.erase(res.begin());
        return res;
    }
};
int main(){
    Solution* sol=new Solution();
    vector<int> arr={10,20,30,50,10,70,30};
    vector<int> res=sol->maxOfMins(arr);
    for(int x:res){
        cout<<x<<" ";
    }
    delete sol;
    return 0;
}

// Problem: maximum of minimums for every window size