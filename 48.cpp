// rotate image

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        void rotate(vector<vector<int>>& matrix){

            int n = matrix.size();

            // Transpose the matrix
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    swap(matrix[i][j], matrix[j][i]);
                }
            }

            // Reverse each row
            for (int i = 0; i < n; i++) {
                reverse(matrix[i].begin(), matrix[i].end());
            }
        }

};

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    Solution s;
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    cout << "Original matrix:\n";
    printMatrix(matrix);
    
    s.rotate(matrix);
    
    cout << "\nRotated matrix:\n";
    printMatrix(matrix);
    
    return 0;
}