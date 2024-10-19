#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int dateToInt(const string& date) {
    int day = stoi(date.substr(0, 2));
    int month = stoi(date.substr(3, 2));
    int year = stoi(date.substr(6, 4));
    return year * 10000 + month * 100 + day;
}

void heapify(vector<string>& dates, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && dateToInt(dates[left]) > dateToInt(dates[largest]))
        largest = left;

    if (right < n && dateToInt(dates[right]) > dateToInt(dates[largest]))
        largest = right;

    if (largest != i) {
        swap(dates[i], dates[largest]);
        heapify(dates, n, largest);
    }
}

void heapSort(vector<string>& dates) {
    int n = dates.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(dates, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(dates[0], dates[i]);
        heapify(dates, i, 0);
    }
}

int main() {
    int n;
    cin >> n;
    vector<string> dates(n);

    for (int i = 0; i < n; ++i) {
        cin >> dates[i];
    }

    heapSort(dates);

    for (const auto& date : dates) {
        cout << date << endl;
    }

    return 0;
}
