# Problem: Search X in Sorted Array

## Problem Statement
Given an array of integers `nums` which is sorted in ascending order, and an integer `target`, write a function to search `target` in `nums`. If `target` exists, then return its index (1-based index based on the code provided). Otherwise, return `-1`.

**Link:** https://leetcode.com/problems/binary-search/ (Standard Binary Search)
**Difficulty:** Easy  
**Topic:** Binary Search, Arrays

---

## Approach
### Approach 1 (Iterative Binary Search)
This approach uses a `while` loop to repeatedly halve the search space. We maintain two pointers, `low` and `high`. At each step, we calculate the `mid` index. If the middle element is equal to the target, we return `mid + 1` (1-based indexing). If the target is less than the middle element, we adjust the `high` pointer to `mid - 1`. If the target is greater, we adjust the `low` pointer to `mid + 1`. This continues until the target is found or `low` exceeds `high`.

### Approach 2 (Recursive Binary Search)
This approach uses recursion to achieve the same logic as the iterative approach. The base condition is `low > high`, returning `-1`. Otherwise, it calculates `mid`. If the target is found, it returns `mid + 1`. If the target is smaller, it makes a recursive call on the left half `(low, mid - 1)`. If larger, it makes a recursive call on the right half `(mid + 1, high)`.

---

## Code
```cpp
// Iterative Approach (solution1.cpp)
#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int>& nums, int target){
    int low=0,high=nums.size()-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]==target) return mid+1;
        else if(target<nums[mid]) high=mid-1;
        else low=mid+1;
    }
    return -1;
}
int main(){
    vector<int> nums {1,2,3,4,5,6,7};
    int target=2;

    cout<<binarySearch(nums,target)<<endl;
}
```

```cpp
// Recursive Approach (solution2.cpp)
#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int>& nums, int low, int high, int target){

    if(low>high) return -1;

    int mid=(low+high)/2;
    
    if(nums[mid]==target) return mid+1;
    else if(target<nums[mid]) return binarySearch(nums,low,mid+1,target);
    else return binarySearch(nums,mid+1,high,target);
    
}
int main(){
    vector<int> nums {1,2,3,4,5,6,7};
    int target=2;
    int low=0,high=nums.size()-1;

    cout<<binarySearch(nums,low,high,target)<<endl;
}
```

---

## Output
```
Input: nums = {1, 2, 3, 4, 5, 6, 7}, target = 2
Output: 2
```

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Approach 1 (Iterative) | O(log N) | O(1) |
| Approach 2 (Recursive) | O(log N) | O(log N) auxiliary stack space |

---

## Key Takeaway
Binary Search drastically reduces the search space by half at each step, taking advantage of the sorted property of the array.
