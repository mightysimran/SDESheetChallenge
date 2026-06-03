// optimal 2

#include <bits/stdc++.h>
using namespace std;

// helper function
void swapIfGreater(long long arr1[],long long arr2[],int ind1,int ind2){
    if (arr1[ind1]>arr2[ind2]){
        swap(arr1[ind1],arr2[ind2]);
    }
}

void merge(long long arr1[],long long arr2[],int n,int m){
    int len=(n+m);
    int gap=(len/2)+(len%2);
    while (gap>0) {
        int left=0;
        int right=left+gap;
        while(right<len) {
            // Case 1: arr1 and arr2
            if(left<n&&right>=n){
                swapIfGreater(arr1,arr2,left,right-n);
            }
            // Case 2: arr2 and arr2
            else if(left>=n){
                swapIfGreater(arr2,arr2,left-n,right-n);
            }
            // Case 3: arr1 and arr1
            else{
                swapIfGreater(arr1,arr1,left,right);
            }
            left++; 
            right++;
        }
        if(gap==1) break;
        gap=(gap/2)+(gap%2);
    }
}

int main() {
    long long arr1[] = {1, 3, 5, 7};
    long long arr2[] = {0, 2, 6, 8, 9};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);
    merge(arr1, arr2, n, m);
    for(int i=0;i<n;i++) cout<<arr1[i]<<" ";
    cout<<"\n";
    for(int i=0;i<m;i++) cout<<arr2[i]<<" ";
    return 0;
}

// Problem: merge sorted arrays without extra space