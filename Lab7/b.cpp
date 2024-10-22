#include<iostream>
#include<vector>
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

int main(){
    int n; cin >> n;
    vector<int> vec1(n);
    for(int i=0; i < n; i++){
        cin >> vec1[i];
    }
    int m; cin >> m;
    for(int i=0; i < m; i++){
        int x; cin >> x;
        vec1.push_back(x);
    }

    mergeSort(vec1, 0, vec1.size()-1);
    for(int x : vec1){
        cout << x << " ";
    }
}