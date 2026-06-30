#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()){
            return 0;
        }
        int m=needle.length();
        int n=haystack.length();
        vector<int> lps(m,0);
        int len=0; 
        int i=1;
        while(i<m){
            if(needle[i]==needle[len]){
                len++;
                lps[i]=len;
                i++;
            } 
            else{
                if(len!=0){
                    len=lps[len-1]; 
                } 
                else{
                    lps[i]=0;
                    i++;
                }
            }
        }
        int haystack_idx=0; 
        int needle_idx=0; 
        while(haystack_idx<n){
            if(haystack[haystack_idx]==needle[needle_idx]){
                haystack_idx++;
                needle_idx++;
            }
            if(needle_idx==m){
                return haystack_idx-m; 
            }
            else if(haystack_idx<n&&haystack[haystack_idx]!=needle[needle_idx]){
                if(needle_idx!=0){
                    needle_idx=lps[needle_idx-1]; 
                } 
                else{
                    haystack_idx++;
                }
            }
        }
        return -1; 
    }
};
int main(){
    Solution* sol=new Solution();
    string haystack="sadbutsad";
    string needle="sad";
    cout<<sol->strStr(haystack,needle);
    delete sol;
    return 0;
}

// Problem: find the index of the first occurence in a string (KMP algorithm or LPS array)