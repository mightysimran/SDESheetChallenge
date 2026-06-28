#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int efc(string& s,int left,int right){
        while(left>=0&&right<s.length()&&s[left]==s[right]){
            left--;
            right++;
        }
        return right-left-1;
    }
public:
    string longestPalindrome(string s) {
        if(s.empty()){
            return "";
        }
        int start=0,end=0;
        for(int i=0;i<s.length();i++){
            int len1=efc(s,i,i);
            int len2=efc(s,i,i+1);
            int maxLen=max(len1,len2);
            if(maxLen>(end-start+1)){
                start=i-(maxLen-1)/2;
                end=i+maxLen/2;
            }
        }
        return s.substr(start,end-start+1);
    }
};
int main(){
    Solution* sol=new Solution();
    string s="babad";
    cout<<sol->longestPalindrome(s);
    delete sol;
    return 0;
}

// Problem: longest palindromic substring