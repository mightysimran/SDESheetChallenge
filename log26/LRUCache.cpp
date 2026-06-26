#include<bits/stdc++.h>
using namespace std;

class LRUCache {
private:
    struct Node {
        int key;
        int val;
        Node* next;
        Node* prev;
        Node(int k,int v):key(k),val(v),next(nullptr),prev(nullptr){}
    };
    int cap;
    unordered_map<int,Node*> m;
    Node* head;
    Node* tail;
    void addNode(Node* newNode){
        Node* temp=head->next;
        newNode->next=temp;
        newNode->prev=head;
        head->next=newNode;
        temp->prev=newNode;
    }
    void deleteNode(Node* delNode){
        Node* delPrev=delNode->prev;
        Node* delNext=delNode->next;
        delPrev->next=delNext;
        delNext->prev=delPrev;
    }
    void moveToHead(Node* node){
        deleteNode(node);
        addNode(node);
    }
public:
    LRUCache(int capacity){
        cap=capacity;
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }
    int get(int key){
        if(m.find(key)==m.end()){
            return -1;
        }
        Node* resNode=m[key];
        moveToHead(resNode);
        return resNode->val;
    }
    void put(int key,int value){
        if(m.find(key)!=m.end()){
            Node* existingNode=m[key];
            existingNode->val=value;
            moveToHead(existingNode);
            return;
        }
        if(m.size()==cap){
            Node* lruNode=tail->prev;
            m.erase(lruNode->key);
            deleteNode(lruNode);
            delete lruNode; 
        }
        Node* newNode=new Node(key,value);
        m[key]=newNode;
        addNode(newNode);
    }
    ~LRUCache(){
        Node* curr=head;
        while(curr!=nullptr){
            Node* next=curr->next;
            delete curr;
            curr=next;
        }
    }
};
int main(){
    LRUCache cache(2);
    cache.put(1,1);
    cache.put(2,2);
    cout<<cache.get(1)<<"\n"; 
    cache.put(3,3); 
    cout<<cache.get(2)<<"\n"; 
    cache.put(4,4); 
    cout<<cache.get(1)<<"\n"; 
    cout<<cache.get(3)<<"\n"; 
    cout<<cache.get(4)<<"\n"; 
    return 0;
}

// Problem: least recently used (lru) cache