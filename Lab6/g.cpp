#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void quickSort(vector<pair<string, string>>& arr, int left, int right) {
    int i = left, j = right;
    auto pivot = arr[(left + right) / 2];

    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if (left < j) quickSort(arr, left, j);
    if (i < right) quickSort(arr, i, right);
}

int main() {
    int n;
    cin >> n;
    map<string, string> nickname_changes;
    map<string, string> original_nicknames;

    for (int i = 0; i < n; ++i) {
        string old_nickname, new_nickname;
        cin >> old_nickname >> new_nickname;
        string original_nickname = old_nickname;
        if (original_nicknames.find(old_nickname) != original_nicknames.end()) {
            original_nickname = original_nicknames[old_nickname];
        }

        original_nicknames[new_nickname] = original_nickname;
        nickname_changes[original_nickname] = new_nickname;
    }

    vector<pair<string, string>> results;
    for (const auto& entry : nickname_changes) {
        results.push_back(entry);
    }

    quickSort(results, 0, results.size() - 1);
    cout << results.size() << endl;
    for (const auto& entry : results) {
        cout << entry.first << " " << entry.second << endl;
    }

    return 0;
}