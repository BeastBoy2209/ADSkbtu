#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector <int> v;
    int x;
    for(int i=0; i<n; i++){
        cin>>x;
        v.push_back(x);
    }
    vector <int> age;
    for(int i=v.size(); i>=0; i--){
        int k=0;
        for(int j=i-1; j>=0; j--){
            if(v[i]>=v[j]){
                age.push_back(v[j]);
                k++;
                break;
            }
        }
        if(k==0){
            age.push_back(-1);
        }
    }
    reverse(age.begin(), age.end());
    age.pop_back();
    for(int i=0; i<age.size(); i++){
        cout<<age[i]<<" ";
    }
    
    return 0;
}