#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data=val;
        left=right=nullptr;
    }
};
class Solution {
  public:
    vector<int> bottomView(Node* root) {
        vector<int> res;
        if(root==nullptr){
            return res;
        }
        map<int,int> mpp;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            auto i=q.front();
            q.pop();
            Node* node=i.first;
            int line=i.second;
            mpp[line]=node->data;
            if(node->left!=nullptr){
                q.push({node->left,line-1});
            }
            if(node->right!=nullptr){
                q.push({node->right,line+1});
            }
        }
        for(auto i:mpp){
            res.push_back(i.second);
        }
        return res;
    }
};
int main(){
    Solution* sol=new Solution();
    Node* root=new Node(20);
    root->left=new Node(8);
    root->right=new Node(22);
    root->left->left=new Node(5);
    root->left->right=new Node(3);
    root->right->right=new Node(25);
    root->left->right->left=new Node(10);
    root->left->right->right=new Node(14);
    vector<int> res=sol->bottomView(root);
    for(int x:res){
        cout<<x<<" ";
    }
    delete root->left->right->right;
    delete root->left->right->left;
    delete root->right->right;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;
    delete sol;
    return 0;
}

// Problem: bottom view of BT