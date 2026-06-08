#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data1, Node* next1) {
        data=data1;
        next=next1;
    }
    Node(int data1) {
        data=data1;
        next=nullptr;
    }
};

Node* merge2sortedLLs(Node* list1,Node* list2) {
    Node* anchor=new Node(-1);
    Node* temp=anchor;
    // traverse both lists simultaneously
    while (list1!=nullptr&&list2!=nullptr) {
        if (list1->data<=list2->data) {
            temp->next=list1;
            list1=list1->next;
        } 
        else{
            temp->next=list2;
            list2=list2->next;
        }
        temp = temp->next; 
    }
    if(list1!=nullptr){
        temp->next=list1;
    } 
    else{
        temp->next=list2;
    }
    return anchor->next;
}

void printLL(Node* head) {
    Node* temp=head;
    while(temp!=nullptr){
        cout << temp->data << " ";
        temp=temp->next; 
    }
    cout<<endl;
}

int main(){
    Node* list1=new Node(1);
    list1->next=new Node(3);
    list1->next->next=new Node(5);

    Node* list2=new Node(2);
    list2->next=new Node(4);
    list2->next->next=new Node(6);
    printLL(list1);
    printLL(list2);
    Node* mergedLL=merge2sortedLLs(list1,list2);
    printLL(mergedLL);
    return 0;
}

// Problem: merge 2 sorted LLs