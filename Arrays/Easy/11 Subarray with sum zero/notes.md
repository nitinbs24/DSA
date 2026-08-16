# Problem: Largest Subarray with 0 Sum

## Problem Statement
Given an array `a` of integers, find the length of the longest subarray with a sum equal to `0`. If no such subarray exists, return `0`.

**Link:** [GeeksforGeeks - Largest Subarray with 0 Sum](https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1)  
**Difficulty:** Medium  
**Topic:** Arrays, Hashing, Prefix Sum

---

## Approach

### Approach 1: Optimal (Prefix Sum + Hashing)
We can solve this problem efficiently in a single pass using the **Prefix Sum** technique paired with a Hash Map (`std::unordered_map`):
1. Maintain a running sum (`sum`) as we iterate through the array.
2. **Case 1 (`sum == 0`):** The subarray from index `0` to `i` has a sum of `0`. The length of this subarray is `i + 1`. We set `maxLen = i + 1`.
3. **Case 2 (`sum` already exists in map):** If the current prefix sum was previously seen at index `prevIndex`, the sum of elements between `prevIndex + 1` and `i` must be `0`. We update `maxLen = max(maxLen, i - prevIndex)`.
4. **Case 3 (`sum` is new):** We store the index `i` of this prefix sum in `sumIndexMap[sum] = i`. We only store the *first* occurrence of each prefix sum to ensure maximum subarray length.

---

## Code

### Approach 1 (Optimal - Prefix Sum + Hashing)
```cpp
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& a) {
    int maxLen = 0;
    unordered_map<int, int> sumIndexMap;
    int sum = 0;

    for (int i = 0; i < (int)a.size(); i++) {
        sum += a[i];

        if (sum == 0) {
            maxLen = i + 1;
        }
        else if (sumIndexMap.find(sum) != sumIndexMap.end()) {
            maxLen = max(maxLen, i - sumIndexMap[sum]);
        }
        else {
            sumIndexMap[sum] = i;
        }
    }

    return maxLen;
}

int main() {
    vector<int> a = {9, -3, 3, -1, 6, -5};
    cout << solve(a) << endl;
    return 0;
}
```

---

## Output
```
Input: a = [9, -3, 3, -1, 6, -5]
Output: 5
(Longest subarray with sum 0 is [-3, 3, -1, 6, -5] with length 5)
```

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Approach 1 (Optimal - Prefix Sum + Hashing) | O(N) | O(N) |

---

## Key Takeaway
If a running prefix sum repeats at two different indices `i` and `j` (`j > i`), the sum of elements in the subarray from `i + 1` to `j` must be `0`. Storing only the earliest index of each prefix sum ensures the calculated subarray length is maximized.
