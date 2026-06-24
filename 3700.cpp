#include <vector>

using namespace std;

class Solution {
private:
    long long MOD = 1e9 + 7;

    // Helper function to multiply two matrices
    vector<vector<long long>> multiply(const vector<vector<long long>>& A, const vector<vector<long long>>& B) {
        int size = A.size();
        vector<vector<long long>> C(size, vector<long long>(size, 0));
        for (int i = 0; i < size; ++i) {
            for (int k = 0; k < size; ++k) {
                if (A[i][k] == 0) continue;
                for (int j = 0; j < size; ++j) {
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }

    // Helper function for matrix power via binary exponentiation
    vector<vector<long long>> power(vector<vector<long long>> A, long long p) {
        int size = A.size();
        vector<vector<long long>> res(size, vector<long long>(size, 0));
        for (int i = 0; i < size; ++i) res[i][i] = 1; // Identity matrix

        while (p > 0) {
            if (p & 1) res = multiply(res, A);
            A = multiply(A, A);
            p >>= 1;
        }
        return res;
    }

public:
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        
        // Base cases for small arrays
        if (n == 1) return m;
        if (n == 2) return (1LL * m * (m - 1)) % MOD;

        // Total states = 2 * m
        // 0 to m-1: "Next must go down" (meaning we just went up to x)
        // m to 2m-1: "Next must go up" (meaning we just went down to x)
        int states = 2 * m;
        vector<vector<long long>> T(states, vector<long long>(states, 0));

        for (int x = 0; x < m; ++x) {
            // From a 'down' state at x (index x), we must move to a 'up' state at y where y < x
            for (int y = 0; y < x; ++y) {
                T[m + y][x] = 1; 
            }
            // From an 'up' state at x (index m + x), we must move to a 'down' state at y where y > x
            for (int y = x + 1; y < m; ++y) {
                T[y][m + x] = 1;
            }
        }

        // Raise the transition matrix to the power of n-2
        // because we start the state tracking from the second element
        vector<vector<long long>> T_pow = power(T, n - 2);

        // Initial vector after picking the first 2 elements:
        // For every pair (i, j) where i != j:
        // If i < j (went up to j), it contributes 1 to the 'down' state at j (index j).
        // If i > j (went down to j), it contributes 1 to the 'up' state at j (index m + j).
        vector<long long> initial(states, 0);
        for (int j = 0; j < m; ++j) {
            initial[j] = j;         // there are j choices of i < j
            initial[m + j] = m - 1 - j; // there are m - 1 - j choices of i > j
        }

        // Multiply T_pow by the initial vector to get the final state counts
        long long total_valid = 0;
        for (int i = 0; i < states; ++i) {
            long long final_val_i = 0;
            for (int j = 0; j < states; ++j) {
                final_val_i = (final_val_i + T_pow[i][j] * initial[j]) % MOD;
            }
            total_valid = (total_valid + final_val_i) % MOD;
        }

        return total_valid;
    }
};