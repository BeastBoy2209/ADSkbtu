#include<iostream>
#include<vector>
using namespace std;

int Parent(int i){ return (i-1)/2; }
int Left(int i){ return i*2+1; }
int Right(int i){ return i*2+2; }

void Heapify(vector<int>& vec, int i, int n){
    int smallest = i;
    if(Left(i) < n && vec[Left(i)] < vec[smallest]){
        smallest = Left(i);
    }
    if(Right(i) < n && vec[Right(i)] < vec[smallest]){
        smallest = Right(i);
    }
    if(i != smallest){
        swap(vec[smallest], vec[i]);
        Heapify(vec, smallest, n);
    }
}

void HeapSort(vector<int>& vec){
    int n = vec.size();
    for(int i = Parent(n-1); i >= 0; i--){
        Heapify(vec, i, n);
    }
    for(int i = n; i > 0; i--){
        swap(vec[0], vec[i]);
        Heapify(vec, 0, i);
    }
}

int main(){
    vector<int> vec = {123, 34, 13, 2, 8, 5, 90};
    HeapSort(vec);
    for(int x : vec){
        cout << x << " ";
    }
}