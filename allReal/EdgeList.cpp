#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class EdgeList {
public:
    void addEdge(int u, int v) {
        edges.push_back(make_pair(u, v));
    }

private:
    vector<pair<int, int>> edges;
};