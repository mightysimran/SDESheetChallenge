#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countPlatforms(int n, int arr[], int dep[]) {
        sort(arr,arr+n);
        sort(dep,dep+n);
        int platforms=1;
        int result=1;
        int i=1,j=0;
        while(i<n&&j<n) {
            if(arr[i]<=dep[j]) {
                platforms++;
                i++;
            }else{
                platforms--;
                j++;
            }
            result=max(result,platforms);
        }
        return result;
    }
};
int main() {
    int arr[]={900,945,955,1100,1500,1800};
    int dep[]={920,1200,1130,1150,1900,2000};
    int n=sizeof(arr)/sizeof(arr[0]);
    Solution sol;
    cout<<"Minimum number of platforms required "<<sol.countPlatforms(n,arr,dep)<<endl;
    return 0;
}

// Problem: minimum number of platforms for a railway station