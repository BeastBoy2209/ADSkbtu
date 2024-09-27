#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int FL(vector <int>& vec, int TT) {
    int l = 0, r = vec.size() - 1;
    int beg = -1;
    while(l <= r) {
        int mid = l + (r - l) / 2;
        if(vec[mid] == TT) {
            beg = mid;
            r = mid - 1;
        } else if(vec[mid] < TT) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    if(beg == -1) {
        return l;
    }

    return beg;
}

int FR(vector <int>& vec, int TT) {
    int l = 0, r = vec.size() - 1;
    int end = -1;
    while(l <= r) {
        int mid = l + (r - l) / 2;
        if(vec[mid] == TT) {
            end = mid;
            l = mid + 1;
        } else if(vec[mid] < TT) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    if(end == -1) {
        return r;
    } 

    return end;
}

int dif(vector <int>& vec, int l, int r) {
    return FR(vec, r) - FL(vec, l) + 1;
}

int main() {
    int n, q;
    cin >> n >> q;
    vector <int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    while(q--) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if(l1 <= l2) {
            if(r1 < l2) {
                cout << dif(v, l1, r2) - dif(v, r1 + 1, l2 - 1) << "\n";
            } else {
                cout << dif(v, l1, max(r1, r2)) << "\n";
            }
        } else {
            if(r2 < l1) {
                cout << dif(v, l2, r1) - dif(v, r2 + 1, l1 - 1) << "\n";
            } else {
                cout << dif(v, l2, max(r1, r2)) << "\n";
            }
        }
    }
}