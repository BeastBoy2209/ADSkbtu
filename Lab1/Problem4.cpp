#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    string st;
    cin >> st;

    stack<char> s;

    for (char c : st) {
        if (!s.empty() && s.top() == c) {
            s.pop();
        } else {
            s.push(c);
        }
    }

    if (s.empty()) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}