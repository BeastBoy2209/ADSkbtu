#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
public:
    MaxHeap() {}

    void push(int value) {
        heap.push_back(value);
        siftUp(heap.size() - 1);
    }

    int top() {
        return heap.empty() ? 0 : heap[0];
    }

    void pop() {
        if (heap.empty()) return;
        heap[0] = heap.back();
        heap.pop_back();
        siftDown(0);
    }

    bool empty() {
        return heap.empty();
    }

private:
    vector<int> heap;

    void siftUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index] <= heap[parent]) break;
            swap(heap[index], heap[parent]);
            index = parent;
        }
    }

    void siftDown(int index) {
        int size = heap.size();
        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int largest = index;

            if (left < size && heap[left] > heap[largest]) {
                largest = left;
            }
            if (right < size && heap[right] > heap[largest]) {
                largest = right;
            }
            if (largest == index) break;
            swap(heap[index], heap[largest]);
            index = largest;
        }
    }
};

int main() {
    int n;
    cin >> n;
    MaxHeap maxHeap;

    for (int i = 0; i < n; i++) {
        int weight;
        cin >> weight;
        maxHeap.push(weight);
    }

    while (!maxHeap.empty()) {
        int first = maxHeap.top();
        maxHeap.pop();
        if (maxHeap.empty()) {
            cout << first << endl;
            return 0;
        }
        int second = maxHeap.top();
        maxHeap.pop();
        
        if (first != second) {
            maxHeap.push(first - second);
        }
    }

    cout << 0 << endl;
}
