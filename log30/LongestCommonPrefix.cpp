#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()){
            return "";
        }
        sort(strs.begin(),strs.end());
        string first=strs.front();
        string last=strs.back();
        string res="";
        for(int i=0;i<first.length();i++){
            if(first[i]==last[i]){
                res+=first[i];
            }
            else{
                break;
            }
        }
        return res;
    }
};
int main(){
    Solution* sol=new Solution();
    vector<string> strs={"flower","flow","flight"};
    cout<<sol->longestCommonPrefix(strs);
    delete sol;
    return 0;
}

// Problem: longest common prefix