#include <iostream> // Includes all standard C++ libraries
#include <vector>  // For using vectors
using namespace std;

class DisjointSet {
    vector<int> rank, parent, size;

public:
    // Constructor to initialize DSU for n elements
    DisjointSet(int n) {
        rank.resize(n + 1, 0);     // Rank (used if using union by rank)
        parent.resize(n + 1);      // Parent of each node
        size.resize(n + 1);        // Size of each set (used in union by size)

        // Initially, every node is its own parent and size is 1
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    // Find with path compression: flattens tree structure for efficiency
    int findUPar(int node) {
        if (node == parent[node]) // If node is the root, return it
            return node;
        return parent[node] = findUPar(parent[node]); // Recursively find and compress path
    }

    // Union two sets by rank (not used in this main)
    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u); // Ultimate parent of u
        int ulp_v = findUPar(v); // Ultimate parent of v

        if (ulp_u == ulp_v) return; // Already in the same set

        // Attach the tree with lower rank to the one with higher rank
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++; // Increase rank if both were equal
        }
    }

    // Union two sets by size
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u); // Ultimate parent of u
        int ulp_v = findUPar(v); // Ultimate parent of v

        if (ulp_u == ulp_v) return; // Already in the same set

        // Attach smaller set under the larger set and update size
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u]; // Increase size of new root
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

int main() {
    DisjointSet ds(7); // Create a DSU for 7 elements (1 to 7)

    // Merge sets using union by size
    ds.unionBySize(1, 2); // 1-2
    ds.unionBySize(2, 3); // 1-2-3
    ds.unionBySize(4, 5); // 4-5
    ds.unionBySize(6, 7); // 6-7
    ds.unionBySize(5, 6); // 4-5-6-7

    // Check if 3 and 7 are in the same set
    if (ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Same\n"; // Output if they are connected
    }
    else {
        cout << "Not same\n"; // Output if they are not connected
    }

    // Connect 3's set with 7's set
    ds.unionBySize(3, 7);

    // Check again if 3 and 7 are now in the same set
    if (ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Same\n"; // Should output "Same" now
    }
    else {
        cout << "Not same\n";
    }

    return 0;
}
