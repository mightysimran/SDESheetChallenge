#include<bits/stdc++.h>
using namespace std;

class MaxHeap {
private:
    std::vector<int> heap;
    void heapifyUp(int index){
        while(index>0){
            int parent=(index-1)/2;
            if(heap[index]>heap[parent]){
                std::swap(heap[index],heap[parent]);
                index=parent;
            }
            else{
                break;
            }
        }
    }
    void heapifyDown(int index){
        int size=heap.size();
        while(true){
            int leftChild=2*index+1;
            int rightChild=2*index+2;
            int largest=index;
            if(leftChild<size&&heap[leftChild]>heap[largest]){
                largest=leftChild;
            }
            if(rightChild<size&&heap[rightChild]>heap[largest]){
                if(leftChild>=size||heap[rightChild]>heap[leftChild]){
                    largest=rightChild;
                }
            }
            if(largest!=index){
                std::swap(heap[index],heap[largest]);
                index=largest;
            }
            else{
                break;
            }
        }
    }
public:
    void initializeHeap(){
        heap.clear();
    }
    void insert(int x){
        heap.push_back(x);
        heapifyUp(heap.size()-1);
    }
    int getMax(){
        if(isEmpty()){
            throw std::runtime_error("Heap is empty");
        }
        return heap[0];
    }
    void extractMax(){
        if(isEmpty()){
            return;
        }
        heap[0]=heap.back();
        heap.pop_back();
        if(!isEmpty()){
            heapifyDown(0);
        }
    }
    int heapSize(){
        return heap.size();
    }
    bool isEmpty(){
        return heap.empty();
    }
    void changeKey(int ind,int val){
        if(ind<0||ind>=heap.size()){
            return;
        }
        int oldVal=heap[ind];
        heap[ind]=val;
        if(val>oldVal){
            heapifyUp(ind);
        }else if(val<oldVal){
            heapifyDown(ind);
        }
    }
};
int main(){
    MaxHeap maxHeap;
    std::cout<<"Executing operations..."<<std::endl;
    maxHeap.initializeHeap();
    std::cout<<"initializeHeap -> null"<<std::endl;
    maxHeap.insert(4);
    std::cout<<"insert(4) -> null"<<std::endl;
    maxHeap.insert(1);
    std::cout<<"insert(1) -> null"<<std::endl;
    maxHeap.insert(10);
    std::cout<<"insert(10) -> null"<<std::endl;
    std::cout<<"getMax -> "<<maxHeap.getMax()<<std::endl;
    std::cout<<"heapSize -> "<<maxHeap.heapSize()<<std::endl;
    std::cout<<"isEmpty -> "<<maxHeap.isEmpty()<<std::endl;
    maxHeap.extractMax();
    std::cout<<"extractMax -> null"<<std::endl;
    maxHeap.changeKey(0,16);
    std::cout<<"changeKey(0, 16) -> null"<<std::endl;
    std::cout<<"getMax -> "<<maxHeap.getMax()<<std::endl;
    return 0;
}

// Problem: implement max heap