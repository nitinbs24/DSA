# Problem: Check Palindrome String

## Problem Statement
Determine if a given string reads the same forwards and backwards using recursion.

**Difficulty:** Easy  
**Topic:** Basic Recursion

---

## Approach
**Recursive Approach:**
Instead of using two pointers explicitly, use a single index `i` that iterates from `0` to `length / 2`.
1. **Base Case:** If `i >= name.length() / 2`, all characters have matched successfully, return `true`.
2. **Failure Case:** Compare `name[i]` with its counterpart `name[name.length() - 1 - i]`. If they don't match, return `false`.
3. **Recursive Step:** If they match, recurse for `i + 1`.

---

## Code
```cpp
#include<iostream>
using namespace std;

bool palindromeCheck(int i,string name){

    if(i>=name.length()/2) return true;

    if(name[i] != name[name.length()-1-i]) return false;

    return palindromeCheck(i+1, name);

}
int main(){
    string name="nitin";

    cout<<"Is "<<name<<" a palidrome?: "<<palindromeCheck(0,name)<<endl;
}
```

---

## Output
**Sample Input:**
```
name = "nitin"
```
**Sample Output:**
```
Is nitin a palidrome?: 1
```

---

## Complexity
| | Time | Space |
|---|---|---|
| Recursive | O(N/2) => O(N) | O(N/2) => O(N) (Auxiliary Stack) |

---

## Key Takeaway
We only need one pointer `i` for checking palindromes or reversing data recursively, as the opposite pointer can always be calculated using `size - 1 - i`.
