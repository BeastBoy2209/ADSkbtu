#include <iostream>
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
    string s; 
    cin >> s;
    int cnt = 0;
    vector <int> occurrences = prefix(s); 
    for(int i = 1; i < occurrences.size(); i++) { 
        if(i % 2 == 0) {
            if((i / (i - occurrences[i - 1])) % 2 == 0) { 
                cnt++; 
            }
        }
    } 
    cout << cnt << endl;

    return 0;
}