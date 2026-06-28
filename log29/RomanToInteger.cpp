#include<bits/stdc++.h>
using namespace std;
class Solution {
private: 
    int getval(char c){
        switch(c){
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
            default:
                return 0;
        }
    }
public:
    int romanToInt(string s) {
        int res=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            int current=getval(s[i]);
            if(i<n-1&&current<getval(s[i+1])){
                res-=current;
            }
            else{
                res+=current;
            }
        }
        return res;
    }
};
int main(){
    Solution* sol=new Solution();
    string s="MCMXCIV";
    cout<<sol->romanToInt(s);
    delete sol;
    return 0;
}

// Problem: roman to integer 