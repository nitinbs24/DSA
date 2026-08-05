# Problem: Longest Palindromic Substring

## Problem Statement
Given a string `s`, return the longest palindromic substring in `s`.

**Link:** [LeetCode - Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/)  
**Difficulty:** Medium  
**Topic:** String, Two Pointers, Expand Around Center

---

## Approach
### Expand Around Center (Optimal)
A palindrome mirrors around its center. Therefore, a palindrome can be expanded from its center, and there are only `2n - 1` such centers. The reason there are `2n - 1` and not `n` centers is because a palindrome can have an even length (e.g., "abba") where its center is between the two 'b's, or an odd length (e.g., "aba") where the center is on the 'b'.

1. For each character (and each pair of adjacent characters) in the string, we expand outward as long as the characters on the left and right match.
2. We define a `helper` function that takes the string and the starting `left` and `right` indices. It expands the window outward and returns the length of the palindrome found.
3. In the main function, for each index `i`, we check for both odd-length palindromes (center at `i`, `helper(str, i, i)`) and even-length palindromes (center between `i` and `i+1`, `helper(str, i, i+1)`).
4. We keep track of the maximum length found so far (`max_len`). If a longer palindrome is found, we update the `start` and `end` indices using the formula `start = i - (max_len - 1) / 2` and `end = i + max_len / 2`.
5. Finally, we return the substring using the `start` index and the length `end - start + 1`.

---

## Code
```cpp
#include<iostream>
using namespace std;

int helper(string& str, int left, int right){
    while(left>=0 && right<str.length() && str[left]==str[right]){
        left--;
        right++;
    }
    return right-left-1;
}

string longestPalindrome(string& str){
    int start=0,end=0;

    for(int i=0;i<str.size();i++){

        int len1=helper(str,i,i);

        int len2=helper(str,i,i+1);

        int max_len=max(len1,len2);

        if(max_len>end-start){
            start=i-(max_len-1)/2;
            end=i+max_len/2;
        }
    }
    return str.substr(start,end-start+1);
}

int main(){
    string str="babad";
    cout<<longestPalindrome(str)<<endl;
}
```

---

## Output
```
Input: str = "babad"
Output: aba
```
*(Explanation: "aba" is a valid answer. "bab" is also a valid answer. Our algorithm returns "aba".)*

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Expand Around Center | O(N^2) | O(1) |

*(Note: Expanding around the center takes O(N) time in the worst case, and we do this around `2N - 1` centers, leading to O(N^2) overall time complexity. Space complexity is O(1) as we only use a few variables for pointers.)*

---

## Key Takeaway
For substring palindrome problems, iterating through all possible centers (both single characters and between adjacent characters) and expanding outwards is an intuitive and highly space-efficient approach.
