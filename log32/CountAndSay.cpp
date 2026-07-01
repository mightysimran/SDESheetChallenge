#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string countAndSay(int n) {
        string res="1";
        for(int i=2;i<=n;i++){
            string nextres="";
            int len=res.length();
            int j=0;
            while(j<len){
                char cd=res[j];
                int count=0;
                while(j<len&&res[j]==cd){
                    count++;
                    j++;
                }
                nextres+=to_string(count)+cd;
            }
            res=nextres;
        }
        return res;
    }
};
int main(){
    Solution* sol=new Solution();
    int n=4;
    cout<<sol->countAndSay(n);
    delete sol;
    return 0;
}

// Problem: count and say