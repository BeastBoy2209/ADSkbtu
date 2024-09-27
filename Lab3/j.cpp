#include <iostream>
#include <vector>
using namespace std;

bool steal(vector <int> &arr, int h, int mid) {
    int final = 0;

    for(int i = 0; i < arr.size(); i++) {
        final += (arr[i] + mid - 1) / mid;
    }
    if(final > h) {
        return false;
    } return true;
}

int main() {
    int n, f;
    cin >> n >> f;
    vector <int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int maximum = (int)-1e9;
    for(int i = 0; i < v.size(); i++) {
        if(maximum < v[i]) {
            maximum = v[i];
        }
    }
    int l = 1, r = maximum, res = 0;

    while(l <= r) {
        int mid = l + (r - l) / 2;
        if(steal(v, f, mid)) {
            res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << res;
}