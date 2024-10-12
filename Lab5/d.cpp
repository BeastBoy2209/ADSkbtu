#include <iostream>
#include <vector>

using namespace std;

class maxHeap {
public:
    vector<int> heap;

    void heapify(int i) {
        int minVal = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < heap.size() && heap[left] < heap[minVal]) {
            minVal = left;
        }
        if (right < heap.size() && heap[right] < heap[minVal]) {
            minVal = right;
        }
        if (minVal != i) {
            swap(heap[i], heap[minVal]);
            heapify(minVal);
        }
    }

    void buildHeap() {
        for (int i = heap.size() / 2 - 1; i >= 0; i--) {
            heapify(i);
        }
    }

    int extractMin() {
        if (heap.size() == 0) {
            return -1; 
        }
        int minVal = heap[0];
        swap(heap[0], heap[heap.size() - 1]);
        heap.pop_back();
        if (!heap.empty()) {
            heapify(0);
        }
        return minVal;
    }

    void insert(int value) {
        heap.push_back(value);
        int i = heap.size() - 1;
        while (i != 0 && heap[(i - 1) / 2] > heap[i]) {
            swap(heap[(i - 1) / 2], heap[i]);
            i = (i - 1) / 2;
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    maxHeap heap;
    for (int i = 0; i < n; i++) {
        int density;
        cin >> density;
        heap.insert(density);
    }

    heap.buildHeap();
    int operations = 0;

    while (heap.heap[0] < m) {
        if (heap.heap.size() < 2) {
            cout << -1 << endl;
            return 0;
        }
        int least = heap.extractMin();
        int secondLeast = heap.extractMin();
        int newDensity = least + 2 * secondLeast;
        heap.insert(newDensity);
        operations++;
    }

    cout << operations << endl;
}
