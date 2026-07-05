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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> nodes;
        queue<pair<TreeNode*,pair<int,int>>> todo;
        if(root==nullptr){
            return {};
        }
        todo.push({root,{0,0}});
        while(!todo.empty()){
            auto p=todo.front();
            todo.pop();
            TreeNode* temp=p.first;
            int x=p.second.first;  
            int y=p.second.second; 
            nodes[x][y].insert(temp->val);
            if(temp->left!=nullptr){
                todo.push({temp->left,{x-1,y+1}});
            }
            if(temp->right!=nullptr){
                todo.push({temp->right,{x+1,y+1}});
            }
        }
        vector<vector<int>> res;
        for(auto p:nodes){
            vector<int> col;
            for(auto q:p.second){
                col.insert(col.end(),q.second.begin(),q.second.end());
            }
            res.push_back(col);
        }
        return res;
    }
};
int main(){
    Solution* sol=new Solution();
    TreeNode* root=new TreeNode(3);
    root->left=new TreeNode(9);
    root->right=new TreeNode(20);
    root->right->left=new TreeNode(15);
    root->right->right=new TreeNode(7);
    vector<vector<int>> res=sol->verticalTraversal(root);
    for(const auto& col:res){
        for(int x:col){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root;
    delete sol;
    return 0;
}

// Problem: vertical order traversal of BT