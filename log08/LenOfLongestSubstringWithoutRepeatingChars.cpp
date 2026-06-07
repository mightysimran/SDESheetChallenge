#include <bits/stdc++.h>
using namespace std;

int LenOfLongestSubstringWithoutRepeatingChars(string& s){
        int n=s.size();
        // all ASCII characters
        int HashLen = 256; 
        int hash[HashLen]; 
        for (int i=0;i<HashLen;i++){
            hash[i]=-1;
        }

        int l=0,r=0,maxLen=0;
        while(r<n){
            if(hash[s[r]]!=-1){
                l=max(hash[s[r]]+1,l);
            }
            int len=r-l+1;
            maxLen=max(len,maxLen);
            hash[s[r]]=r;
            r++;
        }
        return maxLen;
    }

int main() {
    string s="cadbzabcd"; 
    cout<<"The maximum length is: ";
    cout<<LenOfLongestSubstringWithoutRepeatingChars(s);
    return 0;
}

// Problem: length of longest substring without repeating characters
