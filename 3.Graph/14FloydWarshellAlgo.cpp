/*
floyd-Warshall Algorithm
The Floyd-Warshall algorithm is a dynamic programming algorithm for finding the shortest paths in a weighted graph
 with positive or negative edge weights (but with no negative cycles). 
 It can also be used to find the transitive closure of a graph.

 we can use the Floyd-Warshall algorithm to find the shortest path between all pairs of vertices in a graph.
Time Complexity: O(V^3), where V is the number of vertices in the graph.
Space Complexity: O(V^2), where V is the number of vertices in the graph, for storing the distance matrix.

for negative weight cycle detection, 
we can check if the distance from a vertex to itself is negative after running the algorithm.

*/

#include <iostream>
#include <vector>

using namespace std;

// User function template for C++

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        // Code here
        int n = dist.size();
        
        for(int via = 0; via < n; via++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(dist[i][via] == 100000000 || dist[via][j] == 100000000) continue;
                    dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                }
            }
        }
        
        // for i 0 -> n, if dist[i][i] < 0, it means it contains negative cycle.
        
        return;
    }
};

int main() {
    int n = 4; // Number of vertices
    // 100000000 is used to represent infinity (no path)
    vector<vector<int>> dist = {
        {0, 5, 100000000, 10},
        {100000000, 0, 2, 100000000},
        {100000000, 3, 0, 1},
        {100000000, 100000000, 100000000, 0}
    };

    Solution sol;
    sol.floydWarshall(dist);

    // Print the distance matrix
    for (const auto &row : dist) {
        for (int val : row) {
            if (val == 100000000) cout << "INF ";
            else cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}