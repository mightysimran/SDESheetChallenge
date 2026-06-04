// optimal - Floyd's Tortoise and Hare (Cycle Detection) Algorithm

#include <bits/stdc++.h>
using namespace std;

int f(vector<int>& nums){
    int slow=nums[0];
    int fast=nums[0];
    // phase 1: finding intersection point in the cycle
    do{
        slow=nums[slow];
        fast=nums[nums[fast]];
    }while(slow!=fast);

    // phase 2: finding entrace to the cycle (the duplicate)
    fast=nums[0];
    while(slow!=fast){
        slow=nums[slow];
        fast=nums[fast];
    }
    return slow;
}

int main(){
    vector<int> v={1,4,2,3,4};
    cout<<f(v);
    return 0;
}

// Problem: find duplicate element
// note: values strictly ranging between 1 and n for a size n + 1 array.