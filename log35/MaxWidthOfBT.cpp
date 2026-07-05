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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root){
            return 0;
        }
        int maxWidth=0;
        queue<pair<TreeNode*,unsigned long long>> q;
        q.push({root,0});
        while(!q.empty()){
            int size=q.size();
            unsigned long long minIndex=q.front().second;
            unsigned long long first=0,last=0;
            for(int i=0;i<size;i++){
                unsigned long long currIndex=q.front().second-minIndex;
                TreeNode* node=q.front().first;
                q.pop();
                if(i==0){
                    first=currIndex;
                }
                if(i==size-1){
                    last=currIndex;
                }
                if(node->left){
                    q.push({node->left,2*currIndex+1});
                }
                if(node->right){
                    q.push({node->right,2*currIndex+2});
                }
            }
            maxWidth=max(maxWidth,(int)(last-first+1));
        }
        return maxWidth;
    }
};
int main(){
    Solution* sol=new Solution();
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(3);
    root->right=new TreeNode(2);
    root->left->left=new TreeNode(5);
    root->left->right=new TreeNode(3);
    root->right->right=new TreeNode(9);
    cout<<sol->widthOfBinaryTree(root);
    delete root->right->right;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;
    delete sol;
    return 0;
}

// Problem: maximum width of a binary tree