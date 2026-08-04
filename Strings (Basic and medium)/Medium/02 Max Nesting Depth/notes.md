# Problem: Maximum Nesting Depth of the Parentheses

## Problem Statement
Given a valid parentheses string, return the nesting depth of the string. The nesting depth is the maximum number of simultaneously open parentheses.

**Link:** [LeetCode - Maximum Nesting Depth of the Parentheses](https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/)  
**Difficulty:** Easy / Medium  
**Topic:** Strings, Stack

---

## Approach
**Optimal Approach (Counting):**
We can solve this problem in a single pass without using an explicit stack. 
1. Maintain two variables: `p` to track the current depth of open parentheses, and `ans` to store the maximum depth encountered so far.
2. Iterate through each character of the string.
3. If the current character is an opening parenthesis `(`, increment the current depth `p`.
4. If the current character is a closing parenthesis `)`, decrement the current depth `p`.
5. In every step, update the maximum depth `ans` as `max(ans, p)`.
6. Return `ans` as the final result.

This optimal approach allows us to find the maximum nesting depth using constant extra space.

---

## Code
```cpp
#include<iostream>
using namespace std;

int maxDepth(string str){
    int p=0,ans=0;

    for(auto x: str){
        if(x=='(') p++;
        else if(x==')')p--;

        ans=max(ans,p);
    }
    return ans;
}

int main(){
    string str="(1)+((2))+(((3)))";

    cout<<maxDepth(str)<<endl;
}
```

---

## Output
**Input:** `str = "(1)+((2))+(((3)))"`
**Output:**
```
3
```

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Optimal (Counting) | O(N) | O(1) |

*(N is the length of the string)*

---

## Key Takeaway
Nesting depth problems with only one type of parenthesis can be solved efficiently without an explicit stack by simply tracking the count of currently open parentheses.
