#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int data1,Node* next1){
        data=data1;
        next=next1;
    }
    Node(int data1) {
        data=data1;
        next=nullptr;
    }
};

class Solution {
public:
    void printLL(Node* head) {
        while (head!=NULL) {
            cout<<head->data<<" ";
            head=head->next;
        }
    }
    Node* deleteNthNodeFromEnd(Node* head,int n) {
        Node* ph = new Node(0, head);
        Node* slow = ph;
        Node* fast = ph;
        for (int i=0;i<=n;i++) {
            fast=fast->next;
        }
        while (fast!=NULL) {
            slow=slow->next;
            fast=fast->next;
        }
        slow->next=slow->next->next;
        return ph->next;
    }
};

int main() {
    vector<int> arr={1,2,3,4,5};
    int n=3;
    Node* head=new Node(arr[0]);
    head->next=new Node(arr[1]);
    head->next->next=new Node(arr[2]);
    head->next->next->next=new Node(arr[3]);
    head->next->next->next->next=new Node(arr[4]);
    Solution sol;
    head = sol.deleteNthNodeFromEnd(head,n);
    sol.printLL(head);
}

// Problem: remove nth node from the back of LL