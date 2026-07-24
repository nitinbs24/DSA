# Problem: 3Sum

## Problem Statement
Given an integer array nums, return all the triplets `[nums[i], nums[j], nums[k]]` such that `i != j`, `i != k`, and `j != k`, and `nums[i] + nums[j] + nums[k] == 0`. Notice that the solution set must not contain duplicate triplets.

**Link:** https://leetcode.com/problems/3sum/  
**Difficulty:** Medium  
**Topic:** Arrays

---

## Approach
### 1. Brute / Better Approach (Hashing)
Iterate with two nested loops for `i` and `j`. For the third element, we need `-(nums[i] + nums[j])`. Instead of a third loop, we can look for this value in a hash set that stores elements we have seen so far between `i` and `j`. To avoid duplicate triplets, we can sort each triplet and insert it into a `set` of vectors.

### 2. Optimal Approach (Two Pointers)
Sort the array first. Iterate `i` from 0 to `n-1`. For each `i`, use two pointers: `left` pointing to `i+1` and `right` pointing to `n-1`.
Calculate `sum = nums[i] + nums[left] + nums[right]`.
- If `sum == 0`, we found a triplet. Add it to our answer, and move `left` and `right` inward while skipping duplicates.
- If `sum < 0`, we need a larger sum, so increment `left`.
- If `sum > 0`, we need a smaller sum, so decrement `right`.
To avoid duplicates, we also skip duplicate values for the `i` pointer.

---

## Code
For code implementations, refer to `solution1.cpp` (Hashing with Set) and `solution2.cpp` (Two Pointers).

---

## Output
**Input:** `nums = [-1,0,1,2,-1,-4]`
**Output:** 
`-1 -1 2`
`-1 0 1`

---

## Complexity
| | Time | Space |
|---|---|---|
| Better (Hashing) | O(N^2 * log(no. of unique triplets)) | O(N) + O(no. of unique triplets) |
| Optimal (Two Pointers) | O(N log N + N^2) ~ O(N^2) | O(1) (excluding output space) |

---

## Key Takeaway
Sorting the array transforms the problem so we can use the two-pointer technique, which elegantly avoids the O(N) space overhead of hashing and makes duplicate handling straightforward.
