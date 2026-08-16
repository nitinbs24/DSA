# Problem: Power of Two

## Problem Statement
Given an integer `n`, return `true` if it is a power of two. Otherwise, return `false`. An integer `n` is a power of two if there exists an integer `x` such that `n == 2^x`.

**Link:** [LeetCode - Power of Two](https://leetcode.com/problems/power-of-two/)  
**Difficulty:** Easy  
**Topic:** Bit Manipulation, Math

---

## Approach

### Approach 1: Optimal (Bitwise Trick: `n & (n - 1)`)
A positive integer `n` is a power of 2 if and only if its binary representation contains **exactly one** set bit (`1`).
- Example: `16` in binary is `10000`.
- Subtracting 1 flips the rightmost set bit and all 0s after it: `16 - 1 = 15`, which is `01111` in binary.
- Taking bitwise AND of `n` and `n - 1`: `(10000 & 01111) == 00000` (which is `0`).

Thus, for `n > 0`, if `(n & (n - 1)) == 0`, `n` is a power of 2.

---

## Code

### Approach 1 (Optimal - Bitwise Trick)
```cpp
#include<iostream>
using namespace std;

bool checker(int n){
    return (n>0 && (n&(n-1))==0);
}

int main(){
    if(checker(16)) cout<<"True\n";
    else cout<<"False\n";
}
```

---

## Output
```
Input: n = 16
Output: True
```

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Approach 1 (Optimal - Bitwise Trick) | O(1) | O(1) |

---

## Key Takeaway
The bitwise operation `n & (n - 1)` turns off / clears the rightmost set bit of `n`. For powers of 2 (which have only one set bit), clearing that single set bit leaves `0`.
