#include <iostream>
#include <string>
using namespace std;

int cn(string t, string p) { 
    int n = t.size();
    int m = p.size();
    int i = 0;
    bool found = false;
    while(i < m) {
        int j = i;
        int l = 0;
        int cnt = 1;
        while (l < n && p[j] == t[l]) {
            if (l == n - 1) {
                found = true;
                break;
            }
            j = (j + 1) % m; 
            if (j == 0) {
                cnt++;
            }
            l++;
        }
        if (found) {
            return cnt;
        }
        i++;
    }
    return -1;
}

int main() {
    string p;
    string t;
    cin >> p; 
    cin >> t;
    cout << cn(t, p) << endl; 
    return 0;
}