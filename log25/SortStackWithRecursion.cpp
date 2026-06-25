#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    void insertInSortedOrder(stack<int>& st,int element){
        if(st.empty()||st.top()<=element){
            st.push(element);
            return;
        }
        int topElement=st.top();
        st.pop();
        insertInSortedOrder(st,element);
        st.push(topElement);
    }
public:
    void sortStack(stack<int> &st){
        if(st.empty()){
            return;
        }
        int topElement=st.top();
        st.pop();
        sortStack(st);
        insertInSortedOrder(st,topElement);
    }
};
int main(){
    Solution solution;
    stack<int> st;
    st.push(5);
    st.push(-2);
    st.push(9);
    st.push(1);
    st.push(3);
    solution.sortStack(st);
    cout<<"Sorted Stack (top to bottom): ";
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<"\n";
    return 0;
}

// Problem: sort stack with recursion