# Problem: Majority Element II

## Problem Statement
Given an integer array of size `n`, find all elements that appear more than `⌊ n/3 ⌋` times.

**Link:** https://leetcode.com/problems/majority-element-ii/  
**Difficulty:** Medium  
**Topic:** Arrays

---

## Approach
### 1. Better Approach (Using Hashing)
Use an unordered map to store the frequency of each element. Iterate through the array, increment the frequency of each element, and if any element's frequency reaches `⌊ n/3 ⌋ + 1`, add it to the result array. Stop early if we find two such elements, as there can be at most two majority elements (since 3 * (n/3 + 1) > n).

### 2. Optimal Approach (Boyer-Moore Majority Vote Algorithm)
Since there can be at most two elements that appear more than `⌊ n/3 ⌋` times, we can keep track of two potential candidates (`el1`, `el2`) and their counts (`cnt1`, `cnt2`). 
- If the current element matches `el1` or `el2`, increment their respective count.
- If a count is 0, assign the current element to that candidate and set its count to 1.
- If it matches neither, decrement both counts.
After a single pass, `el1` and `el2` are our potential candidates. We do a second pass to manually count their exact occurrences and verify if they actually appear more than `⌊ n/3 ⌋` times.

---

## Code
For code implementations, refer to `solution1.cpp` (Hashing) and `solution2.cpp` (Boyer-Moore).

---

## Output
**Input:** `arr = [11, 33, 33, 11, 33, 11]`
**Output:** `The majority elements are: 11 33`

---

## Complexity
| | Time | Space |
|---|---|---|
| Better (Hashing) | O(N) | O(N) |
| Optimal (Boyer-Moore) | O(N) | O(1) |

---

## Key Takeaway
Boyer-Moore Majority Vote Algorithm can be extended to find elements appearing more than `n/k` times by keeping track of `k-1` candidates.
