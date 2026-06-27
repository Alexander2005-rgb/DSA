// set matrix zeroes

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int col0 = 1; // Flag to track if the first column needs to be zeroed

        // Step 1: Scan the matrix and flag rows/cols using the first row/col
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) col0 = 0; // First column has a zero
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0; // Mark row i
                    matrix[0][j] = 0; // Mark col j
                }
            }
        }

        // Step 2: Traverse downwards from row 1 and col 1 to apply the zeroes
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 1; j--) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
            // Step 3: Handle the first column separately using our flag
            if (col0 == 0) {
                matrix[i][0] = 0;
            }
        }
    }
};

