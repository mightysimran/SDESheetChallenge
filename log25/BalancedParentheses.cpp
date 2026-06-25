#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s){
        stack<char> st;
        for(char c:s){
            if(c=='('||c=='{'||c=='['){
                st.push(c);
            } 
            else{
                if(st.empty()){
                    return false;
                }
                char top=st.top();
                st.pop();
                if((c==')'&&top!='(')||(c=='}'&&top!='{')||(c==']'&&top!='[')){
                    return false;
                }
            }
        }
        return st.empty();
    }
};
int main(){
    Solution sol;
    string s1="()[]{}";
    string s2="(]";
    string s3="([)]";
    string s4="{[]}";
    cout<<s1<<" : "<<sol.isValid(s1)<<"\n";
    cout<<s2<<" : "<<sol.isValid(s2)<<"\n";
    cout<<s3<<" : "<<sol.isValid(s3)<<"\n";
    cout<<s4<<" : "<<sol.isValid(s4)<<"\n";
    return 0;
}

// Problem: balanced parentheses