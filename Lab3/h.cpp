#include<iostream>
#include<vector>
using namespace std;

int BrawlStars(vector <int>& vec, int TT) {
    int l = 1;
    int r = vec.size();

    while(l <= r) {
        int mid = l + (r - l) / 2;
        if(vec[mid] < TT) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return l;
}

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<int> v1(n), v2(n);
    for(int i = 1; i <= n; i++) {
        cin >> v1[i];
    }
    for(int i = 1; i <= n; i++) {
        if(i == 1) {
            v2[i] = v1[i];
        } else {
            v2[i] = v2[i - 1] + v1[i];
        }
    }

    while(m--) {
        int x;
        cin >> x;
        cout << BrawlStars(v2, x) << "\n";
    }

    return 0;
}