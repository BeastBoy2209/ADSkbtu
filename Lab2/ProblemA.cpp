#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, k;
    vector<int> vec;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        vec.push_back(x);
    }
    cin >> k;
    int mindif = abs(vec[0] - k);
    int mindif_index = 0;
    for (int i = 1; i < n; ++i) {
        int current_diff = abs(vec[i] - k);
        if (current_diff < mindif) {
            mindif = current_diff;
            mindif_index = i;
        }
    }
    cout << mindif_index << endl;
}