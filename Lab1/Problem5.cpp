#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<int> boris, nursik;
    int card;
    for (int i = 0; i < 5; ++i) {
        cin >> card;
        boris.push(card);
    }
    for (int i = 0; i < 5; ++i) {
        cin >> card;
        nursik.push(card);
    }
    int moves = 0;
    const int MAX_MOVES = 1000000;

    while (!boris.empty() && !nursik.empty() && moves < MAX_MOVES) {
        int boris_card = boris.front();
        int nursik_card = nursik.front();
        boris.pop();
        nursik.pop();
        
        if ((boris_card == 0 && nursik_card == 9) || (boris_card > nursik_card && !(boris_card == 9 && nursik_card == 0))) {
            boris.push(boris_card);
            boris.push(nursik_card);
        } else {
            nursik.push(boris_card);
            nursik.push(nursik_card);
        }
        
        ++moves;
    }
    if (boris.empty()) {
        cout << "Nursik " << moves << endl;
    } else if (nursik.empty()) {
        cout << "Boris " << moves << endl;
    } else {
        cout << "blin nichya" << endl;
    }

    return 0;
}