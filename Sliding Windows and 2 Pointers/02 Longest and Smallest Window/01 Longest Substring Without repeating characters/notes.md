# Problem: Longest Substring Without Repeating Characters

## Problem Statement
Given a string `s`, find the length of the **longest substring** without duplicate characters.

A substring is a contiguous non-empty sequence of characters within a string.

**Link:** [LeetCode 3 - Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/)  
**Difficulty:** Medium  
**Topic:** Strings, Hash Table, Sliding Window, Two Pointers

---

## Approach

### Approach 1: Sliding Window with Hash Set (Standard Two Pointers)
We maintain a dynamic sliding window `[left, right]` where all characters within the window are distinct:
1. Maintain an `unordered_set<char> window` storing the unique characters currently inside the active window.
2. Expand the window by advancing `right` from `0` to `s.length() - 1`.
3. If the incoming character `s[right]` already exists in `window`:
   - Repeatedly erase `s[left]` from `window` and increment `left++` until `s[right]` is removed.
4. Insert `s[right]` into `window`.
5. Update `maxLen = max(maxLen, right - left + 1)`.
- **Complexity:** In the worst case (e.g., `"bbbbb"`), each character is inserted once and erased once, leading to $O(2N) = O(N)$ time. Space is $O(\min(N, \Sigma))$ where $\Sigma$ is the alphabet size.

### Approach 2: Optimal Sliding Window with Direct Index Jump (Hash Table)
In Approach 1, when a duplicate is found, `left` shifts incrementally one step at a time. We can optimize this by jumping `left` directly past the previous occurrence of the duplicate character:
1. Maintain an array/vector `hash` of size 128 (covering all ASCII characters) initialized to `-1`, storing the **most recent index** where each character appeared.
2. Iterate `right` from `0` to `s.length() - 1`:
   - If `hash[s[right]] >= left`: this character has already appeared inside our current active window `[left, right]`. Jump `left` forward directly to `hash[s[right]] + 1`.
   - Update the last seen position of the character: `hash[s[right]] = right`.
   - Update the maximum window length: `maxLen = max(maxLen, right - left + 1)`.
- **Advantage:** Eliminates the inner `while` loop completely; each character is visited exactly once, making it a strictly single-pass $O(N)$ algorithm with $O(1)$ auxiliary memory (fixed size-128 array).

---

## Code

### Solution 1: Sliding Window with Hash Set
```cpp
#include <algorithm>
#include<iostream>
#include <unordered_set>
using namespace std;

class Solution{
    public:
    int longestSubstring(string s){
        int left=0,right=0,maxLen=0;
        unordered_set<char> window;

        while(right<s.length()){
            while(window.count(s[right])){
                window.erase(s[left]);
                left++;
            }

            window.insert(s[right]);
            maxLen=max(maxLen,right-left+1);
            right++;
        }
        return maxLen;
    }
};

int main(){
    string name="nitin";
    Solution sol;
    cout<< sol.longestSubstring(name)<<endl;
    
}
```

### Solution 2: Optimal Sliding Window with Direct Index Jump
```cpp
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash (128,-1);
        int left=0,maxLen=0;

        for(int right=0;right<s.length();right++){

            if(hash[s[right]]>=left) left=hash[s[right]]+1;

            hash[s[right]]=right;
            maxLen=max(maxLen,right-left+1);
        }
        return maxLen;
    }
};

int main(){
    Solution sol;
    string name="nitin";

    cout<<sol.lengthOfLongestSubstring(name)<<endl;

}
```

---

## Output

**Sample Input 1:**
```
s = "abcabcbb"
```

**Sample Output 1:**
```
3
```
*(Explanation: The answer is "abc", with the length of 3.)*

**Sample Input 2:**
```
s = "bbbbb"
```

**Sample Output 2:**
```
1
```
*(Explanation: The answer is "b", with the length of 1.)*

**Sample Input 3:**
```
s = "pwwkew"
```

**Sample Output 3:**
```
3
```
*(Explanation: The answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.)*

**Sample Input 4:**
```
s = "nitin"
```

**Sample Output 4:**
```
3
```
*(Explanation: Longest substring without duplicates is "nit" or "tin", length = 3.)*

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Approach 1 (Sliding Window with Set) | O(2N) | O(min(N, Σ)) |
| Approach 2 (Optimal - Index Jump) | O(N) | O(Σ) ≈ O(1) |

*(Where N is the length of the string and Σ is the size of the character set, at most 128 for standard ASCII.)*

---

## Key Takeaway
Instead of shrinking the window element-by-element with an inner `while` loop, store the last seen index of each character in a direct hash map. When a duplicate inside the window is detected (`hash[c] >= left`), jump `left` directly to `hash[c] + 1`, eliminating redundant shrink steps and guaranteeing a strictly single-pass $O(N)$ execution.
