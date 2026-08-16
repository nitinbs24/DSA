# Problem: Check if a Number is Odd or Even

## Problem Statement
Given an integer `num`, determine whether the number is odd or even using bitwise operations.

**Link:** [GeeksforGeeks - Odd or Even](https://www.geeksforgeeks.org/problems/odd-or-even3618/1)  
**Difficulty:** Easy  
**Topic:** Bit Manipulation

---

## Approach

### Approach 1: Optimal (Bitwise AND with 1)
In binary representation:
- Even numbers always have `0` as their Least Significant Bit (LSB) (0-th bit).
- Odd numbers always have `1` as their Least Significant Bit (LSB) (0-th bit).

By taking the bitwise AND of `num` with `1` (`num & 1`):
- If `(num & 1) == 0`, the LSB is `0`, meaning the number is **Even**.
- If `(num & 1) == 1`, the LSB is `1`, meaning the number is **Odd**.

---

## Code

### Approach 1 (Optimal - Bitwise AND)
```cpp
#include<iostream>
using namespace std;

bool checker(int num){
    return (num&1)==0;
}

int main(){
    int num=9;
    if(checker(num)) cout<<"even\n";
    else cout<<"odd\n";
}
```

---

## Output
```
Input: num = 9
Output: odd
```

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Approach 1 (Optimal - Bitwise AND) | O(1) | O(1) |

---

## Key Takeaway
Checking `(num & 1)` checks the LSB directly in O(1) CPU instruction time, making it faster than using the modulo operator `% 2`.
