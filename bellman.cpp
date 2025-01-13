#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Structure to represent an edge
struct Edge
{
    int u, v, weight;
};

// Bellman-Ford Algorithm
void bellmanFord(int nodes, int edgesCount, int source, vector<Edge> &edges)
{
    vector<int> distance(nodes + 1, INT_MAX); // Distance array
    distance[source] = 0;                     // Distance to source is 0

    // Relax all edges (nodes - 1) times
    for (int i = 1; i < nodes; i++)
    {
        for (auto &edge : edges)
        {
            if (distance[edge.u] != INT_MAX && distance[edge.u] + edge.weight < distance[edge.v])
            {
                distance[edge.v] = distance[edge.u] + edge.weight;
            }
        }
    }

    // Check for negative weight cycles
    bool hasNegativeCycle = false;
    for (auto &edge : edges)
    {
        if (distance[edge.u] != INT_MAX && distance[edge.u] + edge.weight < distance[edge.v])
        {
            hasNegativeCycle = true;
            break;
        }
    }

    if (hasNegativeCycle)
    {
        cout << "Graph contains a negative weight cycle!" << endl;
    }
    else
    {
        cout << "Shortest distances from source " << source << ":" << endl;
        for (int i = 1; i <= nodes; i++)
        {
            if (distance[i] == INT_MAX)
            {
                cout << "Node " << i << ": INF" << endl;
            }
            else
            {
                cout << "Node " << i << ": " << distance[i] << endl;
            }
        }
    }
}

int main()
{
    int nodes, edgesCount;
    cout << "Enter the number of nodes: ";
    cin >> nodes;

    cout << "Enter the number of edges: ";
    cin >> edgesCount;

    vector<Edge> edges;

    cout << "Enter the edges (u v weight):" << endl;
    for (int i = 0; i < edgesCount; i++)
    {
        int u, v, weight;
        cin >> u >> v >> weight;
        edges.push_back({u, v, weight});
    }

    int source;
    cout << "Enter the source node: ";
    cin >> source;

    bellmanFord(nodes, edgesCount, source, edges);

    return 0;
}