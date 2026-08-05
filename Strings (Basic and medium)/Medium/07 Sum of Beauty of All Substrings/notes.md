# Problem: Sum of Beauty of All Substrings

## Problem Statement
Given a string `s`, the **beauty** of a substring is defined as the difference between the **maximum** frequency of any character in that substring and the **minimum** frequency of any character in that substring.

Return the **sum of beauty** of all substrings of `s`.

**Link:** https://leetcode.com/problems/sum-of-beauty-of-all-substrings/  
**Difficulty:** Medium  
**Topic:** Strings, Hash Map

---

## Approach

### Brute Force (Incremental Frequency Map) — O(n² × 26)

We iterate over every possible substring using two nested loops (`i` as the start, `j` as the end). For each substring, we maintain a frequency map (`unordered_map<char, int>`) that is **built incrementally** — as we extend `j`, we just add one character to the existing map (avoiding recomputing the entire frequency from scratch).

After updating the frequency map for each `(i, j)` pair, we do a **linear scan over the map** to find the minimum and maximum frequencies. The beauty of that substring is `max_freq - min_freq`, which we add to the running total.

**Key Steps:**
1. Outer loop fixes the starting index `i`.
2. Inner loop extends the end index `j` from `i` to `n-1`, incrementally updating the frequency map.
3. For each `(i, j)` pair, scan the frequency map to get `max` and `min` frequency values.
4. Add `(max - min)` to the sum.
5. Return the total sum.

**Why no further optimization?**  
Finding the min/max frequency inherently requires scanning all characters in the frequency map for each substring. The incremental update reduces redundant work (from O(n) per extension to O(1)), but the map scan still runs O(26) times per pair. Since there are at most 26 unique lowercase letters, this is treated as a constant.

---

## Code
```cpp
#include <climits>
#include <iostream>
#include <unordered_map>
using namespace std;

int beautySum(string& str) {
    int n = str.size();
    int sum = 0;

    for (int i = 0; i < n; i++) {
        unordered_map<char, int> freq;
        for (int j = i; j < n; j++) {
            freq[str[j]]++;

            int mini = INT_MAX;
            int maxi = INT_MIN;

            for (auto a : freq) {
                mini = min(mini, a.second);
                maxi = max(maxi, a.second);
            }
            sum += (maxi - mini);
        }
    }
    return sum;
}

int main() {
    string str = "aabcb";
    cout << beautySum(str) << endl;
}
```

---

## Output

**Input:** `"aabcb"`

| Substring | Max Freq | Min Freq | Beauty |
|-----------|----------|----------|--------|
| `"aab"`   | 2 (a)    | 1 (b)    | 1      |
| `"aabc"`  | 2 (a)    | 1 (b/c)  | 1      |
| `"aabcb"` | 2 (a/b)  | 1 (c)    | 1      |
| `"abcb"`  | 2 (b)    | 1 (a/c)  | 1      |
| `"bcb"`   | 2 (b)    | 1 (c)    | 1      |
| All other substrings |  |  | 0 |

**Output:** `5`

---

## Complexity

| Approach | Time | Space |
|---|---|---|
| Brute Force (Incremental Map) | O(n² × 26) ≈ O(n²) | O(26) = O(1) |

> The inner map scan is bounded by at most 26 characters (lowercase English letters), making it effectively a constant factor.

---

## Key Takeaway
When iterating over all substrings, **incrementally updating** a frequency map (instead of rebuilding from scratch for each substring) reduces redundant work significantly. For character frequency problems, the alphabet size (26) acts as a constant upper bound that simplifies both implementation and complexity analysis.
