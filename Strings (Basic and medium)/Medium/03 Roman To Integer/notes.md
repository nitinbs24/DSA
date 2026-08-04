# Problem: Roman to Integer

## Problem Statement
Given a roman numeral, convert it to an integer. Roman numerals are represented by seven different symbols: `I`, `V`, `X`, `L`, `C`, `D`, and `M`.

**Link:** https://leetcode.com/problems/roman-to-integer/  
**Difficulty:** Easy  
**Topic:** Strings, Hash Table

---

## Approach
### Optimal Approach
We iterate through the Roman numeral string from left to right. We use a Hash Map (or unordered_map in C++) to store the integer values corresponding to each Roman character. 

For each character at index `i` (up to the second to last character), we compare its value with the value of the next character at index `i+1`:
- If the current character's value is less than the next character's value (e.g., in "IV" where I=1 < V=5, or "IX"), it represents a subtraction case. So, we **subtract** its value from the result.
- Otherwise, it represents an addition case, and we **add** its value to the result.

Finally, outside the loop, we add the value of the last character of the string to the result since the loop terminates at `num.size() - 1` and doesn't process it.

---

## Code
```cpp
#include<iostream>
#include<unordered_map>
using namespace std;

int romanToInt(string num){
    unordered_map<char,int> roman ={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
    int res=0;
    for(int i=0;i<num.size()-1;i++){
        if(roman[num[i]]<roman[num[i+1]]) res-=roman[num[i]];
        else res+=roman[num[i]];
    }
    return res+roman[num.back()];
}

int main(){
    string num="III";
    cout<<romanToInt(num)<<endl;
}
```

---

## Output
```text
Input: s = "III"
Output: 3

Input: s = "LVIII"
Output: 58

Input: s = "MCMXCIV"
Output: 1994
```

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Approach 1 (Optimal) | O(N) | O(1) |

*(N is the length of the string. Space complexity is O(1) because the hash map always stores a constant number of 7 characters.)*

---

## Key Takeaway
When processing a sequence where the meaning of an element depends on the next element (like subtraction in Roman numerals), always check the next element. If the current element is smaller than the next, it's a subtraction case; otherwise, it's an addition case.
