# Problem: Reverse an Array

## Problem Statement
Reverse the elements of a given array or vector in-place.

**Difficulty:** Easy  
**Topic:** Basic Recursion / Arrays

---

## Approach
**Two Pointers (Iterative):** Maintain two pointers, `a` at the start (0) and `b` at the end (`size - 1`). Swap the elements at these pointers, then increment `a` and decrement `b`. Continue until `a >= b`.

**Built-in Function:** Use `std::reverse(begin, end)` from the `<algorithm>` library to achieve the same result cleanly.

*(Note: While this folder is in "Basic Recursion", the current implementations are iterative and use STL.)*

---

## Code
### Two Pointers Solution
```cpp
#include<iostream>
#include<vector>
using namespace std;

void reverseArray(vector<int>& nums){
    int a=0,b=nums.size()-1;

    while(a<b){
        swap(nums[a],nums[b]);
        a++,b--;
    }
}
int main(){
    vector<int> nums {1,2,3,4,5};

    reverseArray(nums);

    for(auto num:nums) cout<<num<<endl;
}
```

---

## Output
**Sample Input:**
```
[1, 2, 3, 4, 5]
```
**Sample Output:**
```
5
4
3
2
1
```

---

## Complexity
| | Time | Space |
|---|---|---|
| Two Pointers | O(N/2) => O(N) | O(1) |
| Built-in | O(N) | O(1) |

---

## Key Takeaway
The two-pointer technique is a fundamental pattern for reversing or traversing arrays from both ends simultaneously in `O(1)` space.
