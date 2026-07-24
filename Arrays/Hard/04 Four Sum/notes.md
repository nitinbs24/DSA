# Problem: 4Sum

## Problem Statement
Given an array `nums` of `n` integers, return an array of all the unique quadruplets `[nums[a], nums[b], nums[c], nums[d]]` such that:
`0 <= a, b, c, d < n`, `a`, `b`, `c`, and `d` are distinct, and `nums[a] + nums[b] + nums[c] + nums[d] == target`.

**Link:** https://leetcode.com/problems/4sum/  
**Difficulty:** Medium  
**Topic:** Arrays

---

## Approach
### 1. Better Approach (Hashing)
Use three nested loops for pointers `i`, `j`, and `k`. We need the fourth element `target - (nums[i] + nums[j] + nums[k])`. We maintain a hash set `seen` of elements between `j` and `k`. If the required element is in `seen`, we sort the quadruplet and insert it into a `set` to guarantee uniqueness.

### 2. Optimal Approach (Two Pointers)
Sort the array first. Iterate `i` from 0 to `n-1` and `j` from `i+1` to `n-1`, skipping duplicates for both `i` and `j`. For each pair `(nums[i], nums[j])`, use two pointers: `left = j+1` and `right = n-1`.
Calculate `sum = nums[i] + nums[j] + nums[left] + nums[right]`.
- If `sum == target`, add the quadruplet, and move both pointers inward, skipping duplicates for `left` and `right`.
- If `sum < target`, increment `left`.
- If `sum > target`, decrement `right`.

---

## Code
For code implementations, refer to `solution1.cpp` (Hashing) and `solution2.cpp` (Two Pointers).

---

## Output
**Input:** `nums = [1, 0, -1, 0, -2, 2]`, `target = 0`
**Output:**
`-2 -1 1 2`
`-2 0 0 2`
`-1 0 0 1`

---

## Complexity
| | Time | Space |
|---|---|---|
| Better (Hashing) | O(N^3 * log(no. of unique quads)) | O(N) + O(no. of unique quads) |
| Optimal (Two Pointers) | O(N^3) | O(1) (excluding output space) |

---

## Key Takeaway
Similar to 3Sum, we can fix k-2 pointers and use the 2-pointer technique for the remaining 2 elements to reduce the time complexity from O(N^k) to O(N^(k-1)) and avoid extra space.
