#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        int n=s.size();
        int left=0;
        for(int i=0;i<n;i++){
            if(s[i]!=' '){
                if(left!=0){
                    s[left++]=' ';
                }
                int wordStart=left;
                while(i<n&&s[i]!=' '){
                    s[left++]=s[i++];
                }
                reverse(s.begin()+wordStart,s.begin()+left);
            }
        }
        s.erase(s.begin()+left,s.end());
        return s;
    }
};
int main(){
    Solution* sol=new Solution();
    string s="  hello world  ";
    cout<<"\""<<sol->reverseWords(s)<<"\"";
    delete sol;
    return 0;
}

// Problem: reverse every word in a string