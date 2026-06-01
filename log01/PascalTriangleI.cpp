#include <bits/stdc++.h>
using namespace std;

long long find_nCr(long long n,long long r){
    long long res=1;
    for(int i=0;i<r;i++){
        res=res*(n-i);
        res/=(i+1);
    }
    return res;
}

int main()
{
    long long r=5,c=3;
    cout<<find_nCr(r-1,c-1);
    return 0;
}

// TC: r
// SC: 1