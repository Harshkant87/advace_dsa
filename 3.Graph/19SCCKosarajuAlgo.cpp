/*
SCC (Strongly Connected Components) using Kosaraju's Algorithm
This code implements Kosaraju's algorithm to find all strongly connected components (SCCs) in a directed graph.

SCC -> A strongly connected component is a maximal subgraph where every vertex is reachable from every other vertex in the same component.

Kosraju's Algorithm Steps:
1. Perform a DFS on the original graph to get the finishing order of vertices.
2. Reverse the graph (transpose).
3. Perform DFS on the transposed graph in the order of decreasing finishing times to discover SCCs.

time complexity: O(V + E), where V is the number of vertices and E is the number of edges.
space complexity: O(V + E) for storing the graph and its transpose.

*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

//Position this line where user code will be pasted.
class Solution {
  private:
  
    void dfsTime(int node, vector<bool> &vis, stack<int> &st, vector<vector<int>> &adj){
        vis[node] = true;
        
        for(int nbr: adj[node]){
            if(vis[nbr] == false)
                dfsTime(nbr, vis, st, adj);
        }
        
        st.push(node);
    }
    
    void dfsVis(int node, vector<bool> &visited,  vector<vector<int>> &adjT){
        visited[node] = true;
        
        for(int nbr: adjT[node])
            if(visited[nbr] == false)
                dfsVis(nbr, visited, adjT);
    }
    
  public:
  
    int kosaraju(vector<vector<int>> &adj) {
        // code here
        int V = adj.size();
        vector<bool>vis(V, false);
        stack<int>st;
        
        for(int i = 0; i < V; i++){
            if(vis[i] == false)
                dfsTime(i, vis, st, adj); // Perform DFS to fill the stack with finishing times
        }
        
        vector<vector<int>>adjT(V);
        for(int i = 0; i < V; i++){
            for(int j: adj[i]){
                adjT[j].push_back(i); // Reverse the graph
            }
        }
        
        int countSCC = 0;
        vector<bool>visited(V, false);
        
       while(!st.empty()){
           int i = st.top();
           st.pop();
           
           if(visited[i] == false){
                countSCC++;
                dfsVis(i, visited, adjT); // DFS on stack's top element in the transposed graph
            }
       }   
        return countSCC;
        
    }
};

int main() {
    Solution sol;
    vector<vector<int>> graph = {
        {1},    // 0 -> 1
        {2},    // 1 -> 2
        {0},    // 2 -> 0 (forming a cycle)
        {4},    // 3 -> 4
        {5},    // 4 -> 5
        {3}     // 5 -> 3 (forming another cycle)
    };
    
    int sccCount = sol.kosaraju(graph);
    cout << "Number of strongly connected components: " << sccCount << endl; // Output: 2
    
    return 0;
}