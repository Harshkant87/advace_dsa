/*
There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.

 

Example 1:


Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2
Example 2:


Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    void dfs(vector<vector<int>>&adj, vector<bool>&vis, int node){
        vis[node] = true;
        for(int nbrs: adj[node]){
            if(vis[nbrs] == false)
                dfs(adj, vis, nbrs);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>>adj(n);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                else{
                    if(isConnected[i][j] == 1){ // If there is a direct connection
                        // Add the edge in the adjacency list
                        adj[i].push_back(j);
                        adj[j].push_back(i);
                    }
                }
            }
        }

        vector<bool>vis(n, false);
        int provinceCount = 0;
        for(int i = 0; i < n; i++){
            if(vis[i] == false){
                provinceCount++; // Increment province count
                // Call DFS to mark all connected nodes
                dfs(adj, vis, i);
            }
        }
        return provinceCount;

    }
};

int main() {
    Solution obj;
    vector<vector<int>> isConnected1 = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    cout << obj.findCircleNum(isConnected1) << endl; // Output: 2

    vector<vector<int>> isConnected2 = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    cout << obj.findCircleNum(isConnected2) << endl; // Output: 3

    return 0;
}