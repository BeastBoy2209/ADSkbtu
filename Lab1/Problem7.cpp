#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>  
using namespace std;

void sieve(int limit, vector<int>& primes) {
    vector<bool> is_prime(limit + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int p = 2; p * p <= limit; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= limit; i += p) {
                is_prime[i] = false;
            }
        }
    }
    for (int i = 2; i <= limit; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
}

int main() {
    int n;
    cin >> n;
    int limit = 10000;
    vector<int> primes;
    sieve(limit, primes);
    vector<int> superprimes;
    for (int i = 0; i < primes.size(); i++) {
        if (binary_search(primes.begin(), primes.end(), i + 1)) {
            superprimes.push_back(primes[i]);
        }
        if (superprimes.size() >= 100) break;
    }
    cout << superprimes[n - 1] << endl;
}