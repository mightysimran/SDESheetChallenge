#include<bits/stdc++.h>
using namespace std;

class LFUCache {
private:
    struct Node {
        int key,value,cnt;
        Node* next; 
        Node* prev;
        Node(int _key,int _value):key(_key),value(_value),cnt(1),next(nullptr),prev(nullptr){}
    }; 
    struct List {
        int size; 
        Node* head; 
        Node* tail; 
        List(){
            head=new Node(-1,-1); 
            tail=new Node(-1,-1); 
            head->next=tail;
            tail->prev=head; 
            size=0;
        }
        ~List(){
            delete head;
            delete tail;
        }
        void addFront(Node* node){
            Node* temp=head->next;
            node->next=temp;
            node->prev=head;
            head->next=node;
            temp->prev=node;
            size++; 
        }
        void removeNode(Node* delnode){
            Node* prevNode=delnode->prev;
            Node* nextNode=delnode->next;
            prevNode->next=nextNode;
            nextNode->prev=prevNode;
            size--; 
        }
    };
    unordered_map<int,Node*> keyNode; 
    unordered_map<int,List*> freqListMap; 
    int maxSizeCache; 
    int minFreq; 
    int curSize; 
    void updateFreqListMap(Node* node){
        List* oldList=freqListMap[node->cnt];
        oldList->removeNode(node); 
        if(node->cnt==minFreq&&oldList->size==0){
            minFreq++; 
        }
        node->cnt++;
        if(freqListMap.find(node->cnt)==freqListMap.end()){
            freqListMap[node->cnt]=new List();
        }
        freqListMap[node->cnt]->addFront(node); 
    }
public:
    LFUCache(int capacity){
        maxSizeCache=capacity; 
        minFreq=0; 
        curSize=0; 
    }
    int get(int key){
        if(maxSizeCache==0||keyNode.find(key)==keyNode.end()){
            return -1; 
        }
        Node* node=keyNode[key]; 
        int val=node->value; 
        updateFreqListMap(node); 
        return val; 
    }
    void put(int key,int value){
        if(maxSizeCache==0)return;
        if(keyNode.find(key)!=keyNode.end()){
            Node* node=keyNode[key]; 
            node->value=value; 
            updateFreqListMap(node); 
            return;
        }
        if(curSize==maxSizeCache){
            List* list=freqListMap[minFreq]; 
            Node* lruNode=list->tail->prev; 
            keyNode.erase(lruNode->key); 
            list->removeNode(lruNode);
            delete lruNode; 
            curSize--; 
        }
        curSize++; 
        minFreq=1; 
        if(freqListMap.find(minFreq)==freqListMap.end()){
            freqListMap[minFreq]=new List();
        }
        Node* node=new Node(key,value); 
        freqListMap[minFreq]->addFront(node);
        keyNode[key]=node; 
    }
    ~LFUCache(){
        for(auto& pair:keyNode){
            delete pair.second;
        }
        for(auto& pair:freqListMap){
            delete pair.second;
        }
    }
};
int main(){
    LFUCache cache(2);
    cache.put(1,1);
    cache.put(2,2);
    cout<<cache.get(1)<<"\n"; 
    cache.put(3,3); 
    cout<<cache.get(2)<<"\n"; 
    cout<<cache.get(3)<<"\n"; 
    cache.put(4,4); 
    cout<<cache.get(1)<<"\n"; 
    cout<<cache.get(3)<<"\n"; 
    cout<<cache.get(4)<<"\n"; 
    return 0;
}

// Problem: least frequently used (lfu) cache