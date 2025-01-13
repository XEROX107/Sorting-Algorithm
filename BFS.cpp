#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to perform BFS on the graph
void BFS(int start, vector<vector<int>> &adjList, vector<bool> &visited)
{
    queue<int> q; // Queue to manage the BFS process

    // Mark the starting node as visited and enqueue it
    visited[start] = true;
    q.push(start);

    cout << "BFS Traversal starting from node " << start << ": ";

    while (!q.empty())
    {
        int current = q.front(); // Get the front element of the queue
        q.pop();
        cout << current << " "; // Print the current node

        // Traverse all adjacent nodes
        for (int neighbor : adjList[current])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true; // Mark as visited
                q.push(neighbor);         // Enqueue the adjacent node
            }
        }
    }

    cout << endl;
}

int main()
{
    int nodes, edges;
    cout << "Enter the number of nodes: ";
    cin >> nodes;

    cout << "Enter the number of edges: ";
    cin >> edges;

    // Adjacency list representation of the graph
    vector<vector<int>> adjList(nodes + 1); // Use 1-based indexing for simplicity

    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u); // For undirected graph, add both directions
    }

    // Visited array to track visited nodes
    vector<bool> visited(nodes + 1, false);

    // Perform BFS starting from node 1 (or any other node)
    int startNode;
    cout << "Enter the starting node for BFS: ";
    cin >> startNode;

    BFS(startNode, adjList, visited);

    return 0;
}
