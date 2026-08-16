# Problem: Move Zeroes to End

## Problem Statement
Given an integer array `nums`, move all `0`'s to the end of it while maintaining the relative order of the non-zero elements. The operation must be done in-place without making a copy of the array.

**Link:** [LeetCode - Move Zeroes](https://leetcode.com/problems/move-zeroes/)  
**Difficulty:** Easy  
**Topic:** Arrays, Two Pointers

---

## Approach

### Approach 1: Optimal (Two Pointers)
We can solve this efficiently in a single pass using the two-pointer technique to achieve O(1) extra space.
1. **Find the first zero:** Iterate through the array to find the index of the first `0` and assign it to pointer `j`. If no zeros are found, we simply return.
2. **Swap non-zeros:** Use another pointer `i` starting from `j+1` to scan the rest of the array.
3. Whenever `nums[i]` is non-zero, we swap `nums[i]` with `nums[j]` (which is a zero).
4. After swapping, we increment `j` by `1` so it points to the next available zero position.

---

## Code

### Approach 1 (Optimal)
```cpp
#include<iostream>
#include<vector>

using namespace std;

void moveZeroes(vector<int>& nums){
    int j = -1;
    
    // Step 1: Find the first zero
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] == 0){
            j = i;
            break;
        }
    }
    
    // If no zero is found, no need to do anything
    if(j == -1) return;

    // Step 2: Swap non-zero elements with the zero at index j
    for(int i = j + 1; i < nums.size(); i++){
        if(nums[i] != 0){
            swap(nums[i], nums[j]);
            j++;
        }
    }

    // Print the array
    for(int num : nums) cout << num << " ";
}

int main(){
    vector<int> nums {1, 0, 2, 0, 0, 3, 8, 5};
    moveZeroes(nums);
}
```

---

## Output
```
Input: nums = [1, 0, 2, 0, 0, 3, 8, 5]
Output: 1 2 3 8 5 0 0 0 
```

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Approach 1 (Optimal) | O(N) | O(1) |

---

## Key Takeaway
To move specific elements (like zeros) to one side while preserving the relative order of other elements, a two-pointer approach works perfectly: use one pointer to track the target insertion position and another to traverse and find valid elements to swap.
