#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class maxHeap {
public:
    vector<int> heap;
    long long sum = 0;

    void heapify(int i) {
        int min = i;
        int n = heap.size();
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && heap[left] < heap[min]) {
            min = left;
        }
        if (right < n && heap[right] < heap[min]) {
            min = right;
        }
        if (min != i) {
            swap(heap[i], heap[min]);
            heapify(min);
        }
    }

    int putMin(int k) {
        if (heap.size() == 0) {
            return 0;
        }
        if (heap.size() == 1) {
            int root = heap[0];
            heap.pop_back();
            return root;
        }
        int root = heap[0];
        heap[0] = heap[heap.size() - 1];
        heap.pop_back();
        heapify(0);
        return root;
    }

    void _insert(int value, int k) {
        heap.push_back(value);
        sum += value;
        int i = heap.size() - 1;

        while (i != 0 && heap[(i - 1) / 2] > heap[i]) {
            swap(heap[(i - 1) / 2], heap[i]);
            i = (i - 1) / 2;
        }

        if (heap.size() > k) {
            sum -= putMin(k);
        }
    }
    void _sum() {
        if (heap.size() == 0) {
            cout << 0 << endl;
        } else {
            cout << sum << endl;
        }
    }
};

int main() {
    int q, k;
    cin >> q >> k;

    maxHeap heap;

    while (q--) {
        string s;
        cin >> s;
        if (s == "print") {
            heap._sum();
        } else if (s == "insert") {
            int x;
            cin >> x;
            heap._insert(x, k);
        }
    }
}
