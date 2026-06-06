// optimal

#include<bits/stdc++.h>
using namespace std;

int longestConsecutiveSequence(vector<int>& a){
    int n=a.size();
    if(n==0){
        return 0;
    }
    int longest=1;
    unordered_set<int> st;
    for(int i=0;i<n;i++){
        st.insert(a[i]);
    }
    // find longest consecutive sequence
    for(auto it:st){
        if(st.find(it-1)==st.end()){
            int cnt=1;
            int x=it;
            // increment and search for consecutive elements
            while(st.find(x+1)!=st.end()){
                x++; cnt++;
            }
            longest=max(longest,cnt);
        }
    }
    return longest;
}

int main(){
    vector<int> v={100,4,101,2,1,3};
    cout<<longestConsecutiveSequence(v);
}

// Problem: maximum consecutive sequence in an array