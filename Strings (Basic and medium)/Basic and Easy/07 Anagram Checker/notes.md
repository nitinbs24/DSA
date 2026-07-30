# Problem: Valid Anagram

## Problem Statement
Given two strings `s1` and `s2`, return `true` if `s2` is an anagram of `s1`, and `false` otherwise.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

**Link:** https://leetcode.com/problems/valid-anagram/  
**Difficulty:** Easy  
**Topic:** Hash Table, String

---

## Approach
**Optimal Approach (Frequency Array):**
First, check if the lengths of both strings are equal; if not, they cannot be anagrams. Then, we use a frequency array of size 26 to keep track of the occurrences of each character. 
We iterate through the first string and increment the frequency for each character. 
We then iterate through the second string and decrement the frequency for each character.
Finally, we check the frequency array. If all elements are 0, it means both strings had the exact same characters in the exact same quantities, meaning they are anagrams.

*(Note: The provided code assumes the strings consist of uppercase English letters by using `-'A'`. If the problem specifies lowercase, use `-'a'` instead).*

---

## Code
```cpp
#include<iostream>
using namespace std;

bool isAnagram(string s1,string s2){
    if(s1.length()!=s2.length()) return false;
    int freq[26]={0};
    for(int i=0;i<s1.length();i++) freq[s1[i]-'A']++;

    for(int i=0;i<s2.length();i++) freq[s2[i]-'A']--;

    for(int i=0;i<26;i++) if(freq[i]!=0) return false;

    return true;
}

int main(){
    string s1="ACT",s2="CAT";
    cout<<isAnagram(s1,s2)<<endl;

}
```

---

## Output
```
Input: s1 = "ACT", s2 = "CAT"
Output: 1 (True)
```

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Optimal (Frequency Array) | `O(N)` | `O(1)` |

*(Where N is the length of the strings)*

---

## Key Takeaway
Using a fixed-size integer array to count character frequencies is a highly efficient and standard pattern to solve character-matching string problems in `O(N)` time and `O(1)` space.
