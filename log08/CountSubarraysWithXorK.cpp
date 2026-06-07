#include<bits/stdc++.h>
using namespace std;

int countSubarraysWithXorK(vector<int> a,int k){
    int xr=0;
    map<int,int> mpp;
    mpp[xr]++; // initializing map with {0,1} for subarrays startin' from idx 0
    int cnt=0;
    for(int i=0;i<a.size();i++) {
        xr=xr^a[i]; // prefix XOR calculation
        int x=xr^k; // target formula: x=xr^k
        cnt+=mpp[x]; // add the frequency of prefix XORs found so far
        mpp[xr]++; // insert current prefix XOR into the map
    }
    return cnt;
}

int main() {
    vector<int> a={4,2,2,6,4};
    int k=6;
    int res = countSubarraysWithXorK(a,k);
    cout<<"Number of subarrays with XOR sum "<<k<< ": "<<res<<endl;
    return 0;
}

// Problem: count subarrays with XOR sum K