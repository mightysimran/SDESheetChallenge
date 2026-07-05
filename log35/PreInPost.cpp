#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};
struct TraversalResult {
    vector<int> preorder;
    vector<int> inorder;
    vector<int> postorder;
};
class Solution {
public:
    TraversalResult preInPostTraversal(TreeNode* root) {
        TraversalResult result;
        if(root==nullptr){
            return result;
        }
        stack<pair<TreeNode*,int>> st;
        st.push({root,1});
        while(!st.empty()){
            auto& current=st.top();
            TreeNode* node=current.first;
            int state=current.second;
            if(state==1){
                result.preorder.push_back(node->val);
                st.top().second++; 
                if(node->left!=nullptr){
                    st.push({node->left,1});
                }
            }
            else if(state==2){
                result.inorder.push_back(node->val);
                st.top().second++; 
                if(node->right!=nullptr){
                    st.push({node->right,1});
                }
            }
            else{
                result.postorder.push_back(node->val);
                st.pop(); 
            }
        }
        return result;
    }
};
int main(){
    Solution* sol=new Solution();
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    TraversalResult res=sol->preInPostTraversal(root);
    for(int num:res.preorder){
        cout<<num<<" ";
    }
    cout<<"\n";
    for(int num:res.inorder){
        cout<<num<<" ";
    }
    cout<<"\n";
    for(int num:res.postorder){
        cout<<num<<" ";
    }
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;
    delete sol;
    return 0;
}
// Problem: pre, in, post order of BT in a single traversal