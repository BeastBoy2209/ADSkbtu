//Priority Queue
#include<iostream>
#include<vector>
using namespace std;

class PriorityQueue {
private:
    vector<int> heap;
    int Parent(int i) { return (i - 1) / 2; }
    int Left(int i) { return (2 * i + 1); }
    int Right(int i) { return (2 * i + 2); }

    void heapifyUp(int i) {
        if (i && heap[Parent(i)] < heap[i]) {
            swap(heap[i], heap[Parent(i)]);
            heapifyUp(Parent(i));
        }
    }

    void heapifyDown(int i) {
        int largest = i;

        if (Left(i) < size() && heap[Left(i)] > heap[largest])
            largest = Left(i);

        if (Right(i) < size() && heap[Right(i)] > heap[largest])
            largest = Right(i);

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }
public:
    unsigned int size() { return heap.size(); }
    bool empty() { return size() == 0; }

    void push(int element) {
        heap.push_back(element);
        heapifyUp(size() - 1);
    }

    void pop() {
        if (size() > 1) {
            heap[0] = heap.back();
            heap.pop_back();
            heapifyDown(0);
        } else {
            heap.pop_back();
        }
    }

    int top() {
        if (!empty())
            return heap.front();
    }
};

int main(){

}