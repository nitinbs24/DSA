# Problem: Rotate Image by 90 Degrees

## Problem Statement
You are given an `n x n` 2D `matrix` representing an image, rotate the image by **90 degrees clockwise**.

You have to rotate the image **in-place**, which means you have to modify the input 2D matrix directly without allocating another 2D matrix for the optimal approach.

**Link:** [LeetCode 48 - Rotate Image](https://leetcode.com/problems/rotate-image/)  
**Difficulty:** Medium  
**Topic:** Arrays, Matrix, Math

---

## Approach

### Approach 1: Brute Force (Using an Auxiliary Matrix)
When rotating an `n x n` matrix clockwise by 90 degrees, observe where each element lands:
- The first row becomes the last column (`n - 1`).
- The second row becomes the second-to-last column (`n - 2`).
- In general, the element at `matrix[i][j]` maps to index `[j][n - 1 - i]` in the rotated matrix.

**Algorithm:**
1. Create a new matrix `rotated` of size `n x n`.
2. Iterate through each cell `(i, j)` of the original matrix:
   - Assign `rotated[j][n - 1 - i] = matrix[i][j]`.
3. Return `rotated` (or copy it back to `matrix`).
- **Drawback:** Requires $O(N^2)$ additional space, violating the in-place requirement.

### Approach 2: Optimal (Transpose + Reverse Each Row)
A 90-degree clockwise rotation can be decomposed into two distinct transformations that can both be performed in-place:
1. **Transpose the Matrix:** 
   - Swap elements across the main diagonal: swap `matrix[i][j]` with `matrix[j][i]` for all `j > i`.
   - After transposing, rows become columns and columns become rows.
2. **Reverse Each Row:** 
   - Reverse the elements of each row horizontally (`reverse(matrix[i].begin(), matrix[i].end())`).
   - Reversing each row converts the transposed matrix into the exact 90-degree clockwise rotated matrix.

**Why does this work?**
- Original cell: `(i, j)`
- After Transpose: moves to `(j, i)`
- After Row Reverse: column `i` flips to column `n - 1 - i` $\rightarrow$ final position is `(j, n - 1 - i)`, which is precisely a 90° clockwise rotation!

---

## Code

### Solution 1: Brute Force (Auxiliary Matrix)
```cpp
#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    vector<vector<int>> rotate90(vector<vector<int>> nums){


        int n=nums.size(),m=nums[0].size();
        vector<vector<int>> rotated (m,vector<int> (n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                rotated[j][n-i-1]=nums[i][j];
            }
        }
        return rotated;
    }
};

int main(){
    vector<vector<int>> nums {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    for(auto i:nums){
        for(auto j:i) cout<<j<<" ";
        cout<<endl;
    }
    Solution sol;
    vector<vector<int>> rotated=sol.rotate90(nums);

    cout<<"After:\n";
    for(auto i:rotated){
        for(auto j:i) cout<<j<<" ";
        cout<<endl;
    }
}
```

### Solution 2: Optimal (Transpose and Reverse In-Place)
```cpp
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
    public:
    vector<vector<int>> rotate90(vector<vector<int>> nums){


        int n=nums.size(),m=nums[0].size();

        for(int i=0;i<n;i++){
            for(int j=i+1;j<m;j++){
                swap(nums[i][j],nums[j][i]);
            }
        }
        for(int i=0;i<n;i++){
            reverse(nums[i].begin(),nums[i].end());
        }
        return nums;
    }
};

int main(){
    vector<vector<int>> nums {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    for(auto i:nums){
        for(auto j:i) cout<<j<<" ";
        cout<<endl;
    }
    Solution sol;
    vector<vector<int>> rotated=sol.rotate90(nums);

    cout<<"After:\n";
    for(auto i:rotated){
        for(auto j:i) cout<<j<<" ";
        cout<<endl;
    }
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
After:
7 4 1 
8 5 2 
9 6 3 
```

**Sample Input 2:**
```
matrix = [
  [5, 1, 9, 11],
  [2, 4, 8, 10],
  [13, 3, 6, 7],
  [15, 14, 12, 16]
]
```

**Sample Output 2:**
```
After:
15 13 2 5 
14 3 4 1 
12 6 8 9 
16 7 10 11 
```

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Approach 1 (Brute Force) | O(N²) | O(N²) |
| Approach 2 (Optimal - In-Place) | O(N²) | O(1) |

*(Where N is the number of rows and columns of the N x N matrix. Transpose takes O(N²/2) and reversing all rows takes O(N²/2), summing to O(N²).)*

---

## Key Takeaway
Rotating an $N \times N$ matrix 90 degrees clockwise in-place can always be achieved in two elegant linear passes: **Transpose** (swap `[i][j]` with `[j][i]`) followed by **Horizontal Flip** (reverse each individual row). To rotate 90 degrees counter-clockwise instead, reverse each row first and then transpose (or transpose and reverse each column).
