// number of zigzag array 1

class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        int MOD = 1e9 + 7;
        
        // Use int instead of long long to save memory
        // dp[0][x]: next move must be strictly DOWN (< x)
        // dp[1][x]: next move must be strictly UP (> x)
        vector<vector<int>> dp(2, vector<int>(m, 0));
        vector<vector<int>> next_dp(2, vector<int>(m, 0));
        
        // Base case for length 2
        for (int x = 0; x < m; ++x) {
            dp[0][x] = x;
            dp[1][x] = m - 1 - x;
        }
        
        // Iterate for lengths from 3 up to n
        for (int i = 3; i <= n; ++i) {
            // Compute next_dp[0][y] = sum(dp[1][x]) for x < y
            long long prefix_sum_up = 0; 
            for (int y = 0; y < m; ++y) {
                next_dp[0][y] = prefix_sum_up;
                prefix_sum_up = (prefix_sum_up + dp[1][y]) % MOD;
            }
            
            // Compute next_dp[1][y] = sum(dp[0][x]) for x > y
            long long suffix_sum_down = 0;
            for (int y = m - 1; y >= 0; --y) {
                next_dp[1][y] = suffix_sum_down;
                suffix_sum_down = (suffix_sum_down + dp[0][y]) % MOD;
            }
            
            // Reuse the arrays by swapping instead of allocating new memory
            dp.swap(next_dp);
        }
        
        // Total valid configurations
        long long total_arrays = 0;
        for (int x = 0; x < m; ++x) {
            total_arrays = (total_arrays + dp[0][x] + dp[1][x]) % MOD;
        }
        
        return total_arrays;
    }
};