#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(int i,int j,const string &s) {
    while(i<j) {
        if(s[i]!=s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
int minCut(string s) {
    int n=s.size();
    vector<int> dp(n+1,0);
    dp[n]=0; 
    for(int i=n-1;i>=0;i--) {
        int minCost=INT_MAX;
        for(int j=i;j<n;j++) {
            if(isPalindrome(i,j,s)) {
                int cost=1+dp[j+1];
                minCost=min(minCost,cost);
            }
        }
        dp[i]=minCost;
    }
    return dp[0]-1;
}
int main() {
    string s="aab";
    cout<<"Minimum Cuts: "<<minCut(s)<<endl;
    return 0;
}

// Problem: palindrome partitioning 