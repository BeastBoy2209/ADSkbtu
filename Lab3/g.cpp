#include <iostream>
#include <vector>
using namespace std;

bool flights(vector <int> &vec, int f, int mid) {
    int total = 0;
    for(int i = 0; i < vec.size(); i++) {
        total += (vec[i] + mid - 1) / mid;
    }

    if(total > f) {
        return true;
    } 

    return false;
}

int main() {
    int n;
    int f;
    cin >> n >> f;
    vector <int> v(n);

    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int max = (int)-1e9;
    for(int i = 0; i < v.size(); i++) {
        if(max < v[i]) {
            max = v[i];
        }
    }

    int l = 1, r = max, res = 0;

    while(l <= r) {
        int mid = l + (r - l) / 2;
        if(flights(v, f, mid)) {
            res = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << res + 1;

    return 0;
}