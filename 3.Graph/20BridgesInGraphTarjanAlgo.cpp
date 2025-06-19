/*
bridges in a graph are edges that, when removed, increase the number of connected components in the graph.

steps to find bridges using Tarjan's algorithm:
1. Initialize discovery time and low values for each vertex.
2. Perform DFS traversal, updating discovery and low values.
3. For each edge (u, v), check if low[v] > discovery[u]. If true, (u, v) is a bridge.

time complexity: O(V + E), where V is the number of vertices and E is the number of edges.
space complexity: O(V) for storing discovery and low values.

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    int timer = 1;
    void dfsTarjan(int node, int parent, vector<vector<int>> &adj,
                                         vector<bool> &visited, 
                                         vector<int> &timeToReach,
                                          vector<int> &lowestTime,
                                          vector<vector<int>> &bridges){
        
        visited[node] = true;
        timeToReach[node] = lowestTime[node] = timer; // set discovery time and lowest reachable time
        timer++;

        for(int nbr: adj[node]){
            if(nbr == parent) // skip the edge to parent
                continue;
            if(visited[nbr] == false){
                dfsTarjan(nbr, node, adj, visited, timeToReach, lowestTime, bridges);
                lowestTime[node] = min(lowestTime[node], lowestTime[nbr]); // update the lowest reachable time
                // if the lowest reachable time of the neighbor is greater than the discovery time of the current node,
                // then the edge (node, nbr) is a bridge

                if(lowestTime[nbr] > timeToReach[node] )
                    bridges.push_back({nbr, node});
            }
            else{
                // if the neighbor is already visited, update the lowest reachable time
                // this means there is a back edge
                lowestTime[node] = min(lowestTime[node], lowestTime[nbr]);
            }
        }

                                          }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>bridges;
        vector<int>timeToReach(n), lowestTime(n); // to store discovery time and lowest reachable time
        vector<bool>visited(n, false); // to keep track of visited nodes

        vector<vector<int>>adj(n);
        for(auto it: connections){ // constructing the undirected adjacency list
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        dfsTarjan(0, 0, adj, visited, timeToReach, lowestTime, bridges);
        return bridges;
    }
};

int main() {
    Solution sol;
    int n = 5;
    vector<vector<int>>connections = {{0, 1}, {1, 2}, {2, 0}, {1, 3}, {3, 4}};
    
    vector<vector<int>>result = sol.criticalConnections(n, connections);
    
    for(auto &bridge : result) {
        cout << bridge[0] << " - " << bridge[1] << endl;
    }
    
    return 0;
}