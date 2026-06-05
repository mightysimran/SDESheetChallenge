// optimal

#include<bits/stdc++.h>
using namespace std;

double calc(double x,int n){
    double res=1.0;
    long long nn=n; 
    if(nn<0){
        nn=-1*nn;
    }
    while(nn!=0){
        // odd
        if(nn%2){
            res=x*res;
            nn--;
        }
        // even
        else{
            x=x*x;
            nn/=2;
        }
    }
    if(n<0){
        res=1.0/res;
    }
    return res;
}

int main(){
    double x; int n;
    cin>>x>>n; // x-> base, n-> exponent
    cout<<calc(x,n);
    return 0;
}

// Problem: pow(x,n)