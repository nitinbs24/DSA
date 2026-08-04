# Problem: String to Integer (atoi)

## Problem Statement
Implement the `myAtoi(string s)` function, which converts a string to a 32-bit signed integer (similar to C/C++'s `atoi` function).

The algorithm for `myAtoi(s)` is as follows:
1. Read in and ignore any leading whitespace.
2. Check if the next character (if not already at the end of the string) is `'-'` or `'+'`. Read this character in if it is either. This determines the sign of the final result.
3. Read in next the characters until the next non-digit character or the end of the input is reached. The rest of the string is ignored.
4. Convert these digits into an integer (i.e. `"123"` → `123`, `"0032"` → `32`).
5. If no digits were read, then the integer is `0`.
6. Change the sign as necessary (from step 2).
7. If the integer is out of the 32-bit signed integer range `[-2^31, 2^31 - 1]`, clamp the integer so that it remains in the range. Specifically, integers less than `-2^31` should be clamped to `-2^31`, and integers greater than `2^31 - 1` should be clamped to `2^31 - 1`.
8. Return the integer as the final result.

**Link:** https://leetcode.com/problems/string-to-integer-atoi/  
**Difficulty:** Medium  
**Topic:** Strings, Recursion

---

## Approach
### Optimal Approach (Recursive)

The solution is split into two parts:

**`myAtoi` (main function):**
1. **Skip leading whitespace**: Increment index `i` while the current character is a space.
2. **Determine the sign**: Check if the current character is `'+'` or `'-'`. Set `sign` to `1` or `-1` accordingly, and advance the index.
3. **Delegate to helper**: Call the recursive `helper` function starting from index `i` with accumulated number `0` and the determined `sign`.

**`helper` (recursive function):**
- **Base case**: If the current index `i` is out of bounds OR the current character is not a digit, cast and return `sign * num` as an integer.
- **Recursive case**:
  1. Append the current digit to `num`: `num = num * 10 + (s[i] - '0')`.
  2. **Overflow check**: Since `num` is a `long long`, check if `sign * num` exceeds `INT_MAX` (return `INT_MAX`) or goes below `INT_MIN` (return `INT_MIN`) before the cast.
  3. Recurse to the next character: `helper(s, i+1, num, sign)`.

> **Why `long long` for `num`?** We accumulate digits before multiplying by the sign. Using `long long` prevents overflow during intermediate computation when the value might temporarily exceed `INT_MAX`.

---

## Code
```cpp
#include <cctype>
#include <climits>
#include<iostream>
using namespace std;

int helper(string& s, int i, long long num, int sign){
    if(i>=s.size() || !isdigit(s[i])) return (int) (sign*num);

    num=num*10+(s[i]-'0');

    if(sign*num<=INT_MIN) return INT_MIN;
    if(sign*num>=INT_MAX) return INT_MAX;

    return helper(s,i+1,num,sign);
}

int myAtoi(string s){
    int i=0;
    while(i<s.size() && s[i]==' ') i++;

    int sign=1;
    if(i<s.size() && (s[i]=='+' || s[i]=='-')){
        sign=(s[i]=='-')?-1:1;
        i++;
    }
    return helper(s,i,0,sign);
}

int main(){
    string s="  -1234";
    cout<<myAtoi(s)<<endl;
}
```

---

## Output
```text
Input: s = "  -1234"
Output: -1234

Input: s = "42"
Output: 42

Input: s = "   +100"
Output: 100

Input: s = "2147483648"
Output: 2147483647   (clamped to INT_MAX)

Input: s = "-2147483649"
Output: -2147483648  (clamped to INT_MIN)

Input: s = "words and 987"
Output: 0
```

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Approach 1 (Recursive) | O(N) | O(N) |

*(N is the length of the string. Space complexity is O(N) due to the recursion call stack, which can go as deep as the number of digit characters.)*

---

## Key Takeaway
When simulating multi-step string parsing (skip spaces → check sign → read digits), break the logic into clean phases. Always use a wider integer type (`long long`) for intermediate accumulation to safely detect 32-bit overflow before clamping.
