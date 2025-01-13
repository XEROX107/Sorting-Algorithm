#include <iostream>
#include <vector>
using namespace std;
// Function to perform DFS
void DFS(int node, vector<vector<int>> &adjList, vector<bool> &visited)
{
    visited[node] = true; // Mark the current node as visited
    cout << node << " ";  // Print the current node

    // Traverse all neighbors
    for (int neighbor : adjList[node])
    {
        if (!visited[neighbor])
        {
            DFS(neighbor, adjList, visited); // Recur for unvisited neighbors
        }
    }
}
int main()
{
    int nodes, edges;
    cout << "Enter the number of nodes: ";
    cin >> nodes;

    cout << "Enter the number of edges: ";
    cin >> edges;
    // Graph representation using an adjacency list
    vector<vector<int>> adjList(nodes + 1); // 1-based indexing
    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u); // For undirected graph
    }

    // Visited array to track visited nodes
    vector<bool> visited(nodes + 1, false);

    // Perform DFS starting from a specific node
    int startNode;
    cout << "Enter the starting node for DFS: ";
    cin >> startNode;

    cout << "DFS Traversal starting from node " << startNode << ": ";
    DFS(startNode, adjList, visited);
    cout << endl;

    return 0;
}
