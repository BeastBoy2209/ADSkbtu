#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int rowSum(const vector<int>& row) {
    int sum = 0;
    for (int num : row) {
        sum += num;
    }
    return sum;
}

bool customComparator(const vector<int>& row1, const vector<int>& row2) {
    int sum1 = rowSum(row1);
    int sum2 = rowSum(row2);
    if (sum1 != sum2) {
        return sum1 > sum2;
    }
    return row1 < row2;
}

void merge(vector<vector<int>>& rows, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<vector<int>> L(n1);
    vector<vector<int>> R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = rows[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = rows[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (customComparator(L[i], R[j])) {
            rows[k] = L[i];
            i++;
        } else {
            rows[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        rows[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        rows[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<vector<int>>& rows, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(rows, left, mid);
        mergeSort(rows, mid + 1, right);
        merge(rows, left, mid, right);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> rows(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> rows[i][j];
        }
    }

    mergeSort(rows, 0, n - 1);

    for (const auto& row : rows) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
}