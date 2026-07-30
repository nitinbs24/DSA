# Problem: Longest Common Prefix

## Problem Statement
Write a function to find the longest common prefix string amongst an array of strings. If there is no common prefix, return an empty string `""`.

**Link:** https://leetcode.com/problems/longest-common-prefix/  
**Difficulty:** Easy  
**Topic:** String

---

## Approach
**Optimal Approach (Sorting):**
The idea is to sort the array of strings. Once the array is sorted alphabetically, the strings that are most different from each other will be at the beginning and the end of the sorted array. Therefore, the longest common prefix of all strings in the array will simply be the common prefix of the first string and the last string. We compare the first and the last string character by character until a mismatch is found or one of the strings ends.

---

## Code
```cpp
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

string longestCommonPrefix(vector<string> str){
    string ans="";
    sort(str.begin(),str.end());
    string first=str[0], last=str[str.size()-1];
    int minLeng=min(first.size(),last.size());
    
    for(int i=0;i<minLeng;i++){
        if(first[i]!=last[i]) break;
        ans+=first[i];
    }
    return ans;
}

int main(){
    vector<string> str {"interview", "internet", "internal", "interval"};

    cout<<longestCommonPrefix(str)<<endl;
}
```

---

## Output
```
Input: strs = {"interview", "internet", "internal", "interval"}
Output: inter
```

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Optimal (Sorting) | `O(N * L * log(N))` | `O(1)` |

*(Where N is the number of strings and L is the maximum length of a string)*

---

## Key Takeaway
Sorting the strings simplifies the problem to just comparing the first and the last string, as they will have the most dissimilar prefixes.
