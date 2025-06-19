/*
articulation points in a graph are vertices that, when removed, increase the number of connected components in the graph.
steps to find articulation points using DFS:
1. Initialize discovery time and low values for each vertex.
2. Perform DFS traversal, updating discovery and low values.
3. For each vertex, check if it is an articulation point based on the discovery and low values.

time complexity: O(V + E), where V is the number of vertices and E is the number of edges.
space complexity: O(V) for storing discovery and low values.

*/

#include <iostream>
#include <vector>

using namespace std;

// User function Template for C++

class Solution {
  private:
  
  int timer = 0;
  
  void dfs(int node, int parent, vector<int> adj[],
                                vector<int> &timeToReach,
                                vector<int> &lowestTime,
                                vector<bool> &markArticulation,
                                vector<bool> &visited){
                                    
        visited[node] = true;
        timeToReach[node] = lowestTime[node] = timer++;
        int child = 0;
        
        for(int nbr: adj[node]){
            if(nbr == parent) continue;
            
            if(visited[nbr] == false){
                dfs(nbr, node, adj, timeToReach, lowestTime, markArticulation, visited);
                lowestTime[node] = min(lowestTime[node], lowestTime[nbr]); // update the lowest reachable time
                
                if(lowestTime[nbr] >= timeToReach[node] && parent != -1) // if the lowest reachable time of the neighbor
                // is greater than or equal to the discovery time of the current node,
                // then the current node is an articulation point
                    markArticulation[node] = true; 
                
                child++;
            }
            else{
                lowestTime[node] = min(lowestTime[node], timeToReach[nbr]);
            }
        }
        if(child > 1 && parent == -1) // if the current node is the root and has more than one child,
        // then it is an articulation point
            markArticulation[node] = true;
                                    
    }
  
  public:
    vector<int> articulationPoints(int V, vector<int> adj[]) {
        // Code here
        vector<int>timeToReach(V), lowestTime(V); // to store discovery time and lowest reachable time
        vector<bool>visited(V, false), markArticulation(V, false); // to mark articulation points
        
        for(int i = 0; i < V; i++){
            if(visited[i] == false) // Perform DFS for unvisited nodes
                dfs(i, -1, adj, timeToReach, lowestTime, markArticulation, visited);
        }
        
        vector<int>ans;
        for(int i = 0; i < V; i++)
            if(markArticulation[i] == true) // if the node is an articulation point
                ans.push_back(i);
        
        if(ans.size() == 0) return {-1};
        return ans;
    }
};

int main() {
    int V = 5; // Number of vertices
    vector<int> adj[V];
    
    // Example graph edges
    adj[0] = {1, 2};
    adj[1] = {0, 2, 3};
    adj[2] = {0, 1};
    adj[3] = {1, 4};
    adj[4] = {3};

    Solution sol;
    vector<int> articulationPoints = sol.articulationPoints(V, adj);
    
    cout << "Articulation Points: ";
    for (int point : articulationPoints) {
        cout << point << " ";
    }
    
    return 0;
}