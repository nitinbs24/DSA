# Problem: Power Set (Subsets)

## Problem Statement
Given an array `nums` of unique integers, return all possible subsets (the power set). The solution set must not contain duplicate subsets, and the subsets can be returned in any order.

**Link:** [LeetCode - Subsets](https://leetcode.com/problems/subsets/)  
**Difficulty:** Medium  
**Topic:** Bit Manipulation, Backtracking, Arrays

---

## Approach

### Approach 1: Optimal (Bitmasking / Bit Manipulation)
An array of size `n` has `2^n` total subsets. Each subset can be represented by a binary sequence of length `n`:
- A `1` at the `i`-th bit position indicates that `nums[i]` is included in the subset.
- A `0` at the `i`-th bit position indicates that `nums[i]` is excluded from the subset.

**Algorithm:**
1. Compute total subsets: `subsets = 1 << n` (`2^n`).
2. Iterate `num` from `0` to `(1 << n) - 1`.
3. For each `num`, check every bit position `i` from `0` to `n - 1` using `num & (1 << i)`:
   - If the `i`-th bit is set (`1`), append `nums[i]` to the current subset.
4. Add the generated subset to the result list `ans`.

---

## Code

### Approach 1 (Bitmasking)
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> getPowerSet(vector<int>& nums) {
        int n = nums.size();
        int subsets = 1 << n;
        vector<vector<int>> ans;

        for (int num = 0; num < subsets; num++) {
            vector<int> subset;

            for (int i = 0; i < n; i++) {
                if (num & (1 << i)) {
                    subset.push_back(nums[i]);
                }
            }

            ans.push_back(subset);
        }

        return ans;
    }
};

int main() {
    vector<int> nums = {5, 7, 8};

    Solution obj;
    vector<vector<int>> subsets = obj.getPowerSet(nums);

    cout << "Initial Input Array: ";
    for (auto num : nums) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Subsets: " << endl;
    for (auto subset : subsets) {
        cout << "[ ";
        for (auto num : subset) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
```

---

## Output
```
Initial Input Array: 5 7 8 
Subsets: 
[ ]
[ 5 ]
[ 7 ]
[ 5 7 ]
[ 8 ]
[ 5 8 ]
[ 7 8 ]
[ 5 7 8 ]
```

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Approach 1 (Bitmasking) | O(N · 2ⁿ) | O(N · 2ⁿ) |

---

## Key Takeaway
Each number from `0` to `(2ⁿ - 1)` acts as a unique bitmask mapping directly to one of the `2ⁿ` subsets of an array of size `N`.
