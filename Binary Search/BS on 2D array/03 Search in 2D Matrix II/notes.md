# Problem: Search in 2D Matrix II

## Problem Statement
Write an efficient algorithm that searches for a value `target` in an `m x n` integer matrix `matrix`. This matrix has the following properties:
1. Integers in each row are sorted in ascending from left to right.
2. Integers in each column are sorted in ascending from top to bottom.
(Unlike Part I, the rows and columns overlap in range).

**Link:** https://leetcode.com/problems/search-a-2d-matrix-ii/
**Difficulty:** Medium  
**Topic:** Binary Search, 2D Arrays, Staircase Search

---

## Approach
### Approach 1 (Better - Binary Search on Rows)
We can iterate through each row, and if the target is within the min and max bounds of that row, we perform a binary search. If it is found, return true. Because ranges overlap, if it's not found, we must continue to the next row.

### Approach 2 (Optimal - Staircase Search)
We can start our search from the Top-Right corner (`row = 0, col = m - 1`). This corner acts like a Binary Search Tree root: all elements to the left are smaller, and all elements below are larger. 
- If `matrix[row][col] == target`, we found it.
- If `matrix[row][col] > target`, the target cannot be in this column, so we eliminate the column by moving left (`col--`).
- If `matrix[row][col] < target`, the target cannot be in this row, so we eliminate the row by moving down (`row++`).

---

## Code
```cpp
// Approach 2: Optimal - Staircase Search (solution2.cpp)
#include<iostream>
#include<vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix,int target){
    
    int n=matrix.size(),m=matrix[0].size();
    int row=0, column=m-1;

    while(row<n && column>=0){
        if(matrix[row][column]==target) return true;
        else if(matrix[row][column]>target) column--;
        else row++;
    }

    return false;
}

int main(){
    vector<vector<int>> matrix {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    int target=5;

    if(searchMatrix(matrix,target)) cout<<"Found\n";
    else cout<<"Not Found\n";
}
```

---

## Output
```
Input: matrix = {{1,4,7,11,15},{2,5,8,12,19},...}, target = 5
Output: Found
```

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Approach 1 (Better) | O(N * log M) | O(1) |
| Approach 2 (Optimal) | O(N + M) | O(1) |

---

## Key Takeaway
When both rows and columns are sorted independently, treat the Top-Right (or Bottom-Left) corner as a decision tree root to eliminate entire rows or columns in `O(1)` time.
