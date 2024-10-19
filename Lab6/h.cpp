#include<iostream>
#include<vector>
using namespace std;

int Parent(int i) {return (i - 1) / 2;}
int Left(int i) {return 2 * i + 1;}
int Right(int i) {return 2 * i + 2;}

void heapify(vector<char>& heap, int n, int i){
    int left = Left(i);
    int right = Right(i);
    int largest = i;
    if(left < n && heap[left] > heap[largest]){
        largest = left;
    }
    if(right < n && heap[right] > heap[largest]){
        largest = right;
    }
    if(i != largest){
        swap(heap[i], heap[largest]);
        heapify(heap, n, largest);
    }
}

void heapsort(vector<char>& heap){
    int n = heap.size();

    for(int i = Parent(n-1); i >=0; i--){
        heapify(heap, n, i);
    }
    for(int i=n-1; i>0 ;i--){
        swap(heap[i], heap[0]);
        heapify(heap, i, 0);
    }
}

int main() {
    int n;
    cin >> n;
    vector<char> ch(n);
    for (int i = 0; i < n; i++) {
        cin >> ch[i];
    }
    char s2;
    cin >> s2;
    char smallest = ch[0];
    for (int i = 0; i < n; i++) {
        if (ch[i] > s2) {
            smallest = ch[i];
            break;
        }
    }
    if (smallest <= s2) {
        smallest = ch[0];
    }

    cout << smallest << endl;
}