# Problem: Check if Array is Sorted and Rotated

## Problem Statement
Given an array `nums`, return `true` if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return `false`.

**Link:** [LeetCode 1752 - Check if Array Is Sorted and Rotated](https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/)  
**Difficulty:** Easy  
**Topic:** Arrays

---

## Approach

### Approach 1: Counting "Drops" (Optimal)
In a sorted array that is rotated, there will be at most **one** point where the order breaks (i.e., `nums[i-1] > nums[i]`). We call this a "drop". 
- If the array is perfectly sorted and not rotated, there will be `0` drops.
- If it is sorted and rotated, there will be exactly `1` drop. 
- Additionally, we must check the boundary wrap-around: `nums[n-1]` should not be greater than `nums[0]` if a drop has occurred. If it is, that's considered a drop too.
So if the total number of drops is `<= 1`, the array is sorted and rotated. If there are `>= 2` drops, it's not.

---

## Code

### Solution 1: Optimal One Pass
```cpp
#include<iostream>
#include<vector>
using namespace std;

bool checkSort(vector<int>& nums){
    int drop=0;
    for(int i=1;i<nums.size();i++){
        if(nums[i-1]>nums[i]) drop++;
    }
    // Check circular break
    if(nums[nums.size()-1]>nums[0]) drop++;

    return drop<2;
}

int main(){
    vector<int> nums {4,5,1,2,3};
    cout<<checkSort(nums)<<endl;
}
```

---

## Output

**Sample Input:**
```
4 5 1 2 3
```

**Sample Output:**
```
1 (true)
```

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Optimal | O(N) | O(1) |

---

## Key Takeaway
When dealing with circular array properties, visualizing the array as a ring helps. In a sorted circular array, there can only be at most one break in the non-decreasing sequence.
