# Problem: Spiral Matrix (Spiral Traversal)

## Problem Statement
Given an `m x n` `matrix`, return all elements of the `matrix` in **spiral order** (clockwise traversal starting from the top-left element).

**Link:** [LeetCode 54 - Spiral Matrix](https://leetcode.com/problems/spiral-matrix/)  
**Difficulty:** Medium  
**Topic:** Arrays, Matrix, Simulation

---

## Approach

### Boundary Simulation (4-Pointer Shrinking Boundary)
We can simulate the clockwise spiral movement by defining four boundaries that represent the current active rectangular perimeter of the matrix:
- `top = 0` (starting row)
- `bottom = m - 1` (ending row)
- `left = 0` (starting column)
- `right = n - 1` (ending column)

While `left <= right` and `top <= bottom`, we traverse the current perimeter in 4 directional steps and then shrink the boundaries inward:

1. **Move Left to Right** across the `top` row:
   - Traverse `i` from `left` to `right`: append `matrix[top][i]` to `res`.
   - Shrink the top boundary: `top++`.

2. **Move Top to Bottom** down the `right` column:
   - Traverse `i` from `top` to `bottom`: append `matrix[i][right]` to `res`.
   - Shrink the right boundary: `right--`.

3. **Move Right to Left** across the `bottom` row:
   - **Important Guard Condition:** Check `if (top <= bottom)` before executing this loop to avoid re-traversing rows when only a single horizontal row remains.
   - Traverse `i` from `right` down to `left`: append `matrix[bottom][i]` to `res`.
   - Shrink the bottom boundary: `bottom--`.

4. **Move Bottom to Top** up the `left` column:
   - **Important Guard Condition:** Check `if (left <= right)` before executing this loop to avoid re-traversing columns when only a single vertical column remains.
   - Traverse `i` from `bottom` down to `top`: append `matrix[i][left]` to `res`.
   - Shrink the left boundary: `left++`.

Continue until all concentric rectangular layers have been processed.

---

## Code

### Solution: Boundary Simulation
```cpp
#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    vector<int> spiralTraverse(vector<vector<int>>& nums){
        int top=0;
        int right=nums[0].size()-1;
        int bottom=nums.size()-1;
        int left=0;

        vector<int> res;

        while(left<=right && top<=bottom){

            for(int i=left;i<=right;i++){
                res.push_back(nums[top][i]);
            }
            top++;

            for(int i=top;i<=bottom;i++){
                res.push_back(nums[i][right]);
            }
            right--;

            if(top<=bottom){
                for(int i=right;i>=left;i--){
                    res.push_back(nums[bottom][i]);
                }
                bottom--;
            }

            if(left<=right){
                for(int i=bottom;i>=top;i--){
                    res.push_back(nums[i][left]);
                }
                left++;
            }
        }
        return res;
    }
};


int main(){
    Solution sol;

    vector<vector<int>> nums {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<int> res = sol.spiralTraverse(nums);

    for(auto num: res){
        cout<<num<<" ";
    } 
    cout<<endl;
}
```

---

## Output

**Sample Input 1:**
```
matrix = [
  [1, 2, 3],
  [4, 5, 6],
  [7, 8, 9]
]
```

**Sample Output 1:**
```
1 2 3 6 9 8 7 4 5 
```

**Sample Input 2:**
```
matrix = [
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9, 10, 11, 12]
]
```

**Sample Output 2:**
```
1 2 3 4 8 12 11 10 9 5 6 7
```

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Optimal (Boundary Simulation) | O(M × N) | O(1) |

*(Note: Time complexity is O(M × N) because every element is traversed exactly once. Space complexity is O(1) auxiliary space excluding the O(M × N) space required to store and return the result vector.)*

---

## Key Takeaway
Maintain four boundary pointers (`top`, `bottom`, `left`, `right`) and peel off layers one by one. Always include guard conditions (`if (top <= bottom)` and `if (left <= right)`) before the backward sweeps to prevent duplicate traversal on non-square or 1D remaining submatrices.
