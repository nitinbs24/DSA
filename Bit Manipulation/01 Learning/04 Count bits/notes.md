# Problem: Count Set Bits (Hamming Weight)

## Problem Statement
Given a positive integer `n`, count and return the number of set bits (i.e., bits with a value of `1`) in its binary representation.

**Link:** [LeetCode - Number of 1 Bits](https://leetcode.com/problems/number-of-1-bits/)  
**Difficulty:** Easy  
**Topic:** Bit Manipulation

---

## Approach

### Approach 1: Brute Force (Bit Shift & Mask)
Check the least significant bit (LSB) using `n & 1`, add its value to `count`, and right-shift `n` by 1 (`n >>= 1`). Repeat until `n` becomes `0`.
- This approach inspects **every bit** from LSB up to the highest set bit.
- Loop runs O(log₂ N) times.

### Approach 2: Optimal (Brian Kernighan's Algorithm)
Brian Kernighan's algorithm clears the rightmost set bit in each iteration using `n &= (n - 1)`:
- In binary, `n - 1` flips the rightmost set bit and all 0s following it.
- Taking `n & (n - 1)` resets the rightmost set bit to `0` while keeping all higher bits unchanged.
- Increment `count` in each iteration until `n == 0`. The loop executes **only as many times as there are set bits** in `n`.

---

## Code

### Approach 1 (Brute Force - Bit Shift)
```cpp
#include<iostream>
using namespace std;

int counter(int n){
    int count=0;
    while(n>0){
        count+=(n&1);
        n>>=1;
    }
    return count;
}

int main(){
    cout<<counter(5)<<endl;
}
```

### Approach 2 (Optimal - Brian Kernighan's Algorithm)
```cpp
#include<iostream>
using namespace std;

int counter(int n){
    int count=0;
    while(n){
        n&=(n-1);
        count++;
    }
    return count;
}

int main(){
    cout<<counter(15)<<endl;
}
```

---

## Output
```
Input: n = 15
Output: 4
```

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Approach 1 (Bit Shift & Mask) | O(log₂ N) | O(1) |
| Approach 2 (Brian Kernighan's Algorithm) | O(K) *(where K is the number of set bits)* | O(1) |

---

## Key Takeaway
Brian Kernighan's Algorithm (`n &= (n - 1)`) optimizes counting set bits by skipping 0-bits completely, executing in O(number of set bits) iterations.
