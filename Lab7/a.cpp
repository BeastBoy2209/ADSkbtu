#include <iostream>
#include <vector>
#include <string>
using namespace std;

void merge(vector<string>& vec, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<string> L(n1);
    vector<string> R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = vec[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = vec[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].size() <= R[j].size()) {
            vec[k] = L[i];
            i++;
        } else {
            vec[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        vec[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        vec[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<string>& vec, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(vec, left, mid);
        mergeSort(vec, mid + 1, right);
        merge(vec, left, mid, right);
    }
}

int main() {
    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);
        vector<string> vec;
        string word;
        for (char c : line) {
            if (c == ' ') {
                if (!word.empty()) {
                    vec.push_back(word);
                    word.clear();
                }
            } else {
                word += c;
            }
        }
        if (!word.empty()) {
            vec.push_back(word);
        }

        mergeSort(vec, 0, vec.size() - 1);

        for (int j = 0; j < vec.size(); j++) {
            if (j > 0) cout << " ";
            cout << vec[j];
        }
        cout << endl;
    }
}