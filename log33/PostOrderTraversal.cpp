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
private:
    void f(TreeNode* root,vector<int>& arr) {
        if(root==nullptr){
            return;
        }
        f(root->left,arr);       
        f(root->right,arr);      
        arr.push_back(root->val); 
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> arr;
        f(root,arr);
        return arr;
    }
};
int main(){
    Solution* sol=new Solution();
    TreeNode* root=new TreeNode(1);
    root->right=new TreeNode(2);
    root->right->left=new TreeNode(3);
    vector<int> res=sol->postorderTraversal(root);
    for(int x:res){
        cout<<x<<" ";
    }
    delete root->right->left;
    delete root->right;
    delete root;
    delete sol;
    return 0;
}

// Problem: postorder traversal of BT