# Problem: Largest Odd Number in String

## Problem Statement
Given a string `num`, representing a large integer, return the largest-valued odd integer (as a string) that is a non-empty substring of `num`, or an empty string `""` if no odd integer exists. A substring is a contiguous sequence of characters within a string.

**Link:** https://leetcode.com/problems/largest-odd-number-in-string/  
**Difficulty:** Easy  
**Topic:** String, Math

---

## Approach
**Optimal Approach (Greedy / Right-to-Left Traversal):**
The largest odd number substring must end with an odd digit. To maximize the value of the substring, it should be as long as possible. Therefore, we can start checking from the end (rightmost side) of the string towards the beginning.
1. Traverse the string `num` backwards (from `length - 1` down to `0`).
2. Find the first character that represents an odd digit (i.e., `(num[i] - '0') % 2 == 1`).
3. Once found, this character is the last digit of the largest odd number.
4. Record its index `ind`.
5. Since a number should ideally not have leading zeros, traverse from the beginning (`0` index) to skip any leading `'0'` characters up to index `ind`.
6. Return the substring starting from the first non-zero character up to the found odd digit index `ind`. If no odd digit was found, return an empty string.

---

## Code
```cpp
#include<iostream>
#include <string>
using namespace std;

string largestOddNumber(string num){
    int ind=-1;
    for(int i=num.length()-1;i>=0;i--){
        if((num[i]-'0')%2==1){
            ind=i;
            break;
        }
    }
    
    int i=0;
    while(i<=ind && num[i]=='0') i++;

    return num.substr(i,ind-i+1);
}

int main(){
    string num="02468";
    cout<<largestOddNumber(num)<<endl;
}
```

---

## Output
**Input:** `num = "52"`  
**Output:** `"5"`  

**Input:** `num = "02468"`  
**Output:** `""`  

**Input:** `num = "35427"`  
**Output:** `"35427"`  

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Optimal (Greedy) | O(N) | O(1) |

*(Where N is the length of the string `num`. The space complexity is O(1) auxiliary space, ignoring the space for the returned substring).*

---

## Key Takeaway
To find the largest odd number as a substring, simply find the rightmost odd digit. The optimal choice is always the substring extending from the first non-zero digit of the string to that rightmost odd digit.
