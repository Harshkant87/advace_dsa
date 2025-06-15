/*
There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1. You are given a 2D array graph, where graph[u] is an array of nodes that node u is adjacent to. More formally, for each v in graph[u], there is an undirected edge between node u and node v. The graph has the following properties:

There are no self-edges (graph[u] does not contain u).
There are no parallel edges (graph[u] does not contain duplicate values).
If v is in graph[u], then u is in graph[v] (the graph is undirected).
The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.
A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.

Return true if and only if it is bipartite.

 

Example 1:


Input: graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
Output: false
Explanation: There is no way to partition the nodes into two independent sets such that every edge connects a node in one and a node in the other.
Example 2:


Input: graph = [[1,3],[0,2],[1,3],[0,2]]
Output: true
Explanation: We can partition the nodes into two sets: {0, 2} and {1, 3}.

*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    // Helper function to perform DFS and try to color the graph using 2 colors
    bool dfsColor(vector<vector<int>>& graph, vector<int>& colors, int node, int color) {
        // Assign the current node the given color (either 0 or 1)
        colors[node] = color;

        // Visit all adjacent nodes
        for (int nbr : graph[node]) {
            // If the neighbor hasn't been colored yet
            if (colors[nbr] == -1) {
                // Recursively color it with the opposite color (1 - color)
                if (!dfsColor(graph, colors, nbr, 1 - color))
                    return false; // If coloring fails down the path, return false
            }
            // If the neighbor has the same color as the current node
            else if (colors[nbr] == colors[node]) {
                // The graph is not bipartite
                return false;
            }
        }

        // Successfully colored all connected nodes
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        // Initialize all nodes as uncolored (-1)
        vector<int> colors(n, -1);

        // Try to color each component of the graph (handles disconnected graphs)
        for (int i = 0; i < n; ++i) {
            if (colors[i] == -1) {
                // Start DFS coloring with color 0
                if (!dfsColor(graph, colors, i, 0))
                    return false; // If any component is not bipartite, return false
            }
        }

        // If all components are bipartite
        return true;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> graph1 = {{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}};
    vector<vector<int>> graph2 = {{1, 3}, {0, 2}, {1, 3}, {0, 2}};

    cout << boolalpha; // Print boolean values as true/false
    cout << "Graph 1 is bipartite: " << solution.isBipartite(graph1) << endl; // Output: false
    cout << "Graph 2 is bipartite: " << solution.isBipartite(graph2) << endl; // Output: true

    return 0;
}