// optimal

#include<bits/stdc++.h>
using namespace std;

bool search_matrix(vector<vector<int>>& mat,int target){
    int n=mat.size();
    if(n==0){
        return false;
    }
    int m=mat[0].size();
    int low=0,high=n*m-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        int row=mid/m;
        int col=mid%m;
        if(mat[row][col]==target){
            return true;
        }
        else if(mat[row][col]<target){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return false;
}

int main(){
    vector<vector<int>> mat={{1,2,3},{4,5,6},{7,8,9}};
    int x=4;
    if(search_matrix(mat,x)){
        cout<<"found.";
    }
    else{
        cout<<"not found.";
    }
}

// Problem: search in 2D matrix