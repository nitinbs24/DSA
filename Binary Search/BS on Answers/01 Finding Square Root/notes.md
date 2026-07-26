# Problem: Finding Square Root

## Problem Statement
Given a non-negative integer `x`, compute and return the square root of `x`. Since the return type is an integer, the decimal digits are truncated, and only the integer part of the result is returned. Note: You are not allowed to use any built-in exponent function or operator, such as `pow(x, 0.5)` or `x ** 0.5`.

**Link:** https://leetcode.com/problems/sqrtx/  
**Difficulty:** Easy  
**Topic:** Binary Search on Answers, Math

---

## Approach
### Approach 1 (Optimal - Binary Search on Answer)
To find the square root of `x`, we can search for the answer in the range `[1, x/2]` (for `x >= 2`). We calculate the `mid` value. If `mid * mid <= x`, it means `mid` is a potential answer. We store it and move to the right half (`low = mid + 1`) to find a larger valid integer. If `mid * mid > x`, `mid` is too large to be the square root, so we search in the left half (`high = mid - 1`). Base cases are handled separately (if `x < 2`, return `x`).

---

## Code
```cpp
#include<iostream>
using namespace std;

int mySqrt(int x){
    if(x<2) return x;

    int low=1,high=x/2,ans;

    while(low<=high){
        int mid=low+(high-low)/2;

        if(mid*mid<=x){ 
            ans=mid;
            low=mid+1;
        }
        else high=mid-1;
    }
    return ans;
}

int main(){
    int x=16;
    cout<<mySqrt(x)<<endl;
}
```

---

## Output
```
Input: x = 16
Output: 4
```

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Approach 1 (Optimal) | O(log N) | O(1) |

---

## Key Takeaway
For monotonic search spaces (like finding a number `ans` such that `ans^2 <= x`), "Binary Search on Answers" is a highly efficient technique.
