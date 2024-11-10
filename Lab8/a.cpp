#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

const long long MOD = 1e9 + 7;
const int BASE = 11;

long long mhash(const string &s) {
    long long val = 0;
    long long p = 1;
    for (char ch : s) {
        val = (val + (ch - 47) * p) % MOD;
        p = (p * BASE) % MOD;
    }
    return val;
}

int main() {
    int N; 
    cin >> N;
    vector<string> v;
    map<string, bool> map;

    for (int i = 0; i < 2 * N; i++) {
        string s; 
        cin >> s;
        v.push_back(s);
        map[s] = true;
    }

    int cnt = 0;
    for (const string &s : v) {
        if (cnt == N) break;
        string hash = to_string(mhash(s));
        if (map[hash]) {  
            cout << "Hash of string \"" << s << "\" is " << hash << endl;
            cnt++;
        }
    }

    return 0;
}