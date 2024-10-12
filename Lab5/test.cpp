#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
public:
    vector<int> heap;

    int Parent(int i) { return (i - 1) / 2; }
    int Left(int i) { return 2 * i + 1; }
    int Right(int i) { return 2 * i + 2; }


    void Insert(int value) {
        heap.push_back(value);  
        int i = heap.size() - 1;

        while (i != 0 && heap[Parent(i)] > heap[i]) {
            swap(heap[i], heap[Parent(i)]);
            i = Parent(i);
        }
    }

    void Heapify(int i) {
        int left = Left(i);
        int right = Right(i);
        int smallest = i;

        if (left < heap.size() && heap[left] < heap[smallest])
            smallest = left;

        if (right < heap.size() && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            Heapify(smallest);
        }
    }

    int ExtractMin() {
        if (heap.size() == 0)
            return -1;

        if (heap.size() == 1) {
            int root = heap[0];
            heap.pop_back();
            return root;
        }

        int root = heap[0];

        heap[0] = heap.back();
        heap.pop_back();

        Heapify(0);

        return root;
    }

    void BuildHeap(vector<int>& array) {
        heap = array;
        for (int i = Parent(heap.size() - 1); i >= 0; i--) {
            Heapify(i);
        }
    }

    void PrintHeap() {
        for (int i = 0; i < heap.size(); i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MinHeap h;

    h.Insert(3);
    h.Insert(2);
    h.Insert(15);
    h.Insert(5);
    h.Insert(4);
    h.Insert(45);

    cout << "Min-Heap elements: ";
    h.PrintHeap();

    cout << "Extracted min: " << h.ExtractMin() << endl;

    cout << "Min-Heap after extraction: ";
    h.PrintHeap();

    return 0;
}
