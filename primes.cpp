#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

// Function to perform Prim's Algorithm
void prim(int nodes, vector<vector<pair<int, int>>> &adjList)
{
    // Initialize data structures
    vector<int> key(nodes + 1, INT_MAX);  // Key values to pick minimum weight edge
    vector<int> parent(nodes + 1, -1);    // To store MST structure
    vector<bool> inMST(nodes + 1, false); // To track vertices included in MST

    // Priority queue to pick the minimum weight edge
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    // Start from the first node (arbitrary)
    key[1] = 0;
    pq.push({0, 1}); // (weight, node)

    while (!pq.empty())
    {
        int u = pq.top().second; // Node with the smallest key value
        pq.pop();

        if (inMST[u])
            continue; // Skip if already included in MST
        inMST[u] = true;

        // Explore all neighbors of node `u`
        for (auto &[v, weight] : adjList[u])
        {
            if (!inMST[v] && weight < key[v])
            {
                key[v] = weight;      // Update key value
                parent[v] = u;        // Update parent
                pq.push({key[v], v}); // Push the updated key and vertex
            }
        }
    }

    // Output the MST
    cout << "Edges in the MST:" << endl;
    int mstCost = 0;
    for (int i = 2; i <= nodes; i++)
    { // Parent of 1 is -1, so start from 2
        if (parent[i] != -1)
        {
            cout << parent[i] << " -- " << i << " == " << key[i] << endl;
            mstCost += key[i];
        }
    }
    cout << "Total cost of MST: " << mstCost << endl;
}

int main()
{
    int nodes, edges;
    cout << "Enter the number of nodes: ";
    cin >> nodes;

    cout << "Enter the number of edges: ";
    cin >> edges;

    // Adjacency list representation of the graph
    vector<vector<pair<int, int>>> adjList(nodes + 1); // (neighbor, weight)

    cout << "Enter the edges (u v weight):" << endl;
    for (int i = 0; i < edges; i++)
    {
        int u, v, weight;
        cin >> u >> v >> weight;
        adjList[u].push_back({v, weight});
        adjList[v].push_back({u, weight}); // Undirected graph
    }

    prim(nodes, adjList);

    return 0;
}
