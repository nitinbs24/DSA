# Problem: Print 1 to N (and N to 1)

## Problem Statement
Print numbers from 1 to `N` (and `N` to 1) using recursion.

**Difficulty:** Easy  
**Topic:** Basic Recursion

---

## Approach
**Solution 1 (Print 1 to N - Forward Recursion):**
Keep a `current` variable starting from 1. If `current > N`, return (Base case). Otherwise, print `current` and recursively call for `current + 1`.

**Solution 2 (Print N to 1 - Backtracking/Post-Recursive):**
Using the same parameters starting from 1, if we place the `cout` statement *after* the recursive call, the printing happens while the functions return from the stack. This effectively prints the numbers in reverse, from `N` down to 1.

---

## Code
### Print 1 to N
```cpp
#include<iostream>
using namespace std;

void printer(int current, int n){
    if(current>n) return;

    cout<<current<<endl;

    printer(current+1,n);
}

int main(){
    int n=10;
    printer(1,n);
    return 0;
}
```

### Print N to 1
```cpp
#include<iostream>
using namespace std;

void printer(int current, int n){
    if(current>n) return;

    printer(current+1,n);

    cout<<current<<endl;
}

int main(){
    int n=10;
    printer(1,n);
    return 0;
}
```

---

## Output
**Sample Output (1 to N):**
```
1
2
3
...
10
```

---

## Complexity
| | Time | Space |
|---|---|---|
| Optimal | O(N) | O(N) (Auxiliary Stack Space) |

---

## Key Takeaway
The placement of the work (e.g., `cout`) before or after the recursive call determines whether the operation happens during the recursive descent (forward) or during the backtracking phase (reverse).
