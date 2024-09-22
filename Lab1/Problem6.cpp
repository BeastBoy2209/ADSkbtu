#include <iostream>
#include <vector>

using namespace std;

vector<int> generate_primes_up_to(int max) {
    vector<bool> is_prime(max + 1, true);
    vector<int> primes;
    is_prime[0] = is_prime[1] = false; 
    
    for (int i = 2; i <= max; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= max; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return primes;
}

int main() {
    int N;
    cin >> N;
    
    int upper_bound = 15000;
    
    vector<int> primes = generate_primes_up_to(upper_bound);
    
    if (N <= primes.size()) {
        cout << primes[N - 1] << endl;
    } else {
        cout << "Error: N is too large" << endl;
    }
    
    return 0;
}