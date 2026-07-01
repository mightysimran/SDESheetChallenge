#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()){
            return false;
        }
        int count[26]={0};
        for(int i=0;i<s.length();i++){
            count[s[i]-'a']++;
            count[t[i]-'a']--;
        }
        for(int i=0;i<26;i++){
            if(count[i]!=0){
                return false;
            }
        }
        return true;
    }
};
int main(){
    Solution* sol=new Solution();
    string s="anagram";
    string t="nagaram";
    if(sol->isAnagram(s,t)){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
    delete sol;
    return 0;
}

// Problem: valid anagram