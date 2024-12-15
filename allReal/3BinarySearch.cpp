#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void BinarySearch(vector<int> v, int value, int l, int r){
    if (l > r) {
        cout << "no" << "\n";
        return;
    }
    int mid = l + (r - l) / 2;
    if(!v.empty()){
        if(value == v[mid]){
            cout << "yes" << "\n";
            return;
        }
        if(value < v[mid]){
            BinarySearch(v, value, l, mid - 1);
            cout << "x" << "\n";
        } else {
            BinarySearch(v, value, mid + 1, r);
            cout << "y" << "\n";
        }
    }
}

int main(){
    vector<int> v = {1, 2, 123, 3, 45, 32, 1245, 90};
    sort(v.begin(), v.end());
    int value = 83;
    BinarySearch(v, value, 0, v.size());

    for(int i : v){
        cout << i << " ";
    }
}