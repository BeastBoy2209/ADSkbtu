#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    map <int, int> mp;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        mp[x]++;
    }
    int max = -10000;
    for(const auto & elem: mp){
        if(elem.second > max){
            max = elem.second;
        }
    }
    vector <int> mode;
    for(const auto & elem: mp){
        if(elem.second == max){
            mode.push_back(elem.first);
        }
    }
    sort(mode.begin(), mode.end());
    reverse(mode.begin(), mode.end());
    for(int i=0; i<mode.size(); i++){
        cout<<mode[i]<< " ";
    }
}