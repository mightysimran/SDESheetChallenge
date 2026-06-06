// better (Hashing) 
// most optimal when we have to return the indices

#include<bits/stdc++.h>
using namespace std;

vector<int> solve2Sum(vector<int>& v,int target){
    int n=v.size();
    map<int,int> mpp;
    for(int i=0;i<n;i++){
        int num=v[i];
        int morereqd=target-num;
        if(mpp.find(morereqd)!=mpp.end()){
            // cout<<"YES\n";
            return{morereqd,num};
            break;
        }
        mpp[num]=i;
    }
    // cout<<"NO\n";
    return{-1,-1};
}

int main()
{
    int n,target;
    cin>>n>>target;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<int> res=solve2Sum(v,target);
    if(res[0]!=-1){
        cout<<res[0]<<" "<<res[1];
    }
    else{
        cout<<-1;
    }
    return 0;
}

// TC: n or nlogn
// Space: n
// Problem: 2 sum