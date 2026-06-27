#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        int n=mat.size();
        int top=0,down=n-1;
        while(top<down){
            if(mat[top][down]==1){
                top++;
            } 
            else{
                down--;
            }
        }
        for(int i=0;i<n;i++){
            if(i==top){
                continue;
            }
            if(mat[top][i]==1||mat[i][top]==0){
                return -1;
            }
        }
        return top;
    }
};
int main(){
    Solution* sol=new Solution();
    vector<vector<int>> mat={{0,1,0},{0,0,0},{0,1,0}};
    cout<<sol->celebrity(mat);
    delete sol;
    return 0;
}

// Problem: the celebrity problem