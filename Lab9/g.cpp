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

    vector <int> occurrences = prefix(s); 
    cout << s.size() - occurrences.back() << endl; 

    return 0;
}