#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int val){
        this->val=val;
        this->next=NULL;
    }
};

ListNode* reverseLL(ListNode* head) {
    ListNode* prev=NULL;
    ListNode* curr=head;
    while(curr!=NULL) {
        ListNode* nextNode=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextNode;
    }
    return prev;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode* newHead = reverseLL(head);

    while(newHead!=NULL) {
        cout<<newHead->val<<" ";
        newHead=newHead->next;
    }
    cout<<endl;
    return 0;
}

// Problem: reverse a LL