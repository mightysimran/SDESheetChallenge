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

class Solution {
public:
    bool detectLoop(Node* head){
        Node* temp=head;
        unordered_map<Node*,int> nodeMap;
        while(temp!=nullptr){
            if(nodeMap.find(temp)!=nodeMap.end()){
                return true;
            }
            nodeMap[temp]=1;
            temp=temp->next;
        }
        return false;
    }
};

int main() {
    Node* head=new Node(1);
    Node* second=new Node(2);
    Node* third=new Node(3);
    Node* fourth=new Node(4);
    Node* fifth=new Node(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    // create a loop for testing
    fifth->next = third;

    Solution sol;
    if(sol.detectLoop(head)){
        cout<<"Loop detected in the LL"<<endl;
    }
    else{
        cout<<"No loop detected in the LL"<<endl;
    }

    delete head;
    delete second;
    delete third;
    delete fourth;
    delete fifth;

    return 0;
}

// Problem: detect loop/cycle in LL