/*
spanning tree: A spanning tree of a graph is a subgraph that includes all the vertices of the graph 
and is a tree (i.e., it is connected and acyclic). 
A spanning tree has exactly |V| - 1 edges, where |V| is the number of vertices in the graph.

minimum spanning tree (MST): A minimum spanning tree is a spanning tree with the minimum possible total edge weight.

prims algorithm: Prim's algorithm is a greedy algorithm that finds a minimum spanning tree for a weighted undirected graph.

time complexity: O(E log V), where E is the number of edges and V is the number of vertices in the graph.
space complexity: O(V), where V is the number of vertices in the graph, for storing the parent array and the priority queue.

steps of Prim's algorithm:
1. Initialize a priority queue (min-heap) to store the edges based on their weights.    
2. Start from an arbitrary vertex and add all its edges to the priority queue.
3. While the priority queue is not empty:
   a. Extract the edge with the minimum weight from the priority queue.
   b. If the edge connects to a vertex that is not already included in the MST, add it to the MST and mark the vertex as included.
   c. Add all edges from the newly included vertex to the priority queue.

*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
        vector<bool>vis(V, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> >pq;
        pq.push({0, 0}); // node and weight
        
        int sum = 0;
        while(!pq.empty()){
            
            int node = pq.top().second;
            int wt = pq.top().first;
            
            pq.pop();
            
            if(vis[node] == true) continue; // if already visited, skip
            // if not visited, mark it as visited and add the weight to sum
            vis[node] = true;
            sum += wt;
            
            for(auto nbrs: adj[node]){
                if(vis[nbrs[0]] == false){ // if the neighbor is not visited, add it to the priority queue
                    pq.push({nbrs[1], nbrs[0]});
                }
            }
            
        }
        return sum;
    }
};

int main() {
    int V = 5; // Number of vertices
    vector<vector<int>> adj[V];
    
    // Example graph edges (undirected)
    adj[0] = {{1, 2}, {3, 6}};
    adj[1] = {{0, 2}, {2, 3}, {4, 5}};
    adj[2] = {{1, 3}, {3, 8}};
    adj[3] = {{0, 6}, {1, 8}};
    adj[4] = {{1, 5}};
    
    Solution sol;
    int result = sol.spanningTree(V, adj); 
    
    cout << "Sum of weights of edges in the Minimum Spanning Tree: " << result << endl; 
    
    return 0;
}