#include <iostream>
#include <vector>
#include <queue>
#include <utility> // for pair
#include <climits> // for INT_MAX
using namespace std;
// Prim's Algorithm to find Minimum Spanning Tree (MST)
int primMST(int V, vector<vector<pair<int, int>>> &adj)
{
    vector<int> key(V, INT_MAX);  // Minimum weight to connect a vertex
    vector<bool> inMST(V, false); // To track vertices included in MST
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // Start from vertex 0
    key[0] = 0;
    pq.push({0, 0}); // (weight, vertex)
    int totalWeight = 0;
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        if (inMST[u])
            continue; // Skip if already included
        inMST[u] = true;
        totalWeight += key[u];
        // Traverse adjacent vertices
        for (auto &it : adj[u])
        {
            int v = it.first;
            int weight = it.second;
            if (!inMST[v] && weight < key[v])
            {
                key[v] = weight;
                pq.push({key[v], v});
            }
        }
    }
    return totalWeight;
}
int main()
{
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;
    vector<vector<pair<int, int>>> adj(V);
    cout << "Enter edges (u v weight):" << endl;
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // Undirected graph
    }
    int mstWeight = primMST(V, adj);
    cout << "Total weight of Minimum Spanning Tree: " << mstWeight << endl;
    r