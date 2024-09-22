#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

void findFirstNonRepeating(int n, char stream[]) {
    unordered_map<char, int> charCount;
    list<char> nonRepeatingChars;

    for (int i = 0; i < n; i++) {
        char ch = stream[i];
        charCount[ch]++;
        if (charCount[ch] == 1) {
            nonRepeatingChars.push_back(ch);
        }
        else if (charCount[ch] == 2) {
            nonRepeatingChars.remove(ch);
        }
        if (!nonRepeatingChars.empty()) {
            cout << nonRepeatingChars.front() << " ";
        } else {
            cout << "-1 ";
        }
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        char stream[500];
        for (int i = 0; i < N; i++) {
            cin >> stream[i];
        }

        findFirstNonRepeating(N, stream);
    }

    return 0;
}