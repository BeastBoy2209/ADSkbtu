#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class EdgeList {
public:
    vector<pair<int, int>> edges;

    void addEdge(int u, int v) {
        edges.push_back(make_pair(u, v));
    }

    void printEdges() {
        for (auto edge : edges) {
            cout << "(" << edge.first << ", " << edge.second << ")" << endl;
        }
    }
};

int main() {
    EdgeList graph;
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    cout << "Edge List:" << endl;
    graph.printEdges();

    return 0;
}