# Problem: Isomorphic Strings

## Problem Statement
Given two strings `s` and `t`, determine if they are isomorphic.
Two strings `s` and `t` are isomorphic if the characters in `s` can be replaced to get `t`.
All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

**Link:** https://leetcode.com/problems/isomorphic-strings/  
**Difficulty:** Easy  
**Topic:** String, Hash Table

---

## Approach
**Optimal Approach (Position Mapping):**
We can use two arrays of size 256 (to cover all ASCII characters) to keep track of the most recent position where each character in `s` and `t` was seen. As we iterate through the strings character by character, we check if the last seen position of the character from `s` matches the last seen position of the corresponding character from `t`. If they don't match, it means they have been mapped differently before, so the strings are not isomorphic. If they do match, we update their recorded positions to the current index `+ 1` (to differentiate from the initial `0` value).

---

## Code
```cpp
#include<iostream>
using namespace std;

bool isIsomorphic(string s,string t){
    int a[256]={0},b[256]={0};
    int n=s.size();

    for(int i=0;i<n;i++){
        if(a[s[i]]!=b[t[i]]) return false;
        a[s[i]]=i+1;
        b[t[i]]=i+1;
    }
    return true;
}

int main(){
    string s="paper",t="title";
    cout<<isIsomorphic(s,t)<<endl;
}
```

---

## Output
```
Input: s = "paper", t = "title"
Output: 1 (True)
```

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Optimal (Position Mapping) | `O(N)` | `O(1)` |

*(Where N is the length of the string)*

---

## Key Takeaway
Instead of mapping characters to each other, mapping characters to their last seen positions ensures a correct 1-to-1 mapping dynamically while traversing.
