#include<iostream>
#include<vector>
using namespace std;

class MaxHeap{
    public:
    vector<int> vec;

    int Parent(int i){ return (i-1)/2; }
    int Left(int i){ return 2*i+1; }
    int Right(int i){ return 2*i+2; }

    void insert(int value){
        vec.push_back(value);
        int i = vec.size()-1;
        while(i != 0 && vec[Parent(i)] < vec[i]){
            swap(vec[i], vec[Parent(i)]);
            i = Parent(i);
        }
    }

    void Heapify(int i){
        int largest = i;

        if(Left(i) < vec.size() && vec[Left(i)] > vec[largest]){
            largest = Left(i);
        }
        if(Right(i) < vec.size() && vec[Right(i)] > vec[largest]){
            largest = Right(i);
        }
        if(i != largest){
            swap(vec[largest], vec[i]);
            Heapify(largest);
        }
    }

    void print(){
        int n = vec.size();
        for(int i = 0; i < n; i++){
            cout << vec[i] << " ";
        }
        cout << "\n";
    }
};


int main(){
    MaxHeap heap;
    heap.insert(12);
    heap.insert(19);
    heap.insert(13);
    heap.insert(3);
    heap.insert(2);
    heap.insert(12);
    heap.insert(1123);
    heap.insert(32);
    heap.Heapify(6);
    heap.print();
}