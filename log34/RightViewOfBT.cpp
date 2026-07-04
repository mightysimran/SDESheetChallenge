#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
    TreeNode(int x,TreeNode* left,TreeNode* right):val(x),left(left),right(right){}
};
class Solution {
public:
    void rightDFS(TreeNode* node,int level,vector<int>& res) {
        if(!node){
            return;
        }
        if(res.size()==level){
            res.push_back(node->val);
        }
        rightDFS(node->right,level+1,res);
        rightDFS(node->left,level+1,res);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        rightDFS(root,0,res);
        return res;
    }
};
int main(){
    Solution* sol=new Solution();
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->right=new TreeNode(5);
    root->right->right=new TreeNode(4);
    vector<int> res=sol->rightSideView(root);
    for(int x:res){
        cout<<x<<" ";
    }
    delete root->left->right;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;
    delete sol;
    return 0;
}

// Problem: right/left view of BT