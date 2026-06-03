// optimal 1

#include <bits/stdc++.h>
using namespace std;

void merge(long long arr1[],long long arr2[],int n,int m) 
{
    int left=n-1;
    int right=0;
    while(left>=0&&right<m) {
        if(arr1[left]>arr2[right]){
            swap(arr1[left],arr2[right]);
            left--, right++;
        }
        else{
            break;
        }
    }
    sort(arr1,arr1+n);
    sort(arr2,arr2+m);
}

int main() {
    long long arr1[] = {1, 3, 5, 7};
    long long arr2[] = {0, 2, 6, 8, 9};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    int m = sizeof(arr2)/sizeof(arr2[0]);
    merge(arr1, arr2, n, m);
    for(int i=0;i<n;i++) cout<<arr1[i]<<" ";
    cout<<"\n";
    for(int i=0;i<m;i++) cout<<arr2[i]<<" ";
    return 0;
}

// Problem: merge sorted arrays without extra space