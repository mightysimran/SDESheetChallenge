#include<bits/stdc++.h>
class Solution {
private:
    std::stack<std::pair<int,int>> st;
    int index;
public:
    Solution() {
        index=0;
    }
    int next(int price) {
        while(!st.empty()&&st.top().first<=price){
            st.pop();
        }
        int span;
        if(st.empty()){
            span=index+1;
        } 
        else{
            span=index-st.top().second;
        }
        st.push({price,index});
        index++;
        return span;
    }
};
int main(){
    Solution* sol=new Solution();
    std::vector<int> prices={100,80,60,70,60,75,85};
    for(int price:prices){
        std::cout<<sol->next(price)<<" ";
    }
    delete sol;
    return 0;
}

// Problem: stock span problem