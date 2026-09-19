# Problem: Set Matrix Zeroes

## Problem Statement
Given an `m x n` integer matrix `matrix`, if an element is `0`, set its entire row and column to `0`'s.

You must do it **in place**.

**Link:** [LeetCode 73 - Set Matrix Zeroes](https://leetcode.com/problems/set-matrix-zeroes/)  
**Difficulty:** Medium  
**Topic:** Arrays, Matrix

---

## Approach

### Approach 1: Brute Force (Placeholder / Marker `-1`)
Directly changing an entire row and column to `0` upon encountering a zero cell corrupts other cells that haven't been scanned yet (causing cascading zeros across the whole matrix).
1. Traverse every cell `(i, j)` in the matrix.
2. If `matrix[i][j] == 0`:
   - Mark all non-zero elements in row `i` with a dummy marker (e.g., `-1`).
   - Mark all non-zero elements in column `j` with `-1`.
   - Existing `0` cells are **not** altered so they can still trigger row and column zeroing.
3. In a second pass, replace all `-1` markers with `0`.
- **Drawbacks:** 
  - Time-expensive: For every zero cell, scanning its row and column takes $O(M + N)$, leading to $O((M \times N) \times (M + N))$ time overall.
  - Fragile: Fails if `-1` is an actual valid element of the original matrix.

### Approach 2: Better (Row and Column Marker Arrays)
Instead of modifying matrix elements to a dummy value during traversal, track which rows and columns must be zeroed using auxiliary marker arrays:
1. Maintain two 1D tracker arrays:
   - `row[m]` initialized to `0` (tracks rows needing zeroing).
   - `col[n]` initialized to `0` (tracks columns needing zeroing).
2. **First Pass:** Traverse the matrix. Whenever `matrix[i][j] == 0`, set `row[i] = 1` and `col[j] = 1`.
3. **Second Pass:** Traverse the matrix again. If `row[i] == 1` or `col[j] == 1`, set `matrix[i][j] = 0`.
- **Complexity:** Eliminates redundant row/column traversals, running in $O(M \times N)$ time with $O(M + N)$ extra memory.

### Approach 3: Optimal (In-Place Markers using First Row & First Column)
To achieve true $O(1)$ auxiliary space, reuse the matrix's own **first row** (`matrix[0][..]`) and **first column** (`matrix[..][0]`) as the marker arrays instead of allocating new memory:
1. Since cell `matrix[0][0]` overlaps both the first row and first column, determine independently whether the first row and first column initially contain any zeros:
   - `firstRowZero = true` if any element in `matrix[0][..]` is `0`.
   - `firstColZero = true` if any element in `matrix[..][0]` is `0`.
2. **Marking Inner Matrix:** Traverse cells from row `1` to `m-1` and column `1` to `n-1`. If `matrix[i][j] == 0`, mark its row header `matrix[i][0] = 0` and column header `matrix[0][j] = 0`.
3. **Updating Inner Matrix:** Traverse from row `1` to `m-1` and column `1` to `n-1`. If `matrix[i][0] == 0` or `matrix[0][j] == 0`, set `matrix[i][j] = 0`.
4. **Handling First Row & First Column:**
   - If `firstRowZero` is `true`, set all elements in the first row to `0`.
   - If `firstColZero` is `true`, set all elements in the first column to `0`.
- **Complexity:** Achieves $O(M \times N)$ time with $O(1)$ auxiliary space.

---

## Code

### Solution 1: Brute Force (Marking with -1)
```cpp
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

        // Traverse each cell of the matrix
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // If current cell is zero
                if (matrix[i][j] == 0) {
                    // Mark all elements in this row as -1 (except existing zeros)
                    for (int col = 0; col < n; col++) {
                        if (matrix[i][col] != 0)
                            matrix[i][col] = -1;
                    }
                    // Mark all elements in this column as -1 (except existing zeros)
                    for (int row = 0; row < m; row++) {
                        if (matrix[row][j] != 0)
                            matrix[row][j] = -1;
                    }
                }
            }
        }

        // Second pass: replace all -1 markers with 0
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == -1)
                    matrix[i][j] = 0;
            }
        }
    }
};

int main() {
    // Example matrix
    vector<vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};
    
    // Create Solution object
    Solution sol;
    // Call function to modify matrix
    sol.setZeroes(matrix);
    
    // Print final matrix
    for (auto row : matrix) {
        for (auto val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}
```

### Solution 2: Better (Marker Arrays)
```cpp
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
```

### Solution 3: Optimal (In-Place Markers O(1) Space)
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to set entire row and column to 0 if an element in the matrix is 0 (Optimal O(1) space)
    void setZeroes(vector<vector<int>>& matrix) {
        // Get dimensions of matrix
        int m = matrix.size();
        int n = matrix[0].size();

        // Flag to track if first row should be zeroed
        bool firstRowZero = false;
        // Flag to track if first column should be zeroed
        bool firstColZero = false;

        // Check if first row has any zero
        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == 0) {
                firstRowZero = true;
                break;
            }
        }

        // Check if first column has any zero
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                firstColZero = true;
                break;
            }
        }

        // Mark rows and columns in first row/column
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Set matrix cells to zero based on markers
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Handle first row
        if (firstRowZero) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }

        // Handle first column
        if (firstColZero) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};

int main() {
    Solution obj;
    vector<vector<int>> matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    obj.setZeroes(matrix);
    for (auto row : matrix) {
        for (auto val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}
```

---

## Output

**Sample Input 1:**
```
matrix = [
  [1, 1, 1],
  [1, 0, 1],
  [1, 1, 1]
]
```

**Sample Output 1:**
```
1 0 1 
0 0 0 
1 0 1 
```

**Sample Input 2:**
```
matrix = [
  [0, 1, 2, 0],
  [3, 4, 5, 2],
  [1, 3, 1, 5]
]
```

**Sample Output 2:**
```
0 0 0 0 
0 4 5 0 
0 3 1 0 
```

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Approach 1 (Brute Force) | O((M × N) × (M + N)) | O(1) |
| Approach 2 (Better - Marker Arrays) | O(M × N) | O(M + N) |
| Approach 3 (Optimal - In-Place) | O(M × N) | O(1) |

*(Where M is the number of rows and N is the number of columns of the matrix.)*

---

## Key Takeaway
To optimize space from $O(M + N)$ to $O(1)$, embed the row and column state tracking directly into the input matrix's first row and first column (`matrix[0][..]` and `matrix[..][0]`), while using two independent boolean flags to isolate the state of the first row and first column themselves.
