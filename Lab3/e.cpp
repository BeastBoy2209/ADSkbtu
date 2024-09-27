#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector <int> v;

    for(int i = n; i>0 ; i--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2  >> y2;
        vector <int> xy(4);
        xy.push_back(x1);
        xy.push_back(y1);
        xy.push_back(x2);
        xy.push_back(y2);
        sort(xy.begin(), xy.end());
        v.push_back(xy[xy.size() - 1]);
    }
    sort(v.begin(), v.end());
    cout << v[k - 1];
}