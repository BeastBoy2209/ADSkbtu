#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Parent(int i) { return (i - 1) / 2; }
int Left(int i) { return 2 * i + 1; }
int Right(int i) { return 2 * i + 2; }

void heapify(vector<char>& heap, int n, int i) {
    int left = Left(i);
    int right = Right(i);
    int largest = i;

    if (left < n && heap[left] > heap[largest]) {
        largest = left;
    }

    if (right < n && heap[right] > heap[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(heap[i], heap[largest]);
        heapify(heap, n, largest);
    }
}

void heapsort(vector<char>& heap) {
    int n = heap.size();
    for (int i = Parent(n - 1); i >= 0; i--) {
        heapify(heap, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        swap(heap[0], heap[i]);
        heapify(heap, i, 0);
    }
}

void _print(const vector<char>& heap) {
    for (int i = 0; i < heap.size(); i++) {
        cout << heap[i];
    }
}

int main() {
    vector<char> heap;
    vector<char> vowels;
    int n; 
    cin >> n;

    for (int i = 0; i < n; i++) {
        char x; 
        cin >> x;
        if (x != 'a' && x != 'e' && x != 'i' && x != 'o' && x != 'u') {
            heap.push_back(x);
        } else {
            vowels.push_back(x);
        }
    }

    heapsort(heap);
    heapsort(vowels);
    _print(vowels);
    _print(heap);

    return 0;
}
