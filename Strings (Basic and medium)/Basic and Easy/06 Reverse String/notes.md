# Problem: Rotate String

## Problem Statement
Given two strings `s` and `goal`, return `true` if and only if `s` can become `goal` after some number of shifts on `s`.
A shift on `s` consists of moving the leftmost character of `s` to the rightmost position. *(Note: While the folder is named "Reverse String", the solutions are solving the "Rotate String" problem)*

**Link:** https://leetcode.com/problems/rotate-string/  
**Difficulty:** Easy  
**Topic:** String, String Matching

---

## Approach
**Approach 1 (Brute Force):**
Iterate through all possible rotation points `i` in string `s`. For each point, create a new rotated string by concatenating the substring from index `i` to the end with the substring from the beginning to index `i` (`s.substr(i) + s.substr(0, i)`). Check if this newly formed string equals `goal`.

**Approach 2 (Optimal):**
First, verify that `s` and `goal` have the exact same length. If they do, concatenate `s` with itself to create a new string (`s + s`). A key observation is that any valid rotation of `s` will always be a contiguous substring inside `s + s`. Thus, we only need to search for `goal` within this concatenated string using the `find()` function.

---

## Code
```cpp
#include<iostream>
using namespace std;

bool rotateString(string& s, string& goal){
    if(s.length()!=goal.length()) return false;
    string ds=s+s;
    return ds.find(goal) != string::npos;
}

int main(){
    string s="hello", goal="lohel";

    cout<<rotateString(s,goal)<<endl;
}
```

---

## Output
```
Input: s = "hello", goal = "lohel"
Output: 1 (True)
```

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Approach 1 (Brute Force) | `O(N^2)` | `O(N)` |
| Approach 2 (Optimal) | `O(N)` | `O(N)` |

*(Where N is the length of the string)*

---

## Key Takeaway
Concatenating a string with itself is a powerful and simple trick to expose all possible rotations of that string as contiguous substrings, saving us from having to manually generate and check each rotation.
