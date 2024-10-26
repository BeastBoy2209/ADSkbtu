#include<iostream>
#include<vector>
using namespace std;

void Merge(vector<int>& vec, int l, int r, int mid){
    int n1 = mid - l + 1;
    int n2 = r - mid;
    vector<int> L(n1), R(n2);
    for(int i = 0; i < n1; i++){
        L[i] = vec[l + i];
    }
    for(int i = 0; i < n2; i++){
        R[i] = vec[mid + i + 1];
    }
    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            vec[k] = L[i];
            i++;
        } else { 
            vec[k] = R[j];
            j++;
        }
        k++;
    }
    while(i < n1){
        vec[k] = L[i];
        i++;
        k++;
    }
    while(j < n2){
        vec[k] = R[j];
        j++;
        k++;
    }
}

void MergeSort(vector<int>& vec, int l, int r){
    if(l < r){
        int mid = l + (r-l) / 2;
        MergeSort(vec, l, mid);
        MergeSort(vec, mid + 1, r);
        Merge(vec, l, r, mid);
    }
}

int main(){
    vector<int> vec = {1, 23, 11, 54, 313, 12, 21};
    MergeSort(vec, 0, vec.size() - 1);
    for (int x : vec) {
        cout << x << " ";
    }
    return 0;
}