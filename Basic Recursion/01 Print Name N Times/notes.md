# Problem: Print Name N Times

## Problem Statement
Print a given string (name) `N` times using recursion.

**Difficulty:** Easy  
**Topic:** Basic Recursion

---

## Approach
**Recursive Approach:** Maintain a `count` variable. 
1. **Base Case:** If `count == N`, return.
2. **Recursive Step:** Print the name, and then make a recursive call incrementing the `count` by 1.

---

## Code
```cpp
#include<iostream>
using namespace std;

void printname(string name,int count,int n){
    if(count==n) return;

    cout<<name<<endl;

    printname(name, count+1 , n);
}
int main(){
    int n=5;
    printname("Nitin",0,n);
    return 0;
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
Nitin
Nitin
Nitin
Nitin
Nitin
```

---

## Complexity
| | Time | Space |
|---|---|---|
| Optimal | O(N) | O(N) (Auxiliary Stack Space) |

---

## Key Takeaway
Recursion uses a base condition to terminate. Without it, you would encounter a Stack Overflow.
