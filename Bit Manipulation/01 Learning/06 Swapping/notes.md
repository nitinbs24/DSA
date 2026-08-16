# Problem: Swap Two Numbers Without a Temporary Variable

## Problem Statement
Given two integers `a` and `b`, swap their values without using a third / temporary variable.

**Link:** [GeeksforGeeks - Swap Two Numbers](https://www.geeksforgeeks.org/problems/swap-two-numbers3844/1)  
**Difficulty:** Easy  
**Topic:** Bit Manipulation

---

## Approach

### Approach 1: Optimal (Bitwise XOR Swap)
We can swap two variables using the key properties of the Bitwise XOR (`^`) operator:
1. `X ^ X = 0` (Self-inverse property)
2. `X ^ 0 = X` (Identity property)
3. XOR is commutative and associative (`A ^ B == B ^ A`).

**Step-by-Step Derivation:**
1. `a = a ^ b`: `a` now stores the combined XOR mask of both initial values.
2. `b = a ^ b`: Substituting `a`, we get `(a ^ b) ^ b = a ^ (b ^ b) = a ^ 0 = a`. Now `b` holds the original value of `a`.
3. `a = a ^ b`: Substituting the updated `b`, we get `(a ^ b) ^ a = (a ^ a) ^ b = 0 ^ b = b`. Now `a` holds the original value of `b`.

---

## Code

### Approach 1 (Optimal - XOR Swap)
```cpp
#include<iostream>
using namespace std;

void swapper(int a,int b){
    cout<<a<<" "<<b<<endl;

    a=a^b;
    b=a^b;
    a=a^b;

    cout<<a<<" "<<b<<endl;
}

int main(){
    swapper(5,3);
}
```

---

## Output
```
5 3
3 5
```

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Approach 1 (Optimal - XOR Swap) | O(1) | O(1) |

---

## Key Takeaway
Bitwise XOR allows swapping two variables in-place without any extra space and avoids integer overflow issues that can occur with arithmetic addition/subtraction (`a = a + b; b = a - b; a = a - b;`).
