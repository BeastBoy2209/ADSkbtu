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

int kmp(string t, string p){
    int m = p.size();
    int n = t.size();
    int i = 0;
    int j = 0;
    vector<int> occur;
    vector<int> pref = prefix(p);
    while(i < n){
        if(t[i]==p[j]){
            i++;
            j++;
        }
        if(j == m){
            occur.push_back(i - j);
            j = pref[j - 1];
        }
        else if(t[i] != p[j]){
            if(j > 0){
                j = pref[j - 1];
            }
            else{
                i++;
            }
            
        }
    }
    if(!occur.empty()){ 
        return n  - occur[0] - m;
    }
    else{
        return -1;
    }
}

int main() {
    string text = "";
    string pattern = "";
    cin>>text>>pattern;
    if(text.size()!=pattern.size()){
        cout<<-1<<endl;
    }
    else{
        text += text;
        int res = kmp(text, pattern);
        cout<<res<<endl;
    }
    return 0;
}