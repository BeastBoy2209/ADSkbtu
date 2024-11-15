#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> prefix(string p){
    int m = p.size();
    vector<int> pref(m);
    int j = 0;
    int i = 1;
    while(i < m){
        while(j > 0 && p[i] != p[j]){
            j = pref[j - 1];
        }
        if(p[i] == p[j]){
            j++;
        }
        pref[i] = j;
        i++;
    } 
    return pref;
}

int main() {
    string s = "";
    cin >> s;
    int n = 0;
    cin >> n;
    vector<int> buf;
    vector<int> res;
    int cnt = 0;
    vector<string> city(n);

    for (int i = 0; i < n; i++) {
        cin >> city[i];
        city[i][0] = tolower(city[i][0]);
    }

    int mx = 0;
    buf.reserve(n);
    res.reserve(n);

    for (int i = 0; i < n; i++) {
        vector<int> pref = prefix(city[i] + s);
        int suffixLength = pref.back();
        if (suffixLength > mx) {
            mx = suffixLength;
        }
        buf.push_back(suffixLength);
    }

    for (int i = 0; i < n; i++) {
        city[i][0] = toupper(city[i][0]);
        if (buf[i] == mx && mx != 0) {
            res.push_back(i);
            cnt++;
        }
    }

    cout << cnt << endl;
    for (int i = 0; i < cnt; i++) {
        cout << city[res[i]] << endl;
    }

    return 0;
}