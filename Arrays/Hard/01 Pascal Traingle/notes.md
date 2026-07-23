# Problem: Pascal's Triangle

## Problem Statement
The Pascal's Triangle problem typically has two main variations:
1. Generate the entire Pascal's Triangle up to `N` rows.
2. Given a row number `N`, generate just the `N`-th row of Pascal's Triangle.

In Pascal's Triangle, each number is the sum of the two numbers directly above it. The edges of the triangle are always `1`. The elements in the `N`-th row also represent the combinations `(N-1)C(r)` where `r` ranges from `0` to `N-1`.

**Link:** [LeetCode 118 - Pascal's Triangle](https://leetcode.com/problems/pascals-triangle/) | [LeetCode 119 - Pascal's Triangle II](https://leetcode.com/problems/pascals-triangle-ii/)  
**Difficulty:** Easy / Medium (Placed in Hard structurally for combinatorics concepts)  
**Topic:** Arrays, Math

---

## Approach

### Approach 1: Generating the Entire Triangle (Dynamic Programming / Simulation)
This approach builds the triangle row by row. We initialize a 2D array (or vector of vectors). The first element and the last element of every row are always `1`. For any other element at row `i` and column `j`, the value is the sum of the elements directly above it from the previous row: `triangle[i-1][j-1] + triangle[i-1][j]`. 
This solves the first variation of the problem by simulating the construction of all `N` rows.

### Approach 2: Generating the N-th Row Directly (Optimal Math using Combinatorics)
If we only need the `N`-th row, calculating the entire triangle takes $O(N^2)$ time and extra space. We can optimize this by using the property of combinations.
The `N`-th row elements are exactly `(N-1)C(0), (N-1)C(1), ..., (N-1)C(N-1)`.
Instead of calculating factorials which can cause integer overflow and take extra time, we can compute the current element based on the previous element in $O(1)$ time.
For the `i`-th term (where `i` ranges from `1` to `N-1`):
`Current_Element = Previous_Element * (N - i) / i`
This allows us to generate the `N`-th row in exactly $O(N)$ time and $O(N)$ space (or $O(1)$ auxiliary space if the output array is not counted).

---

## Code

### Solution 1: Generate Entire Triangle
```cpp
#include<iostream>
#include<vector>
using namespace std;

void pascalTriangle(int n){
    vector<vector<int>> nums;
    for(int i=0;i<n;i++){
        vector<int> row;
        for(int j=0;j<=i;j++){
            if(j==0 || j==i) row.push_back(1);
            else{
                row.push_back(nums[i-1][j-1]+nums[i-1][j]);
            }
            cout<<row.back()<<" ";
        }
        nums.push_back(row);
        cout<<"\n";
    }

}
int main(){
    int n;
    cin>>n;

    pascalTriangle(n);
}
```

### Solution 2: Generate N-th Row
```cpp
#include<iostream>
#include<vector>
using namespace std;

vector<int> pascalTriangleRow(int n){
    vector<int> row;
    long long var = 1;
    row.push_back(var);
    
    for(int i = 1; i < n; i++){
        var = var * (n - i) / i;
        row.push_back(var);
    }
    return row;
}

int main(){
    int n;
    cin >> n;
    
    vector<int> row = pascalTriangleRow(n);
    for(auto& c : row){
        cout << c << " ";
    }
    cout << "\n";
}
```

---

## Output

**Sample Input (for N = 5):**
```
5
```

**Sample Output (from Solution 1 - Entire Triangle):**
```
1 
1 1 
1 2 1 
1 3 3 1 
1 4 6 4 1 
```

**Sample Output (from Solution 2 - N-th Row for N = 5):**
```
1 4 6 4 1 
```

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Approach 1 (Entire Triangle) | O(N²) | O(N²) |
| Approach 2 (N-th Row Math) | O(N) | O(N) |

---

## Key Takeaway
Instead of generating the whole Pascal's Triangle to find a single row, you can use the combinations formula `nCr`. Computing `nCr` sequentially using `Current = Previous * (n - r + 1) / r` helps avoid repetitive work and factorial overflow, allowing you to solve it in $O(N)$ time.
