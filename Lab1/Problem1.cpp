#include <iostream>
#include <deque>
#include <vector>

using namespace std;

vector<int> get_initial_deck(int n) {
    deque<int> deck;
    for (int i = n; i >= 1; --i) {
        deck.push_front(i);
        for (int j = 0; j < i; ++j) {
            int last_card = deck.back();
            deck.pop_back();
            deck.push_front(last_card);
        }
    }
    return vector<int>(deck.begin(), deck.end());
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> initial_deck = get_initial_deck(n);
        for (int card : initial_deck) {
            cout << card << " ";
        }
        cout << endl;
    }
    return 0;
}