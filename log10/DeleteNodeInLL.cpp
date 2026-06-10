#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;              
    ListNode* next;       
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void del(ListNode* node){
        node->val=node->next->val;
        node->next=node->next->next;
    }
};

int main() {
    ListNode* head=new ListNode(4);
    head->next=new ListNode(5);
    head->next->next=new ListNode(1);
    head->next->next->next=new ListNode(9);
    Solution sol;
    sol.del(head->next);  
    ListNode* curr=head;
    while(curr){
        cout<<curr->val<<" ";
        curr=curr->next;
    }
    return 0;
}

// Problem: delete node in LL