/*

disjoint set union by rank
This code implements a Disjoint Set Union (DSU) or Union-Find data structure with path compression and union by rank.
It provides methods to find the parent of a node, union two sets, and check if two nodes are in the same set.
Time Complexity: O(α(N)), where α is the inverse Ackermann function, which grows very slowly, making it nearly constant for practical input sizes.
space Complexity: O(N), where N is the number of nodes, for storing the parent and rank arrays.

*/

#include <iostream> // Includes all standard libraries
#include <vector>  // For using vectors
#include <algorithm> // For using algorithms like min, max, etc.
using namespace std;

// Disjoint Set Union (Union-Find) with Union by Rank optimization
class DisjointSet {
    vector<int> rank, parent;

public:
    // Constructor initializes parent and rank arrays
    DisjointSet(int n) {
        rank.resize(n + 1, 0);    // Rank initialized to 0 for all elements
        parent.resize(n + 1);     // Parent array of size n+1

        for (int i = 0; i <= n; i++) {
            parent[i] = i;        // Initially, every node is its own parent (self root)
        }
    }

    // Find ultimate parent with path compression
    int findUPar(int node) {
        if (node == parent[node]) // If node is its own parent, return it
            return node;
        return parent[node] = findUPar(parent[node]); // Path compression: flatten the tree
    }

    // Union two sets by rank
    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u); // Find ultimate parent of u
        int ulp_v = findUPar(v); // Find ultimate parent of v

        if (ulp_u == ulp_v) return; // Already in the same set, do nothing

        // Attach the smaller rank tree under the larger rank tree
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            // If ranks are equal, make one root of the other and increase its rank
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

int main() {
    DisjointSet ds(7); // Create disjoint set for 7 elements (1 to 7)

    // Perform unions on disjoint sets
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);

    // Check if 3 and 7 are in the same set
    if (ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Same\n"; // They are connected
    }
    else {
        cout << "Not same\n"; // They are not connected
    }

    // Connect the sets containing 3 and 7
    ds.unionByRank(3, 7);

    // Check again if 3 and 7 are in the same set
    if (ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Same\n"; // Now they are connected
    }
    else {
        cout << "Not same\n";
    }

    return 0;
}
