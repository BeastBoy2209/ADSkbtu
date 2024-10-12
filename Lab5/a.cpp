#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
    vector<long long> heap;

    int Parent(int i) { 
        return (i - 1) / 2; 
    }
    int Left(int i) { 
        return 2 * i + 1; 
    }
    int Right(int i) { 
        return 2 * i + 2; 
    }

    void SiftUp(int i) {
        while (i != 0 && heap[Parent(i)] > heap[i]) {
            swap(heap[i], heap[Parent(i)]);
            i = Parent(i);
        }
    }

    void SiftDown(int i) {
        int minIndex = i;
        int l = Left(i);
        if (l < heap.size() && heap[l] < heap[minIndex]) {
            minIndex = l;
        }
        int r = Right(i);
        if (r < heap.size() && heap[r] < heap[minIndex]) {
            minIndex = r;
        }
        if (i != minIndex) {
            swap(heap[i], heap[minIndex]);
            SiftDown(minIndex);
        }
    }

public:
    void Insert(long long value) {
        heap.push_back(value);
        SiftUp(heap.size() - 1);
    }

    long long ExtractMin() {
        long long result = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        SiftDown(0);
        return result;
    }

    int Size() {
        return heap.size();
    }
};

int main() {
    int n;
    cin >> n;
    MinHeap heap;

    for (int i = 0; i < n; i++) {
        long long size;
        cin >> size;
        heap.Insert(size);
    }

    long long totalCost = 0;

    while (heap.Size() > 1) {
        long long first = heap.ExtractMin();
        long long second = heap.ExtractMin();
        long long cost = first + second;
        totalCost += cost;
        heap.Insert(cost);
    }

    cout << totalCost << endl;

    return 0;
}
