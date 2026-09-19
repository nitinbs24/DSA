#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to set entire row and column to 0 if an element in the matrix is 0
    void setZeroes(vector<vector<int>>& matrix) {
        // Get number of rows
        int m = matrix.size();
        // Get number of columns
        int n = matrix[0].size();

        // Create row marker array
        vector<int> row(m, 0);
        // Create column marker array
        vector<int> col(n, 0);

        // First pass: mark rows and columns that need to be zeroed
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // If element is zero, mark its row and column
                if (matrix[i][j] == 0) {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }

        // Second pass: set cells to zero based on markers
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // If the row or column is marked, set cell to zero
                if (row[i] == 1 || col[j] == 1) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

int main() {
    // Create the matrix
    vector<vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};
    
    // Create Solution object
    Solution obj;
    // Call function
    obj.setZeroes(matrix);
    
    // Print the updated matrix
    for (auto row : matrix) {
        for (auto val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}
