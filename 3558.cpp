class Solution {
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        const int MOD = 1e9 + 7;
        int n = edges.size() + 1;
        
        // Build adjacency list
        vector<vector<int>> adj(n + 1);
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        // BFS/DFS to find depths and parent of each node
        vector<int> depth(n + 1, -1);
        vector<int> parent(n + 1, 0);
        depth[1] = 0;
        
        queue<int> q;
        q.push(1);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                if (depth[v] == -1) {
                    depth[v] = depth[u] + 1;
                    parent[v] = u;
                    q.push(v);
                }
            }
        }
        
        // Find max depth
        int maxDepth = 0;
        for (int i = 1; i <= n; i++) {
            maxDepth = max(maxDepth, depth[i]);
        }
        
        // The path length from root to any node at maxDepth is maxDepth
        // (number of edges = depth)
        int pathLength = maxDepth;
        
        // We need number of ways to assign 1 or 2 to each of pathLength edges
        // such that the sum is odd.
        // Sum is odd iff an odd number of edges have weight 1.
        // Number of ways = C(pathLength, 1) + C(pathLength, 3) + C(pathLength, 5) + ...
        // = 2^(pathLength - 1)
        
        // Compute 2^(pathLength - 1) mod MOD
        if (pathLength == 0) return 0;
        
        long long ans = 1;
        long long base = 2;
        int exp = pathLength - 1;
        while (exp > 0) {
            if (exp & 1) ans = (ans * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        
        return (int)ans;
    }
};
