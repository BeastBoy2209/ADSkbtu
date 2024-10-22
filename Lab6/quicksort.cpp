#include<vector>
#include<iostream>
using namespace std;

int partition(vector<int>& vec, int low, int high){
    int pivot = vec[high];
    int i = low - 1;
    for(int j=low; j<high; j++){
        if(vec[j]<pivot){
            i++;
            swap(vec[j], vec[i]);
        }
    }
    swap(vec[i+1], vec[high]);
    return i+1;
}

void quickSort(vector<int>& vec, int low, int high){
    if(low<high){
        int part = partition(vec, low, high);

        quickSort(vec, low, part-1);
        quickSort(vec, part+1, high);
    }
}

int main(){
    int n; cin >> n;
    vector<int> vec(n);
    for(int i=0; i< n; i++){
        cin >> vec[i];
    }
    quickSort(vec, 0, vec.size()-1);
    for(int i=0; i< n; i++){
        cout << vec[i]<< " ";
    }
}