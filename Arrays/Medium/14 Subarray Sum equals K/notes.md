# Problem: Subarray Sum Equals K

## Problem Statement
Given an array of integers `arr` and an integer `k`, return the total number of **subarrays** whose sum equals to `k`.

A subarray is a contiguous non-empty sequence of elements within an array.

**Link:** [LeetCode 560 - Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/)  
**Difficulty:** Medium  
**Topic:** Arrays, Hash Table, Prefix Sum

---

## Approach

### Approach 1: Brute Force (3 Nested Loops)
The most direct way is to consider every possible subarray and calculate its sum:
1. Use an outer loop with starting index `i` from `0` to `n - 1`.
2. Use a middle loop with ending index `j` from `i` to `n - 1`.
3. Use an innermost loop with index `m` from `i` to `j` to calculate the sum of elements `arr[i...j]`.
4. If the calculated sum equals `k`, increment `count`.
- **Drawback:** Takes $O(N^3)$ time, resulting in Time Limit Exceeded (TLE) on large arrays.

### Approach 2: Better (2 Nested Loops with Running Sum)
Instead of recalculating the sum from scratch for each subarray, compute the sum incrementally:
1. For each starting index `i` from `0` to `n - 1`, initialize `sum = 0`.
2. Expand the ending index `j` from `i` to `n - 1`, adding the current element `arr[j]` to `sum`: `sum += arr[j]`.
3. If `sum == k`, increment `count`.
- **Drawback:** Reduces time to $O(N^2)$, which is still too slow when $N \ge 2 \times 10^4$.

### Approach 3: Optimal (Prefix Sum + Hash Map)
We can solve the problem in a single pass ($O(N)$) using the concept of **Prefix Sums**:
- Let $S_i$ be the prefix sum of elements up to index `i` ($\sum_{x=0}^{i} arr[x]$).
- The sum of any subarray starting at index $j + 1$ and ending at index `i` is:
  $$\text{Subarray Sum} = S_i - S_j$$
- We want subarrays where $\text{Subarray Sum} = k$:
  $$S_i - S_j = k \iff S_j = S_i - k$$
- Therefore, at index `i`, the number of valid subarrays ending at `i` with sum $k$ is equal to the number of previous prefix sums equal to `S_i - k`.

**Algorithm:**
1. Maintain an `unordered_map<int, int> prefixSumCount` storing `(prefixSum -> frequency)`.
2. Initialize `prefixSumCount[0] = 1`. This handles the base case where a subarray starting from index `0` itself has a sum equal to `k` (since `prefixSum - k = 0`).
3. Maintain running `prefixSum = 0` and total `count = 0`.
4. Traverse through the array:
   - Add `arr[i]` to `prefixSum`.
   - Check if `remove = prefixSum - k` exists in the map:
     - If yes, add `prefixSumCount[remove]` to `count`.
   - Increment `prefixSumCount[prefixSum]++`.
5. Return `count`.

---

## Code

### Solution 1: Brute Force (3 Nested Loops)
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int subarraySum(vector<int>& arr, int k) {

        int n = arr.size();
        int count = 0;

        for (int i = 0; i < n; i++) {

            for (int j = i; j < n; j++) {
                int sum = 0;
                for (int m = i; m <= j; m++) {
                    sum += arr[m];
                }
                if (sum == k) {
                    count++;
                }
            }
        }
        return count;
    }
};

int main() {

    vector<int> arr = {3, 1, 2, 4};
    int k = 6;
    Solution sol;

    int result = sol.subarraySum(arr, k);

    cout << "The number of subarrays is: " << result << "\n";
    return 0;
}
```

### Solution 2: Better (2 Nested Loops)
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int subarraySum(vector<int>& arr, int k) {

        int n = arr.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
 
            int sum = 0;

            for (int j = i; j < n; j++) {
                sum += arr[j];
                if (sum == k) {
                    count++;
                }
            }
        }

        return count;
    }
};

int main() {

    vector<int> arr = {3, 1, 2, 4};
    int k = 6;
    Solution sol;

    int result = sol.subarraySum(arr, k);

    cout << "The number of subarrays is: " << result << "\n";

    return 0;
}
```

### Solution 3: Optimal (Prefix Sum + Hash Map)
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int subarraySum(vector<int>& arr, int k) {

        int n = arr.size();
        unordered_map<int, int> prefixSumCount;
        int prefixSum = 0;
        int count = 0;
        prefixSumCount[0] = 1;

        for (int i = 0; i < n; i++) {

            prefixSum += arr[i];
            int remove = prefixSum - k;
            if (prefixSumCount.find(remove) != prefixSumCount.end()) {
                count += prefixSumCount[remove];
            }
            prefixSumCount[prefixSum]++;
        }

        return count;
    }
};

int main() {
    // Input array
    vector<int> arr = {3, 1, 2, 4};
    int k = 6;
    Solution sol;
    int result = sol.subarraySum(arr, k);

    cout << "The number of subarrays is: " << result << "\n";

    return 0;
}
```

---

## Output

**Sample Input 1:**
```
arr = [3, 1, 2, 4], k = 6
```

**Sample Output 1:**
```
The number of subarrays is: 2
```
*(Explanation: The subarrays with sum 6 are [3, 1, 2] and [2, 4].)*

**Sample Input 2:**
```
arr = [1, 1, 1], k = 2
```

**Sample Output 2:**
```
The number of subarrays is: 2
```
*(Explanation: The subarrays with sum 2 are arr[0...1] = [1, 1] and arr[1...2] = [1, 1].)*

**Sample Input 3:**
```
arr = [1, -1, 0], k = 0
```

**Sample Output 3:**
```
The number of subarrays is: 3
```
*(Explanation: Subarrays with sum 0 are [1, -1], [0], and [1, -1, 0].)*

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Approach 1 (Brute Force) | O(N³) | O(1) |
| Approach 2 (Better) | O(N²) | O(1) |
| Approach 3 (Optimal - Prefix Sum + Map) | O(N) | O(N) |

*(Note: Approach 3 has O(N) average time complexity with unordered_map. In the rare case of high hash collisions, unordered_map can degrade to O(N²), which can be prevented using custom hashing or std::map with O(N log N) guarantee.)*

---

## Key Takeaway
Whenever asked to count subarrays with a target sum (especially when numbers can be negative), two pointers / sliding window will **not** work. Instead, use a **Prefix Sum Hash Map**: if the current prefix sum is `prefixSum`, any previous prefix sum equal to `prefixSum - k` marks the start of a valid subarray summing to `k`. Always initialize `map[0] = 1` to capture subarrays starting from index 0.
