#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure to represent an edge
struct Edge {
    int u, v, weight;
};

// Comparator function to sort edges by weight
bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

// Function to find the parent of a node (with path compression)
int findParent(int node, vector<int> &parent) {
    if (node == parent[node]) {
        return node;
    }
    return parent[node] = findParent(parent[node], parent);
}

// Function to union two sets
void unionSets(int u, int v, vector<int> &parent, vector<int> &rank) {
    u = findParent(u, parent);
    v = findParent(v, parent);

    if (rank[u] < rank[v]) {
        parent[u] = v;
    } else if (rank[u] > rank[v]) {
        parent[v] = u;
    } else {
        parent[v] = u;
        rank[u]++;
    }
}

// Function to perform Kruskal's Algorithm
void kruskal(int nodes, vector<Edge> &edges) {
    // Sort edges by weight
    sort(edges.begin(), edges.end(), compare);

    vector<int> parent(nodes + 1);
    vector<int> rank(nodes + 1, 0);

    // Initialize parent for each node
    for (int i = 1; i <= nodes; i++) {
        parent[i] = i;
    }

    vector<Edge> mst; // To store the edges of the Minimum Spanning Tree
    int mstCost = 0;

    for (Edge &edge : edges) {
        int u = edge.u;
        int v = edge.v;

        // Check if the edge forms a cycle
        if (findParent(u, parent) != findParent(v, parent)) {
            mst.push_back(edge); // Include the edge in the MST
            mstCost += edge.weight;
            unionSets(u, v, parent, rank); // Union the sets
        }
    }

    // Print the Minimum Spanning Tree
    cout << "Edges in the MST:" << endl;
    for (Edge &e : mst) {
        cout << e.u << " -- " << e.v << " == " << e.weight << endl;
    }
    cout << "Total cost of MST: " << mstCost << endl;
}

int main() {
    int nodes, edgesCount;
    cout << "Enter the number of nodes: ";
    cin >> nodes;

    cout << "Enter the number of edges: ";
    cin >> edgesCount;

    vector<Edge> edges;

    cout << "Enter the edges (u v weight):" << endl;
    for (int i = 0; i < edgesCount; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        edges.push_back({u, v, weight});
    }

    kruskal(nodes, edges);

    return 0;
}