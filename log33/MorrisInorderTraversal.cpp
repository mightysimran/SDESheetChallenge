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
    vector<int> inorderTraversal(TreeNode* root) { 
        vector<int> inorder;
        TreeNode* cur=root;
        while(cur!=nullptr){
            if(cur->left==nullptr){
                inorder.push_back(cur->val);
                cur=cur->right;
            } 
            else{
                TreeNode* prev=cur->left;
                while(prev->right&&prev->right!=cur){
                    prev=prev->right;
                }
                if(prev->right==nullptr){
                    prev->right=cur; 
                    cur=cur->left;
                } 
                else{
                    prev->right=nullptr; 
                    inorder.push_back(cur->val);
                    cur=cur->right;
                }
            }
        }
        return inorder;
    }
};
int main(){
    Solution* sol=new Solution();
    TreeNode* root=new TreeNode(1);
    root->right=new TreeNode(2);
    root->right->left=new TreeNode(3);
    vector<int> res=sol->inorderTraversal(root);
    for(int x:res){
        cout<<x<<" ";
    }
    delete root->right->left;
    delete root->right;
    delete root;
    delete sol;
    return 0;
}

// Problem: morris inorder traversal of BT