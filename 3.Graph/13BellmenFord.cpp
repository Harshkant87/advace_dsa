/*
This code implements the Bellman-Ford algorithm to 
find the shortest path from a source vertex to all other vertices in a weighted graph.
it also detects negative weight cycles.

space Complexity: O(V), where V is the number of vertices, for storing the distance array.
time Complexity: O(V * E), where V is the number of vertices and E is the number of edges.

*/

#include <iostream>
#include <vector>

using namespace std;

// User function Template for C++

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int>dist(V, 1e8);
        dist[src] = 0;
        
        for(int i = 0; i < V; i++){ // N - 1 iteraion
            for(vector<int> edge: edges){ // traverse all edges
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];
                
                if(dist[u] != 1e8 && dist[u] + w < dist[v])
                    dist[v] = dist[u] + w;
            }
        }
        
        // Nth iternation
        // if we can still relax the edge, then there is a negative weight cycle
            for(vector<int> edge: edges){
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];
                
                if(dist[u] != 1e8 && dist[u] + w < dist[v]) // if we can still relax the edge
                    return {-1};
            }
        
        return dist;
    }
};

int main() {
    int V = 5; // Number of vertices
    vector<vector<int>> edges = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}
    };
    int src = 0; // Source vertex

    Solution obj;
    vector<int> result = obj.bellmanFord(V, edges, src);

    for (int i = 0; i < result.size(); i++) {
        if (result[i] == 1e8) {
            cout << "Vertex " << i << " is unreachable from source." << endl;
        } else {
            cout << "Shortest distance from source to vertex " << i << " is " << result[i] << endl;
        }
    }

    return 0;
}