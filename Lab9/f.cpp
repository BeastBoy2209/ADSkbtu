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

vector<int> kmp(const string& text, const string& pattern) {
    vector<int> result;
    int patternLength = pattern.size();
    int textLength = text.size();

    if (patternLength > textLength) {
        return result; 
    }

    string str = pattern + ";" + text;
    vector<int> pref = prefix(str);

    for (int i = patternLength + 1; i <= textLength + patternLength; ++i) {
        if (pref[i] == patternLength) {
            result.push_back(i - 2 * patternLength);
        }
    }
    return result;
}

int main() {
    string text, pattern;
    cin >> text >> pattern;
    vector<int> occurrences = kmp(text, pattern);
    cout << occurrences.size() << endl;
    for (int i = 0; i < occurrences.size(); ++i) {
        cout << occurrences[i] + 1 << " ";
    }
    cout << endl;

    return 0;
}