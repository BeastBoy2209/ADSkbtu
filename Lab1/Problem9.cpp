#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;  
    queue<int> kQ, sQ;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'K') {
            kQ.push(i);
        } else {
            sQ.push(i);  
        }
    }
    while (!kQ.empty() && !sQ.empty()) {
        int kIndex = kQ.front();
        int sIndex = sQ.front();
        if (kIndex < sIndex) {
            kQ.push(kIndex + n);
        }
        else {
            sQ.push(sIndex + n);
        }
        kQ.pop();
        sQ.pop();
    }
    if (kQ.empty()) {
        cout << "SAKAYANAGI" << endl;
    }
    else {
        cout << "KATSURAGI" << endl;
    }
}