// tabulation method

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumCoins(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i<=amount;i++) {
            for(int coin:coins) {
                if(i-coin>=0&&dp[i-coin]!=INT_MAX) {
                    dp[i]=min(dp[i],1+dp[i-coin]);
                }
            }
        }
        return dp[amount]==INT_MAX?-1:dp[amount];
    }
};
int main() {
    vector<int> coins={1,2,5};
    int amount=11;
    Solution sol;
    cout<<sol.minimumCoins(coins,amount)<<endl;
    return 0;
}

// Problem: minimum coins