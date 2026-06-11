#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* groupPrev=dummy;
        while(true){
            ListNode* kth=getKthNode(groupPrev, k);
            if(!kth){
                break;
            }
            ListNode* groupNext=kth->next;
            ListNode* prev=groupNext;
            ListNode* curr=groupPrev->next;
            for(int i=0;i<k;i++){
                ListNode* temp=curr->next;
                curr->next=prev;
                prev=curr;
                curr=temp;
            }
            ListNode* temp=groupPrev->next;
            groupPrev->next=kth;
            groupPrev=temp;
        }
        return dummy->next;
    }
    ListNode* getKthNode(ListNode* curr, int k) {
        while (curr&&k>0) {
            curr=curr->next;
            k--;
        }
        return curr;
    }
};

int main() {
    Solution sol;

    // LL: 1->2->3->4->5
    ListNode* head=new ListNode(1);
    head->next=new ListNode(2);
    head->next->next=new ListNode(3);
    head->next->next->next=new ListNode(4);
    head->next->next->next->next=new ListNode(5);
    int k=2;
    ListNode* result = sol.reverseKGroup(head, k);
    while(result!=NULL){
        cout<<result->val<<" ";
        result=result->next;
    }
    cout<<endl;

    return 0;
}

// Problem: reverse LL in groups of size K