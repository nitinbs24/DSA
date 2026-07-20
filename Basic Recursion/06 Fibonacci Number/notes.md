# Problem: Fibonacci Number

## Problem Statement
Find the `N`-th Fibonacci number using recursion. The Fibonacci sequence is a sequence where each number is the sum of the two preceding ones, starting from 0 and 1.

**Difficulty:** Easy  
**Topic:** Basic Recursion

---

## Approach
**Recursive Approach:**
The definition of the Fibonacci series directly translates into a recursive function: `F(n) = F(n-1) + F(n-2)`.
- **Base Case:** If `n <= 1`, return `n` (since `F(0) = 0`, `F(1) = 1`).
- **Recursive Step:** Return `fibonacci(n-1) + fibonacci(n-2)`.

*(Note: This is multiple recursion, which is highly inefficient without memoization because it computes the same subproblems repeatedly).*

---

## Code
```cpp
#include<iostream>
using namespace std;

int fibonacci(int n){
    if (n<=1) return n;

    return fibonacci(n-1)+fibonacci(n-2);
}

int main(){
    int n=6;

    cout<<fibonacci(n)<<endl;
}
```

---

## Output
**Sample Input:**
```
n = 6
```
**Sample Output:**
```
8
```

---

## Complexity
| | Time | Space |
|---|---|---|
| Recursive | O(2^N) | O(N) (Max depth of recursion stack) |

---

## Key Takeaway
Multiple recursion branches out exponentially `O(2^N)`. While the code is incredibly simple, it requires Dynamic Programming (memoization) to optimize the time complexity down to `O(N)`.
