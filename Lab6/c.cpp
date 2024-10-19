#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> points(n);

    for (int i = 0; i < n; ++i) {
        cin >> points[i];
    }

    heapSort(points, n);

    int min_diff = abs(points[1] - points[0]);
    vector<pair<int, int>> result;
    result.push_back({points[0], points[1]});

    for (int i = 1; i < n - 1; ++i) {
        int diff = abs(points[i + 1] - points[i]);
        if (diff < min_diff) {
            min_diff = diff;
            result.clear();
            result.push_back({points[i], points[i + 1]});
        } else if (diff == min_diff) {
            result.push_back({points[i], points[i + 1]});
        }
    }

    for (const auto& pair : result) {
        cout << pair.first << " " << pair.second << " ";
    }

    return 0;
}