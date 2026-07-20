# Problem: Factorial of a Number

## Problem Statement
Calculate the factorial of a given number `N`. Factorial of `N` (denoted by `N!`) is the product of all positive integers less than or equal to `N`.

**Difficulty:** Easy  
**Topic:** Basic Recursion

---

## Approach
**Iterative Approach:** Use a simple `for` loop starting from 1 up to `N`, continually multiplying the result.

**Recursive Approach:**
- **Base Case:** If `n == 0`, return 1 (since 0! = 1).
- **Recursive Step:** Return `n * factorial(n-1)`.

---

## Code
### Recursive Solution
```cpp
#include<iostream>
using namespace std;

int factorial(int n){
    if (n==0) return 1;

    return n*factorial(n-1);
}

int main(){
    int n=5;

    cout<<factorial(n)<<endl;
}
```

---

## Output
**Sample Input:**
```
n = 5
```
**Sample Output:**
```
120
```

---

## Complexity
| | Time | Space |
|---|---|---|
| Iterative | O(N) | O(1) |
| Recursive | O(N) | O(N) (Auxiliary Stack Space) |

---

## Key Takeaway
A classic example of recursion representing a mathematical recurrence relation: `f(n) = n * f(n-1)`.
