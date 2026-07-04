#include<bits/stdc++.h>
using namespace std;
class Node {
  public:
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
  public:
    vector<int> topView(Node* root) {
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
            if(mpp.find(line)==mpp.end()){
                mpp[line]=node->data;
            }
            if(node->left!=nullptr) {
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
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->right=new Node(4);
    root->left->right->right=new Node(5);
    root->left->right->right->right=new Node(6);
    vector<int> res=sol->topView(root);
    for(int x:res){
        cout<<x<<" ";
    }
    delete root->left->right->right->right;
    delete root->left->right->right;
    delete root->left->right;
    delete root->right;
    delete root->left;
    delete root;
    delete sol;
    return 0;
}

// Problem: top view of BT