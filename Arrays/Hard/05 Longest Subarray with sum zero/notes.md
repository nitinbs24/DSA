# Problem: Longest Subarray with Sum Zero

## Problem Statement
Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.

**Link:** https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1  
**Difficulty:** Medium  
**Topic:** Arrays

---

## Approach
### 1. Brute Force Approach
Iterate through the array with two nested loops. The outer loop `i` fixes the starting point, and the inner loop `j` iterates from `i` to the end. Maintain a running sum. If `sum == 0` at any point, update the maximum length `maxi = max(maxi, j - i + 1)`.

### 2. Optimal Approach (Prefix Sum + Hashing)
Use an unordered map to store the prefix sum and its first occurrence index. Iterate through the array keeping a running `sum`.
- If `sum == 0`, the subarray from index 0 to `i` has a sum of 0. Update `maxi = i + 1`.
- If `sum` is already present in the map, it means the elements between the previous occurrence of this sum and the current index `i` add up to 0. Update `maxi = max(maxi, i - map[sum])`.
- If `sum` is not in the map, insert it with its current index. (We only insert the first occurrence to maximize the length).

---

## Code
For code implementations, refer to `solution1.cpp` (Brute Force) and `solution2.cpp` (Optimal Hashing).

---

## Output
**Input:** `nums = [9, -3, 3, -1, 6, -5]`
**Output:** `5`

---

## Complexity
| | Time | Space |
|---|---|---|
| Brute Force | O(N^2) | O(1) |
| Optimal (Hashing) | O(N) | O(N) |

---

## Key Takeaway
The prefix sum property is incredibly powerful. If `PrefixSum[i] == PrefixSum[j]`, then the sum of elements from index `i+1` to `j` is 0. Hashing helps us find these equal prefix sums in O(1) time.
