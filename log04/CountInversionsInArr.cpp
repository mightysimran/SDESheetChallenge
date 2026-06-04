// optimal - modified merge sort

#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> &arr,int low,int mid,int high) {
    vector<int> temp;
    int left=low;
    int right=mid+1;
    int cnt=0;
    // merge elements in sorted order and count inversions
    while (left<=mid&&right<=high){
        if (arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        } 
        else{
            temp.push_back(arr[right]);
            cnt+=(mid-left+1); // all remaining left elements are inversions
            right++;
        }
    }
    // if left half still remains
    while (left<=mid) {
        temp.push_back(arr[left]);
        left++;
    }
    // if right half still remains
    while(right<=high) {
        temp.push_back(arr[right]);
        right++;
    }
    for(int i=low;i<=high;i++) {
        arr[i] = temp[i-low];
    }
    return cnt;
}

int mergeSort(vector<int> &arr,int low,int high) {
    int cnt=0;
    if (low>=high){
        return cnt;
    }
    int mid=(low + high)/2;
    cnt += mergeSort(arr,low,mid);
    cnt += mergeSort(arr,mid+1,high);
    cnt += merge(arr,low,mid,high);
    return cnt;
}

int inversionsCount(vector<int>& a,int n) {
    return mergeSort(a,0,n-1);
}

int main() {
    vector<int> a = {5,4,3,2,1};
    int n = a.size();
    cout<<inversionsCount(a,n);
    return 0;
}

// Problem: count inversions in an array (pre req: merge sort)