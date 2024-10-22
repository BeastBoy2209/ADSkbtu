#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void merge(vector<int>& vec, int l, int r, int mid){
    int n1 = mid - l +1;
    int n2 = r - mid;
    vector<int> L(n1);
    vector<int> R(n2);
    for(int i=0; i<n1; i++){
        L[i]= vec[l + i];
    }
    for(int i=0; i<n2; i++){
        R[i]=vec[mid + i + 1];
    }
    int i = 0, j = 0, k = l;
    while(i < n1 && j<n2) {
        if(L[i] <= R[j]){
            vec[k] = L[i];
            i++;
        } else {
            vec[k] = R[j];
            j++;
        }
        ++k;
    }

    while(i < n1){
        vec[k] = L[i];
        ++i;
        ++k;
    }
    while(j < n2){
        vec[k] = R[j];
        ++j;
        ++k;
    }
}
void mergeSort(vector<int>& vec, int l, int r){
    if(l<r){
        int mid = l + (r-l)/2;

        mergeSort(vec, l, mid);
        mergeSort(vec, mid + 1, r);

        merge(vec, l, r, mid);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> firstPerson(n);
    vector<int> secondPerson(m);
    
    for (int i = 0; i < n; ++i) {
        cin >> firstPerson[i];
    }
    
    for (int i = 0; i < m; ++i) {
        cin >> secondPerson[i];
    }
    
    mergeSort(firstPerson, 0, n - 1);
    mergeSort(secondPerson, 0, m - 1);
    
    vector<int> commonNumbers;
    int i = 0, j = 0;
    
    while (i < n && j < m) {
        if (firstPerson[i] < secondPerson[j]) {
            ++i;
        } else if (firstPerson[i] > secondPerson[j]) {
            ++j;
        } else {
            commonNumbers.push_back(firstPerson[i]);
            ++i;
            ++j;
        }
    }
    
    for (int num : commonNumbers) {
        cout << num << " ";
    }
}