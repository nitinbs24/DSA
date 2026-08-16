# Problem: Set the Rightmost Bit to 1

## Problem Statement
Given an integer `n`, set its rightmost bit (0-th bit / LSB) to `1`. If the bit is already `1`, the number remains unchanged.

**Link:** [GeeksforGeeks - Set the Rightmost Unset Bit](https://www.geeksforgeeks.org/problems/set-the-rightmost-unset-bit4436/1)  
**Difficulty:** Easy  
**Topic:** Bit Manipulation

---

## Approach

### Approach 1: Optimal (Bitwise OR with 1)
To set the 0-th bit (LSB) of a number to `1`:
- Perform a Bitwise OR operation with `1` (`n | 1`).
- Since `1` in binary has only its 0-th bit set (`000...0001`), `n | 1` forces the LSB to become `1` while leaving all other bits intact.
  - If `n` is even (LSB is `0`), `n | 1` increases the number by 1 (`n + 1`).
  - If `n` is odd (LSB is `1`), `n | 1` leaves `n` unchanged.

*(Note: If the goal is to set the first **unset bit** (rightmost `0`) from right to left for any number, the general formula is `n | (n + 1)`).*

---

## Code

### Approach 1 (Optimal - Bitwise OR)
```cpp
#include<iostream>
using namespace std;

int setter(int n){
    return n|1;
}

int main(){
    cout<<setter(10)<<endl;
}
```

---

## Output
```
Input: n = 10
Output: 11
```

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Approach 1 (Optimal - Bitwise OR) | O(1) | O(1) |

---

## Key Takeaway
The Bitwise OR operator (`|`) is used to set bits to `1`. Performing `n | (1 << i)` sets the `i`-th bit to `1`; specifically for `i = 0`, `n | 1` sets the LSB to `1`.
