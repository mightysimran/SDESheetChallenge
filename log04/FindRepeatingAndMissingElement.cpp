// optimal - math

#include <bits/stdc++.h>
using namespace std;

vector<int> f(vector<int> a){
    long long n=a.size();

    // SN: sum of first n natural numbers
    // S2N: sum of squares of first n natural numbers
    long long SN=(n*(n+1))/2;
    long long S2N=(n*(n+1)*(2*n+1))/6;
    long long S=0, S2=0;
    for(int i=0;i<n;i++){
        S+=a[i];
        S2+=(long long)a[i]*(long long)a[i];
    }
    long long val1=S-SN; // x-y
    long long val2=S2-S2N; // x^2-y^2
    val2=val2/val1; // x+y

    long long x=(val1+val2)/2;
    long long y=x-val1;

    return{(int)x,(int)y}; // x -> repeating, y -> missing
}

int main(){
    vector<int> a={3,1,2,5,3};
    cout<<f(a)[0]<<" "<<f(a)[1]; // f(a)[0] -> repeating, f(a)[1] -> missing
    return 0;
}

// Problem: find repeating and missing element