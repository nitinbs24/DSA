# Problem: Rearrange Array Elements by Sign

## Problem Statement
You are given a **0-indexed** integer array `nums` of even length consisting of an equal number of positive and negative integers.

You should return the array of `nums` such that the array follows the given conditions:
1. Every consecutive pair of integers have opposite signs.
2. For all integers with the same sign, the order in which they were present in `nums` is preserved (relative order is maintained).
3. The rearranged array begins with a positive integer.

Return the modified array after rearranging the elements to satisfy the aforementioned conditions.

**Link:** [LeetCode 2149 - Rearrange Array Elements by Sign](https://leetcode.com/problems/rearrange-array-elements-by-sign/)  
**Difficulty:** Medium  
**Topic:** Arrays, Two Pointers, Simulation

---

## Approach

### Approach 1: Segregation via Auxiliary Vectors (Brute Force / Two Pass)
Since positive numbers must go to even indices (`0, 2, 4, ...`) and negative numbers to odd indices (`1, 3, 5, ...`), we can separate the numbers first:
1. Traverse the array and collect all positive elements into a vector `pos` and all negative elements into a vector `neg`.
2. Since the problem guarantees an equal number of positive and negative elements ($n/2$ each), iterate from `i = 0` to `n/2 - 1`:
   - Place `pos[i]` at index `2 * i`.
   - Place `neg[i]` at index `2 * i + 1`.
3. Overwrite or return the rearranged array.
- **Drawback:** Requires two passes (one to segregate into `pos` and `neg`, and one to combine them back) and uses $O(N)$ extra space for the two vectors.

### Approach 2: Direct Placement with Two Pointers (Optimal / One Pass)
Instead of segregating elements into intermediate vectors, we can place each element directly into its correct position in the answer array during a single traversal:
1. Initialize an answer array `ans` of size `n`.
2. Maintain two index pointers:
   - `posIndex = 0` (tracks the next available even index for positive numbers).
   - `negIndex = 1` (tracks the next available odd index for negative numbers).
3. Traverse the array `A` from left to right:
   - If `A[i] > 0`: place it at `ans[posIndex]` and advance `posIndex += 2`.
   - If `A[i] < 0`: place it at `ans[negIndex]` and advance `negIndex += 2`.
4. Because we traverse from index `0` to `n - 1`, the relative order of positive and negative elements is preserved naturally.
5. This accomplishes the rearrangement in a single pass of $O(N)$ time.

---

## Code

### Solution 1: Segregation via Auxiliary Vectors (Two Pass)
```cpp
#include <bits/stdc++.h>
using namespace std;

// Class to encapsulate array operations
class ArrayManipulator {
public:
    // Function to rearrange elements so that positives and negatives alternate
    vector<int> RearrangeBySign(vector<int>& A, int n) {
        vector<int> pos; // Vector to store positive numbers
        vector<int> neg; // Vector to store negative numbers

        // Step 1: Separate positives and negatives
        for (int i = 0; i < n; i++) {
            if (A[i] > 0)
                pos.push_back(A[i]); // Add positive to pos[]
            else
                neg.push_back(A[i]); // Add negative to neg[]
        }

        // Step 2: Place positives at even indices and negatives at odd indices
        for (int i = 0; i < n / 2; i++) {
            A[2 * i] = pos[i];      // Even index → positive
            A[2 * i + 1] = neg[i];  // Odd index → negative
        }

        return A; // Return the rearranged array
    }
};

// Driver code
int main() {
    int n = 4;
    vector<int> A{1, 2, -4, -5};

    // Create object of the class
    ArrayManipulator obj;

    // Call the function and get result
    vector<int> ans = obj.RearrangeBySign(A, n);

    // Print the rearranged array
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}
```

### Solution 2: Direct Placement with Two Pointers (Optimal / One Pass)
```cpp
#include <bits/stdc++.h>
using namespace std;

// Define a class to handle array manipulation
class ArrayManipulator {
public:
    // Function to rearrange elements by alternating sign
    vector<int> rearrangeBySign(vector<int>& A) {
        int n = A.size();

        // Create a result array of size n initialized with 0
        vector<int> ans(n, 0);

        // posIndex will store index for next positive number (even index)
        // negIndex will store index for next negative number (odd index)
        int posIndex = 0, negIndex = 1;

        // Loop through the original array
        for (int i = 0; i < n; i++) {
            if (A[i] < 0) {
                // Place negative numbers at odd indices
                ans[negIndex] = A[i];
                negIndex += 2;
            } else {
                // Place positive numbers at even indices
                ans[posIndex] = A[i];
                posIndex += 2;
            }
        }

        return ans;
    }
};

int main() {
    // Initialize the input array
    vector<int> A = {1, 2, -4, -5};

    // Create an object of the class
    ArrayManipulator obj;

    // Call the rearrange function
    vector<int> result = obj.rearrangeBySign(A);

    // Print the rearranged array
    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}
```

---

## Output

**Sample Input 1:**
```
nums = [3, 1, -2, -5, 2, -4]
```

**Sample Output 1:**
```
[3, -2, 1, -5, 2, -4]
```
*(Explanation: The positive integers in nums were [3, 1, 2], and the negative integers were [-2, -5, -4]. Alternating starting with positive yields [3, -2, 1, -5, 2, -4].)*

**Sample Input 2:**
```
nums = [1, 2, -4, -5]
```

**Sample Output 2:**
```
[1, -4, 2, -5]
```
*(Explanation: Positives are [1, 2] and negatives are [-4, -5]. Alternating signs preserve relative order.)*

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Approach 1 (Brute Force / Two Pass) | O(N) | O(N) |
| Approach 2 (Optimal / One Pass) | O(N) | O(N) |

*(Note: Approach 2 still requires $O(N)$ space to hold the returned answer vector `ans`, but it completes the reorganization in a single pass with only 2 pointers rather than multiple intermediate dynamic allocations for `pos` and `neg` vectors.)*

---

## Key Takeaway
When filling alternating slots in an array while preserving relative order, maintain two independent index pointers (`posIndex = 0` and `negIndex = 1`). Increment each pointer by `2` whenever an element is assigned, completing the rearrangement in a single $O(N)$ pass.
