# Problem: Divide Two Integers Without Using Multiplication, Division, and Mod Operator

## Problem Statement
Given two integers `dividend` and `divisor`, divide two integers without using multiplication, division, and mod operator. Return the quotient after dividing `dividend` by `divisor`. The integer division should truncate toward zero. Handle 32-bit signed integer overflow (e.g., `INT_MIN / -1 = INT_MAX`).

**Link:** [LeetCode - Divide Two Integers](https://leetcode.com/problems/divide-two-integers/)  
**Difficulty:** Medium  
**Topic:** Bit Manipulation, Math

---

## Approach

### Approach 1: Brute Force (Repeated Addition / Subtraction)
1. Handle edge cases such as division by 1, `dividend == divisor`, or overflow (`INT_MIN / -1`).
2. Determine the sign of the quotient (`isPositive`).
3. Work with absolute values using `long long` to prevent overflow.
4. Keep adding `divisor` to a running `sum` in a loop while `sum + divisor <= dividend`, incrementing `ans` by `1` in each step.
5. Return `ans` with the appropriate sign.

*Drawback:* If `dividend = 2^31 - 1` and `divisor = 1`, the loop runs ~2 × 10⁹ times, resulting in Time Limit Exceeded (TLE).

### Approach 2: Optimal (Bit Manipulation / Exponential Shift)
Instead of subtracting/adding `divisor` one by one, we can shift `divisor` to the left (multiplying by powers of 2) to quickly subtract the largest possible chunk:
1. For the current `dividend`, find the maximum `count` such that `(divisor << (count + 1)) <= dividend`.
2. Add `(1 << count)` to the quotient `ans`.
3. Subtract `(divisor << count)` from `dividend`.
4. Repeat the process until `dividend < divisor`.

---

## Code

### Approach 1 (Brute Force - Linear Subtraction)
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor) return 1;
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        if(divisor == 1) return dividend;
        
        bool isPositive = true;
        if(dividend >= 0 && divisor < 0) 
            isPositive = false;
        else if(dividend < 0 && divisor > 0)
            isPositive = false;
            
        long long n = dividend;
        long long d = divisor;

        n = abs(n);
        d = abs(d);
        
        long long ans = 0, sum = 0;
        
        while(sum + d <= n) {
           ans++;
           sum += d;
        }
        
        if(ans > INT_MAX && isPositive) 
            return INT_MAX;
        if(ans > INT_MAX && !isPositive)
            return INT_MIN;
        
        return isPositive ? ans : -1*ans;
    }
};

int main() {
    int dividend = 10, divisor = 3;
    
    Solution sol; 
    int ans = sol.divide(dividend, divisor);
    
    cout << "The result of dividing " << dividend << " and " << divisor << " is " << ans;
    
    return 0;
}
```

### Approach 2 (Optimal - Bit Shifting)
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == divisor) return 1;
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        if (divisor == 1) return dividend;

        bool isPositive = (dividend < 0) == (divisor < 0);

        long long n = abs((long long)dividend);
        long long d = abs((long long)divisor);
        long long ans = 0;

        while (n >= d) {
            int count = 0;
            while (n >= (d << (count + 1))) {
                count++;
            }
            ans += (1LL << count);
            n -= (d << count);
        }

        if (ans > INT_MAX && isPositive) return INT_MAX;
        if (ans > INT_MAX && !isPositive) return INT_MIN;

        return isPositive ? ans : -ans;
    }
};
```

---

## Output
```
The result of dividing 10 and 3 is 3
```

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Approach 1 (Brute Force - Linear Subtraction) | O(Quotient) | O(1) |
| Approach 2 (Optimal - Bit Shifting) | O((log₂ N)²) | O(1) |

---

## Key Takeaway
Multiplying/dividing by powers of 2 can be done using bitwise shift operators (`<<` and `>>`). Bit shifting the divisor exponentially reduces division from $O(\text{Quotient})$ linear subtraction down to $O(\log^2 N)$ time complexity.
