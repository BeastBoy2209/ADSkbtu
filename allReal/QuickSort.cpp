#include<iostream>
#include<vector>
using namespace std;

void QuickSort(vector<int>& vec, int l, int r){
    if(l<r){
        int pivot = vec[r];
        int i = l - 1;

        for(int j = l; j < r; j++){
            if(vec[j] < pivot){
                i++;
                swap(vec[j], vec[i]);
            }
        }
    swap(vec[i+1], vec[r]);
    int pivIndex = i + 1;

    QuickSort(vec, l, pivIndex-1);
    QuickSort(vec, pivIndex + 1, r);
    }
}

int main(){
    vector<int> vec = {1, 3, 4, 5, 6, 15 ,12 , 31 ,2 ,23 , 123};
    QuickSort(vec, 0, vec.size());
    for(int i : vec){
        cout << i << " ";
    }
}