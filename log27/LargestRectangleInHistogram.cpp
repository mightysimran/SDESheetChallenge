#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights){
        int n=heights.size();
        stack<int> st;
        int maxA=0;
        for(int i=0;i<=n;i++){
            while(!st.empty()&&(i==n||heights[st.top()]>=heights[i])){
                int height=heights[st.top()];
                st.pop();
                int width=st.empty()?i:i-st.top()-1;
                maxA=max(maxA,height*width);
            }
            st.push(i);
        }
        return maxA;
    }
};
int main(){
    Solution sol;
    vector<int> heights1={2,1,5,6,2,3};
    vector<int> heights2={2,4};
    cout<<sol.largestRectangleArea(heights1)<<"\n";
    cout<<sol.largestRectangleArea(heights2)<<"\n";
    return 0;
}

// Problem: largest rectangle in histogram