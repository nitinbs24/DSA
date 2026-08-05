# Problem: Count Number of Strings

## Problem Statement
Given a string of lowercase alphabets, count all possible substrings (not necessarily distinct) that have exactly `k` distinct characters.

**Link:** [GeeksforGeeks - Count number of substrings with exactly k distinct characters](https://www.geeksforgeeks.org/count-number-of-substrings-with-exactly-k-distinct-characters/)  
**Difficulty:** Medium  
**Topic:** String, Sliding Window, Hash Map

---

## Approach

### Optimal (Sliding Window)
Finding substrings with exactly `k` distinct characters directly is difficult. Instead, we can use the following mathematical property:
**Exactly $k$ distinct characters** = (At most $k$ distinct characters) - (At most $k-1$ distinct characters).

We can implement a sliding window function, `kSubstring(string str, int k)`, which returns the count of substrings with at most `k` distinct characters.
1. We use an `unordered_map` to keep track of the frequency of characters in the current window.
2. We expand our window by moving the `right` pointer and incrementing the frequency of the current character.
3. If the number of distinct characters in our map exceeds `k`, we shrink the window by moving the `left` pointer and decrementing the frequency of the character at `left`. We remove the character from the map if its frequency reaches 0.
4. For every valid window `[left, right]`, the number of valid substrings ending at `right` is `(right - left + 1)`. We add this to our result.
5. The final answer is `kSubstring(str, k) - kSubstring(str, k - 1)`.

---

## Code
```cpp
#include<iostream>
#include <unordered_map>
using namespace std;

int kSubstring(string& str, int k){
    int left=0,res=0;
    unordered_map<char,int> freq;

    for(int right=0;right<str.size();right++){
        freq[str[right]]++;

        while(freq.size()>k){
            freq[str[left]]--;
            if(freq[str[left]]==0) freq.erase(str[left]);
            left++;
        }
        res+=(right-left+1);
    }
    return res;
}

int countSubstring(string& str, int k){
    return kSubstring(str,k)-kSubstring(str,k-1);
}

int main(){
    string str="pqpqs";
    int k=2;

    cout<<"Count: "<<countSubstring(str,k)<<endl;
}
```

---

## Output
```
Input: str = "pqpqs", k = 2
Output: Count: 7
```
*(Explanation: The substrings with exactly 2 distinct characters are "pq", "pqp", "pqpq", "qp", "qpq", "pq", "qs".)*

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Optimal (Sliding Window) | O(N) | O(1) |

*(Note: Space complexity is O(1) because the hash map will store at most 26 lowercase English letters)*

---

## Key Takeaway
To find the count of subarrays/substrings with **exactly** `k` elements fulfilling a condition, calculate it using `atMost(k) - atMost(k-1)`.
