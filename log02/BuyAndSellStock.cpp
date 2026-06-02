#include <bits/stdc++.h>
using namespace std;

int maxprofit(vector<int>& prices){
    int mn=prices[0],n=prices.size();
    int mxpft=0;
    for(int i=0;i<n;i++){
        int cost=prices[i]-mn;
        mxpft=max(mxpft,cost);
        mn=min(mn,prices[i]);
    }
    return mxpft;
}

int main()
{
    vector<int> v={7,1,5,3,6,4};
    cout<<maxprofit(v);
    return 0;
}