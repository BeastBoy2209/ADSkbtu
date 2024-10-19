#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

int Parent(int i){
    return (i-1)/2;
}
int Left(int i){
    return 2*i+1;
}
int Right(int i){
    return 2*i+2;
}

void heapify(vector<int>& heap, int n, int i){
    int largest = i;
    if(Left(i) < n && heap[Left(i)] > heap[largest])
        largest = Left(i);
    if(Right(i) < n && heap[Right(i)] > heap[largest])
        largest = Right(i);
    if(i != largest){
        swap(heap[i], heap[largest]);
        heapify(heap, n, largest);
    }
}

void heapsort(vector<int>& heap){
    int n = heap.size();
    for(int i = Parent(n - 1); i >= 0; i--){
        heapify(heap, n, i);
    }
    for(int i = n - 1; i > 0; i--){
        swap(heap[0], heap[i]);
        heapify(heap, i, 0);
    }
}

void equals(vector<int>& heap1, vector<int>& heap2){
    unordered_map<int, int> count1, count2;
    for(int element: heap1){
        count1[element]++;
    }
    for(int element: heap2){
        count2[element]++;
    }
    vector<int> common_elements;
    for(auto& pair: count1){
        int element = pair.first;
        int min_count = min(pair.second, count2[element]);
        for(int i = 0; i < min_count; i++){
            common_elements.push_back(element);
        }
    }
    sort(common_elements.begin(), common_elements.end());
    for(int element: common_elements){
        cout << element << " ";
    }
}

void _print(vector<int>& heap){
    for(int number: heap){
        cout << number << " ";
    }
}

int main(){
    int n, m; 
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
    heapsort(a);
    heapsort(b);
    equals(a, b);
}