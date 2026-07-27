# Problem: Remove Outermost Parentheses

## Problem Statement
A valid parentheses string `s` is primitive if it is nonempty, and there does not exist a way to split it into `s = A + B`, with `A` and `B` nonempty valid parentheses strings.
Given a valid parentheses string `s`, consider its primitive decomposition: `s = P_1 + P_2 + ... + P_k`, where `P_i` are primitive valid parentheses strings.
Return `s` after removing the outermost parentheses of every primitive string in the primitive decomposition of `s`.

**Link:** [LeetCode 1021](https://leetcode.com/problems/remove-outermost-parentheses/)  
**Difficulty:** Easy  
**Topic:** Strings, Stack

---

## Approach
### Optimal Approach (Counter)
Instead of using a stack, we can keep track of the nesting depth (level) of the parentheses.
1. Initialize a `level` variable to `0` to keep track of the nesting depth.
2. Iterate through each character in the string:
   - If the character is an opening parenthesis `(`, it is only added to the result if it's not the outermost one (i.e., `level > 0`). Then we increment the `level`.
   - If the character is a closing parenthesis `)`, it is only added to the result if it's not the outermost one. To determine this, we first decrement the `level`, and if `level > 0`, it means it was an inner parenthesis, so we add it to the result.
3. This effectively strips away the outer parentheses of all primitive valid parts, leaving only the inner parts.

---

## Code
```cpp
#include<iostream>
using namespace std;

string remover(string& str){
    string result="";
    int level=0;
    
    for(char ch:str){
        if(ch=='('){
            if(level>0) result+=ch;
            level++;
        }
        else if (ch==')'){
            level--;
            if(level>0) result+=ch;
        }
    }
    return result;
}

int main(){
    string str="((()))";
    cout<<remover(str)<<endl;
    return 0;
}
```

---

## Output
```text
Input: "((()))"
Output: "(())"

Input: "()(()())(())"
Output: "()()()"
```

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Optimal (Level Counter) | O(N) | O(N) |

*(Note: Space complexity is O(N) to store the result string. Auxiliary space is O(1))*

---

## Key Takeaway
Using a counter variable for the nesting level of parentheses is often a more space-efficient alternative to using a Stack.
