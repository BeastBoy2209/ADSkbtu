#include<iostream>
#include<stack>
using namespace std;

bool areStacksEqual(stack<char> st1, stack<char> st2){
    if (st1.size() != st2.size()) {
        return false;
    }
    while (!st1.empty() && !st2.empty()) {
        if (st1.top() != st2.top()) {
            return false; 
        }
        st1.pop();
        st2.pop();
    }
    return true;
}

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    stack<char> st1;
    stack<char> st2;
    for(int i=0; i<s1.size();i++){
        if(s1[i]=='#'){
            st1.pop();
        } else {
            st1.push(s1[i]);
        }
    }
    for(int i=0; i<s2.size();i++){
        if(s2[i]=='#'){
            st2.pop();
        } else {
            st2.push(s2[i]);
        }
    }
    if(areStacksEqual(st1, st2) == true){
        cout << "Yes";
    } else{
        cout << "No";
    }
}
