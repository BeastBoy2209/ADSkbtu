#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> p(N);
    for (int i = 0; i < N; i++) {
        cin >> p[i];
    }

    string S(N, ' ');
    S[0] = (p[0] + 97);

    for (int i = 1; i < N; i++) {
        long long temp = p[i] - p[i - 1];
        S[i] = (temp / (1LL << i)) + 97;
    }

    cout << S << endl;
    return 0;
}