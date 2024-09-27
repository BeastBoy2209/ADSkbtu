#include <iostream>
#include <vector>
using namespace std;

int BrawlStars(vector<int>& vec, int l, int r, int TT) { // p.s. BrawlStars - Bin. Search
    if (l > r) {
        return -1;
    }
    int mid = l + (r - l) / 2;
    if (vec[mid] == TT) {
        return mid;
    } 
    else if (vec[mid] < TT) { 
        return BrawlStars(vec, mid + 1, r, TT);
    } 
    else {
        return BrawlStars(vec, l, mid - 1, TT);  
    }
}

int main() {
    vector<int> v;
    int n, target;

    cout << "target is: ";
    cin >> target;
    cout << "n: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    cout << "your vec: ";
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    int result = BrawlStars(v, 0, v.size() - 1, target);
    if (result != -1) {
        cout << "element on ind.: " << result << " element is: " <<  v[result];
    } else {
        cout << "Element not found" << endl;
    }
    return 0;
}