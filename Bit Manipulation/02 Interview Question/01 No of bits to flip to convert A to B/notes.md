# Problem: Minimum Bit Flips to Convert Number (A to B)

## Problem Statement
A **bit flip** of a number `x` consists of choosing a bit in the binary representation of `x` and flipping it (changing `0` to `1` or `1` to `0`). Given two integers `start` and `goal`, return the minimum number of bit flips required to convert `start` to `goal`.

**Link:** [LeetCode - Minimum Bit Flips to Convert Number](https://leetcode.com/problems/minimum-bit-flips-to-convert-number/)  
**Difficulty:** Easy  
**Topic:** Bit Manipulation

---

## Approach

### Core Insight
A bit position requires a flip if and only if the bit in `start` is **different** from the bit in `goal`.
- The **Bitwise XOR (`^`)** operation yields `1` when bits are different and `0` when bits are identical.
- Therefore, `start ^ goal` produces a mask where every set bit (`1`) represents a position that must be flipped.
- The problem reduces to **counting the number of set bits** in `start ^ goal`.

### Approach 1: Bit Shift & Mask
1. Compute `num = start ^ goal`.
2. Loop 32 times (or while `num > 0`). In each iteration, add `num & 1` to `count` and right-shift `num` by 1 (`num >>= 1`).

### Approach 2: Optimal (Brian Kernighan's Algorithm)
1. Compute `num = start ^ goal`.
2. While `num > 0`, clear the rightmost set bit using `num = num & (num - 1)` and increment `count`.
3. This approach runs in O(K) iterations, where K is the number of bits that actually need to be flipped.

---

## Code

### Approach 1 (Bit Shift & Mask)
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minBitsFlip(int start, int goal) {
        int num = start ^ goal;
        int count = 0;

        for(int i = 0; i < 32; i++) {
            count += (num & 1); 
            num = num >> 1;
        }
        return count;
    }
};

int main() {
    int start = 10, goal = 7;
    
    Solution sol; 
    int ans = sol.minBitsFlip(start, goal);
    
    cout << "The minimum bit flips to convert number is: " << ans;
    
    return 0;
}
```

### Approach 2 (Optimal - Brian Kernighan's Algorithm)
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minBitsFlip(int start, int goal) {
        int num = start ^ goal;
        int count = 0;

        while (num > 0) {
            num = num & (num - 1);
            count++;
        }
        return count;
    }
};
```

---

## Output
```
The minimum bit flips to convert number is: 3
```
*(Explanation: 10 in binary is `1010`, 7 in binary is `0111`. `1010 ^ 0111 = 1101` which has 3 set bits, so 3 flips are required.)*

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Approach 1 (Bit Shift & Mask) | O(1) *(32 iterations)* | O(1) |
| Approach 2 (Brian Kernighan's Algorithm) | O(K) *(where K is the number of flipped bits)* | O(1) |

---

## Key Takeaway
Finding the number of differing bits between two numbers is equivalent to computing `start ^ goal` and counting the set bits in the resulting XOR mask.
