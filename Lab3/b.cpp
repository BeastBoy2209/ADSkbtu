#include <iostream>
using namespace std;

int main() {
    unsigned long long n, k;
    cin >> n >> k;
    unsigned long long arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    unsigned long long l = 0, r = 1e15;
    while(l <= r) {
        unsigned long long mid = l + (r - l) / 2, x = 1, sum = 0;
        for(int i = 0; i < n; i++) {
            if(mid < sum + arr[i]) {
                x++;
                sum = 0;
            }
            if(mid < arr[i]) {
                x = k + 1;
            } 
            sum += arr[i];
        }
        if(k < x) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << l;
}