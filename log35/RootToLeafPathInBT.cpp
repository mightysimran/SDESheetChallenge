#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data=val;
        left=nullptr;
        right=nullptr;
    }
};
class Solution {
private:
    void helper(Node* root,vector<int>& currentPath,vector<vector<int>>& allPaths) {
        if(root==nullptr){
            return;
        }
        currentPath.push_back(root->data);
        if(root->left==nullptr&&root->right==nullptr){
            allPaths.push_back(currentPath);
        } 
        else{
            helper(root->left,currentPath,allPaths);
            helper(root->right,currentPath,allPaths);
        }
        currentPath.pop_back();
    }
public:
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> allPaths;
        vector<int> currentPath;
        helper(root,currentPath,allPaths);
        return allPaths;
    }
};
int main(){
    Solution* sol=new Solution();
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    vector<vector<int>> result=sol->Paths(root);
    for(const auto& path:result){
        for(int x:path){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
    delete root->right->left;
    delete root->left->right;
    delete root->right;
    delete root->left;
    delete root;
    delete sol;
    return 0;
}

// Problem: root to leaf path in BT