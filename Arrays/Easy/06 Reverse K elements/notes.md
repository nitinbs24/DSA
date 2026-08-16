# Problem: Rotate Array by K Elements

## Problem Statement
Given an integer array `nums`, rotate the array to the right (or left) by `k` steps, where `k` is a non-negative integer.

**Link:** [LeetCode - Rotate Array](https://leetcode.com/problems/rotate-array/)  
**Difficulty:** Medium  
**Topic:** Arrays, Two Pointers, Math

---

## Approach

### Approach 1: Optimal (Reversal Algorithm)
Rotating an array by shifting elements one by one takes O(N*K) time, and using a temporary array takes O(N) extra space. We can optimize this to O(N) time and O(1) space using the **Reversal Algorithm**.

1. **Normalize `k`:** Since rotating by `n` (the size of the array) brings the array back to its original state, we first normalize `k` by setting `k = k % n`.
2. **Right Rotation:**
   - Step 1: Reverse the entire array (indices `0` to `n-1`).
   - Step 2: Reverse the first `k` elements (indices `0` to `k-1`).
   - Step 3: Reverse the remaining `n-k` elements (indices `k` to `n-1`).
3. **Left Rotation:**
   - Step 1: Reverse the first `k` elements (indices `0` to `k-1`).
   - Step 2: Reverse the remaining `n-k` elements (indices `k` to `n-1`).
   - Step 3: Reverse the entire array (indices `0` to `n-1`).

---

## Code

### Approach 1 (Optimal)
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseArray(vector<int>& nums, int start, int end) {
        while (start < end) {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }

    vector<int> rotateArray(vector<int>& nums, int k, string direction) {
        int n = nums.size();
        if (n == 0 || k == 0) return nums;
        k = k % n;

        if (direction == "right") {
            reverseArray(nums, 0, n - 1);
            reverseArray(nums, 0, k - 1);
            reverseArray(nums, k, n - 1);
        } 
        else if (direction == "left") {
            reverseArray(nums, 0, k - 1);
            reverseArray(nums, k, n - 1);
            reverseArray(nums, 0, n - 1);
        }
        return nums;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 2;
    string dir = "right";
    
    vector<int> result = sol.rotateArray(nums, k, dir);
    
    for (int num : result) {
        cout << num << " ";
    }
    return 0;
}
```

---

## Output
```
Input: nums = [1, 2, 3, 4, 5, 6, 7], k = 2, direction = "right"
Output: 6 7 1 2 3 4 5
```

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Approach 1 (Optimal) | O(N) | O(1) |

---

## Key Takeaway
The Reversal Algorithm is a classic, highly efficient technique for rotating arrays or strings in-place. Always remember that reversing specific chunks of an array can perfectly simulate a block-shift operation.
