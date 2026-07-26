# Problem: Nth Root of a number

## Problem Statement
Given two integers `N` and `M`, find the `N`th root of `M`. If the `N`th root is not an integer, return `-1`.

**Link:** https://www.geeksforgeeks.org/problems/find-nth-root-of-m5843/1  
**Difficulty:** Medium  
**Topic:** Binary Search on Answers, Math

---

## Approach
### Approach 1 (Optimal - Binary Search on Answer)
We know the `N`th root of a number `x` lies in the range `[1, x]`. We can use binary search on this search space. For a given `mid`, we compute `mid^N` using a loop. 
- If `mid^N == x`, we return `mid`.
- If `mid^N < x`, the answer must be greater, so we search the right half (`low = mid + 1`).
- If `mid^N > x`, the answer must be smaller, so we search the left half (`high = mid - 1`).
To avoid integer overflow, we can break out of the multiplication loop early if the running product exceeds `x`.

---

## Code
```cpp
#include<iostream>
using namespace std;

int myRoot(int n, int x){
    int low=1, high=x;

    while(low<=high){
        int ans=1, mid=(low+high)/2;

        for(int i=0;i<n;i++){
            ans*=mid;
            if(ans>x) break; // prevent overflow and unnecessary computation
        }
        if(ans==x) return mid;
        else if(ans<x) low=mid+1;
        else high=mid-1;

    }
    return -1;
}

int main(){
    int x=27,n=3;
    cout<<myRoot(n,x)<<endl;
}
```

---

## Output
```
Input: n = 3, x = 27
Output: 3
```

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Approach 1 (Optimal) | O(N * log(M)) | O(1) |

---

## Key Takeaway
Binary Search can be generalized to find the inverse of any monotonically increasing function, such as finding roots. Breaking early during exponentiation is a crucial optimization to avoid integer overflow.
