# Problem: Single Number (Find Element Appearing Once)

## Problem Statement
Given a non-empty array of integers `arr`, every element appears twice except for one element which appears exactly once. Find that single element.

**Link:** [LeetCode - Single Number](https://leetcode.com/problems/single-number/)  
**Difficulty:** Easy  
**Topic:** Bit Manipulation, Arrays, Hashing

---

## Approach

### Approach 1: Hashing (Frequency Map)
Use a Hash Map (`std::unordered_map<int, int>`) to count the frequency of each number:
1. Traverse the array and store element counts in the hash map.
2. Traverse the array again and return the element whose frequency is `1`.

### Approach 2: Optimal (Bitwise XOR)
We can eliminate extra space using the properties of the Bitwise XOR (`^`) operator:
1. **`X ^ X = 0`:** Any number XORed with itself cancels out to `0`.
2. **`X ^ 0 = X`:** Any number XORed with `0` remains unchanged.
3. **Commutative & Associative:** The order of XOR operations does not matter.

By initializing `xorr = 0` and XORing all elements in the array, all duplicate pairs will cancel out to `0`, leaving only the unique element that appears once.

---

## Code

### Approach 1 (Hashing)
```cpp
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int getSingleElement(vector<int>& arr) {
        unordered_map<int, int> hash;

        for (int i = 0; i < arr.size(); i++) {
            hash[arr[i]]++;
        }

        for (int i = 0; i < arr.size(); i++) {
            if (hash[arr[i]] == 1)
                return arr[i];
        }

        return -1; 
    }
};

int main() {
    vector<int> arr = {4, 1, 2, 1, 2};
    Solution obj;
    int ans = obj.getSingleElement(arr);
    cout << "The single element is: " << ans << endl;
    return 0;
}
```

### Approach 2 (Optimal - Bitwise XOR)
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getSingleElement(vector<int>& arr) {
        int n = arr.size();
        int xorr = 0;

        for (int i = 0; i < n; i++) {
            xorr = xorr ^ arr[i];
        }

        return xorr;
    }
};

int main() {
    vector<int> arr = {4, 1, 2, 1, 2};

    Solution obj;
    int ans = obj.getSingleElement(arr);

    cout << "The single element is: " << ans << endl;

    return 0;
}
```

---

## Output
```
The single element is: 4
```

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Approach 1 (Hashing) | O(N) | O(N) |
| Approach 2 (Optimal - Bitwise XOR) | O(N) | O(1) |

---

## Key Takeaway
XORing identical numbers cancels them out (`X ^ X = 0`). Whenever every element appears an even number of times except one, XORing all elements together isolates the single unique element in O(N) time and O(1) space.
