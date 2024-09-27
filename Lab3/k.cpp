#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int SubArray(vector<int>& vec, int n, int TT){
    int minLength = INT_MAX, sum = 0, left = 0;

    for(int right = 0; right < n; right++) {
        sum += vec[right];
        while(sum >= TT) {
            minLength = min(minLength, right - left + 1);
            sum -= vec[left];
            left++;
        }
    }

    return minLength;
}

int main() {
    int n, f;
    cin >> n >> f;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int result = SubArray(v, n, f);
    if (result == INT_MAX) {
        cout << -1;
    } else {
        cout << result;
    }

    return 0;
}