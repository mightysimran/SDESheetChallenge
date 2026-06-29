#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string s=a;
        int count=1;
        while(s.length()<b.length()){
            s+=a;
            count++;
        }
        if(rabinKarp(s,b)){
            return count;
        }
        s+=a;
        if(rabinKarp(s,b)){
            return count+1;
        }
        return -1;
    }
private:
    bool rabinKarp(string& text,string& pattern) {
        int n=text.length();
        int m=pattern.length();
        if(n<m){
            return false;
        }
        long long d=256; 
        long long q=1000000007; 
        long long p_hash=0; 
        long long t_hash=0; 
        long long h=1;
        for(int i=0;i<m-1;i++){
            h=(h*d)%q;
        }
        for(int i=0;i<m;i++){
            p_hash=(d*p_hash+pattern[i])%q;
            t_hash=(d*t_hash+text[i])%q;
        }
        for(int i=0;i<=n-m;i++){
            if(p_hash==t_hash){
                if(text.substr(i,m)==pattern){
                    return true; 
                }
            }
            if(i<n-m) {
                t_hash=(d*(t_hash-text[i]*h)+text[i+m])%q;
                if(t_hash<0){
                    t_hash=(t_hash+q); 
                }
            }
        }
        return false;
    }
};
int main(){
    Solution* sol=new Solution();
    string a="abcd";
    string b="cdabcdab";
    cout<<sol->repeatedStringMatch(a,b);
    delete sol;
    return 0;
}

// Problem: repeated string match (rabin karp algorithm)