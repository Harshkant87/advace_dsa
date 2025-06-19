/*
kruskalAlgo.cpp
This file contains the implementation of Kruskal's algorithm for finding the Minimum Spanning Tree (MST) of a graph.

It uses a Disjoint Set Union (DSU) data structure to efficiently manage the connected components of the graph.
//     DisjointSet ds(7); // Create a DSU for 7 elements (1 to 7)
//     ds.unionByRank(1, 2); // Union nodes 1 and 2
//     ds.findPar(2); // Find the parent of node 2

step 1 : sort the edges based on their weights
step 2 : iterate through the edges and for each edge, check if the two vertices are in the same set using findUPar
step 3 : if they are not in the same set, union them using unionByRank and add the edge to the MST

time complexity: O(E log E + E * α(N)), where E is the number of edges, and α(N) is the inverse Ackermann function, which grows very slowly.
space complexity: O(N), where N is the number of nodes, for storing the parent and rank arrays.

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class DisjointSet {
    vector<int> Rank, Parent, Size;

public:
    DisjointSet(int n) {
        Rank.resize(n + 1, 0);
        Parent.resize(n + 1);
        Size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            Parent[i] = i;
        }
    }

    int FindUpar(int node) {
        if (Parent[node] == node) return node;
        return Parent[node] = FindUpar(Parent[node]); 
    }

    void UnionByRank(int u, int v) {
        int ulp_u = FindUpar(u);
        int ulp_v = FindUpar(v);

        if (ulp_u == ulp_v) return;

        if (Rank[ulp_u] < Rank[ulp_v]) {
            Parent[ulp_u] = ulp_v;
        } else if (Rank[ulp_u] > Rank[ulp_v]) {
            Parent[ulp_v] = ulp_u;
        } else {
            Parent[ulp_v] = ulp_u;
            Rank[ulp_u]++;
        }
    }

    void UnionBySize(int u, int v) {
        int ulp_u = FindUpar(u);
        int ulp_v = FindUpar(v);

        if (ulp_u == ulp_v) return;

        if (Size[ulp_u] < Size[ulp_v]) {
            Parent[ulp_u] = ulp_v;
            Size[ulp_v] += Size[ulp_u];
        } else {
            Parent[ulp_v] = ulp_u;
            Size[ulp_u] += Size[ulp_v];
        }
    }
};

class Solution {
public:
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        DisjointSet ds(V);
        vector<vector<int>> newEdges;

        
        for (auto &it : edges) {
            newEdges.push_back({it[2], it[0], it[1]});
        }

        sort(newEdges.begin(), newEdges.end()); // Sort edges based on weight

        int sum = 0;

        for (auto &it : newEdges) {
            int wt = it[0];
            int u = it[1];
            int v = it[2];

            if (ds.FindUpar(u) != ds.FindUpar(v)) { // If u and v are not in the same set
                ds.UnionByRank(u, v); // Union the sets
                sum += wt; // Add the weight to the sum
            }
        }

        return sum;
    }
};

int main() {
    Solution sol;
    int V = 4; // Number of vertices
    vector<vector<int>> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    int mstWeight = sol.kruskalsMST(V, edges);
    cout << "Weight of the Minimum Spanning Tree: " << mstWeight << endl;

    return 0;
}