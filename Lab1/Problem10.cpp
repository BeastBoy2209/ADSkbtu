#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> ages(n);
    for (int i = 0; i < n; ++i) {
        cin >> ages[i];
    }
    
    vector<int> result(n, -1);
    deque<int> dq;
    
    for (int i = 0; i < n; ++i) {
        // Remove elements from the back of deque if they are not younger
        while (!dq.empty() && ages[dq.back()] >= ages[i]) {
            dq.pop_back();
        }
        
        // If deque is not empty, the front element is the closest younger
        if (!dq.empty()) {
            result[i] = ages[dq.front()];
        }
        
        // Add the current element index to the deque
        dq.push_back(i);
    }
    
    // Output the results
    for (int i = 0; i < n; ++i) {
        cout << result[i] << " ";
    }
    
    return 0;
}