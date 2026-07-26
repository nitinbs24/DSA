# Problem: Search in 2D Matrix

## Problem Statement
Write an efficient algorithm that searches for a value `target` in an `m x n` integer matrix `matrix`. This matrix has the following properties:
1. Integers in each row are sorted from left to right.
2. The first integer of each row is greater than the last integer of the previous row.

**Link:** https://leetcode.com/problems/search-a-2d-matrix/
**Difficulty:** Medium  
**Topic:** Binary Search, 2D Arrays

---

## Approach
### Approach 1 (Better - Row Elimination)
We iterate through each row and check if the `target` falls within the range of that row (`matrix[i][0] <= target <= matrix[i][m-1]`). Because the ranges of rows do not overlap, if it falls in a row's range, we binary search that row and immediately return the result.

### Approach 2 (Optimal - Flattening to 1D)
Because the entire matrix is strictly sorted when read row by row, we can logically flatten the 2D matrix into a 1D array of size `N * M`. A 1D index `mid` maps back to 2D coordinates using `row = mid / M` and `col = mid % M`. We perform a standard binary search on this logical 1D array.

---

## Code
```cpp
// Approach 2: Optimal - Flattening to 1D (solution2.cpp)
#include<iostream>
#include<vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix,int target){
    
    int n=matrix.size(),m=matrix[0].size();
    int low=0,high=n*m-1;

    while(low<=high){

        int mid=(low+high)/2;
        int row=mid/m, column=mid%m;

        if(matrix[row][column]==target) return true;
        else if(matrix[row][column]>target) high=mid-1;
        else low=mid+1;
    }

    return false;
}

int main(){
    vector<vector<int>> matrix {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target=3;

    if(searchMatrix(matrix,target)) cout<<"Found\n";
    else cout<<"Not Found\n";
}
```

---

## Output
```
Input: matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}}, target = 3
Output: Found
```

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Approach 1 (Better) | O(N + log M) | O(1) |
| Approach 2 (Optimal) | O(log(N * M)) | O(1) |

---

## Key Takeaway
If a 2D matrix is completely sorted such that it can be flattened into a strictly sorted 1D array, you can use mathematical mapping (`row = mid / cols`, `col = mid % cols`) to perform a standard `O(log(N*M))` binary search.
