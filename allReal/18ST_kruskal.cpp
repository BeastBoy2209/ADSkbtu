#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int src, dest, weight;
};

class DisjointSets {
public:
    DisjointSets(int n);
    int find(int u);
    void unite(int u, int v);

private:
    vector<int> parent, rank;
};

DisjointSets::DisjointSets(int n) {
    parent.resize(n);
    rank.resize(n, 0);
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
    }
}

int DisjointSets::find(int u) {
    if (u != parent[u]) {
        parent[u] = find(parent[u]);
    }
    return parent[u];
}

void DisjointSets::unite(int u, int v) {
    int rootU = find(u);
    int rootV = find(v);
    if (rootU != rootV) {
        if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
}

class Graph {
public:
    Graph(int V, int E);
    void addEdge(int u, int v, int w);
    void kruskalMST();

private:
    int V, E;
    vector<Edge> edges;
};

Graph::Graph(int V, int E) : V(V), E(E) {}

void Graph::addEdge(int u, int v, int w) {
    edges.push_back({u, v, w});
}

void Graph::kruskalMST() {
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.weight < b.weight;
    });

    DisjointSets ds(V);
    vector<Edge> mst;

    for (Edge &edge : edges) {
        int u = edge.src;
        int v = edge.dest;

        int setU = ds.find(u);
        int setV = ds.find(v);

        if (setU != setV) {
            mst.push_back(edge);
            ds.unite(setU, setV);
        }
    }

    cout << "Edges in the Minimum Spanning Tree:" << endl;
    for (Edge &edge : mst) {
        cout << edge.src << " -- " << edge.dest << " == " << edge.weight << endl;
    }
}

int main() {
    int V = 4;
    int E = 5;
    Graph g(V, E);

    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 6);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);

    g.kruskalMST();

    return 0;
}