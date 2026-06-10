#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1,ListNode* l2){
        ListNode *ph=new ListNode(); 
        ListNode *temp=ph; 
        int carry=0;
        while((l1!=NULL||l2!=NULL)||carry){
            int sum=0; 
            if(l1!=NULL) {
                sum+=l1->val; 
                l1=l1 -> next; 
            }
            if(l2!=NULL) {
                sum+=l2->val; 
                l2=l2->next; 
            }
            sum+=carry; 
            carry=sum/10; 
            ListNode *node=new ListNode(sum%10); 
            temp->next=node; 
            temp=temp->next; 
        }
        return ph->next; 
    }
};
ListNode* createLL(vector<int>& arr) {
    ListNode *head=new ListNode(arr[0]);
    ListNode *temp=head;
    for (int i=1;i<arr.size();i++) {
        temp->next=new ListNode(arr[i]);
        temp=temp->next;
    }
    return head;
}

void printLL(ListNode* head) {
    while(head){
        cout<<head->val;
        if(head->next) cout << " -> ";
        head=head->next;
    }
    cout<<endl;
}

int main() {
    vector num1 = {2, 4, 3}; // represents 342
    vector num2 = {5, 6, 4}; // represents 465
    ListNode* l1 = createLL(num1);
    ListNode* l2 = createLL(num2);
    Solution sol;
    ListNode* result=sol.addTwoNumbers(l1,l2);
    printLL(result); // 7 -> 0 -> 8
    return 0;
}

// Problem: add 2 numbers as LL