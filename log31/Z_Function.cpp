#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> search(string& pattern,string& text) {
        vector<int> result;
        if(pattern.empty()||text.empty()||pattern.length()>text.length()){
            return result;
        }
        string concat=pattern+"$"+text;
        int total_len=concat.length();
        int pattern_len=pattern.length();
        vector<int> z(total_len,0);
        int l=0,r=0;
        for(int i=1;i<total_len;i++){
            if(i<=r){
                int k=i-l;
                if(z[k]<r-i+1){
                    z[i]=z[k];
                } 
                else{
                    l=i;
                    while(r<total_len&&concat[r]==concat[r-l]){
                        r++;
                    }
                    z[i]=r-l;
                    r--;
                }
            } 
            else{
                l=i;
                r=i;
                while(r<total_len&&concat[r]==concat[r-l]){
                    r++;
                }
                z[i]=r-l;
                r--;
            }
        }
        for(int i=pattern_len+1;i<total_len;i++){
            if(z[i]==pattern_len){
                result.push_back(i-(pattern_len+1));
            }
        }
        return result;
    }
};
int main(){
    Solution* sol=new Solution();
    string text="batmanandrobinarebatmen";
    string pattern="bat";
    vector<int> res=sol->search(pattern,text);
    for(int idx:res){
        cout<<idx<<" ";
    }
    delete sol;
    return 0;
}

// Problem: Z-algorithm/function