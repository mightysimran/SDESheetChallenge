#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int myAtoi(string s) {
        int i=0,res=0;
        int n=s.length();
        int sign=1;
        while(i<n&&s[i]==' '){
            i++;
        }
        if(i<n&&(s[i]=='+'||s[i]=='-')){
            sign=(s[i]=='-')?-1:1;
            i++;
        }
        while(i<n&&s[i]>='0'&&s[i]<='9'){
            int digit=s[i]-'0';
            if(res>INT_MAX/10||(res==INT_MAX/10&&digit>INT_MAX%10)){
                return (sign==1)?INT_MAX:INT_MIN;
            }
            res=res*10+digit;
            i++;
        }
        return res*(sign);
    }
};
int main(){
    Solution* sol=new Solution();
    string s="   -42";
    cout<<sol->myAtoi(s);
    delete sol;
    return 0;
}

// Problem: string to integer (atoi)