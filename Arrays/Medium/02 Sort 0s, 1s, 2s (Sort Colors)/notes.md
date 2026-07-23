# Problem: Sort Colors (Sort 0s, 1s, and 2s)

## Problem Statement
Given an array `nums` with `n` objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue. We will use the integers `0`, `1`, and `2` to represent the color red, white, and blue, respectively.

**Link:** [LeetCode 75 - Sort Colors](https://leetcode.com/problems/sort-colors/)  
**Difficulty:** Medium  
**Topic:** Arrays, Two Pointers, Sorting

---

## Approach

### Approach 1: Counting (Two Passes)
We can traverse the array and count the number of 0s, 1s, and 2s. After counting, we clear the array (or just overwrite it) and append the exact number of 0s, then 1s, then 2s. This takes two passes over the array.

### Approach 2: Dutch National Flag Algorithm (One Pass - Optimal)
This algorithm uses three pointers: `low`, `mid`, and `high`.
- Elements from `0` to `low - 1` are `0`s.
- Elements from `low` to `mid - 1` are `1`s.
- Elements from `mid` to `high` are unclassified.
- Elements from `high + 1` to `n - 1` are `2`s.

We iterate with the `mid` pointer.
- If `nums[mid] == 0`: swap `nums[low]` and `nums[mid]`, then increment both `low` and `mid`.
- If `nums[mid] == 1`: just increment `mid`.
- If `nums[mid] == 2`: swap `nums[mid]` and `nums[high]`, then decrement `high`. (Do not increment `mid` here because the swapped element needs to be evaluated).

---

## Code

### Solution 1: Counting Sort (Two Passes)
```cpp
#include<iostream>
#include<vector>
using namespace std;

void sortColors(vector<int>& nums){
    int zero=0,one=0,two=0;

    for(int i=0;i<nums.size();i++){
        if(nums[i]==0) zero++;
        else if (nums[i]==1) one++;
        else two++;
    }
    nums.clear();
    while(zero--) nums.push_back(0);
    while(one--) nums.push_back(1);
    while(two--) nums.push_back(2);
}
int main(){
    vector<int> nums {2,1,1,0,1,2,0};
    sortColors(nums);
    for(auto num: nums) cout<<num;
    cout<<"\n";
}
```

### Solution 2: Dutch National Flag Algorithm (One Pass)
```cpp
#include<iostream>
#include<vector>
#include<utility>
using namespace std;

void sortColors(vector<int>& nums){
    int low=0,high=nums.size()-1,mid=0;

    while(mid<=high){
        if(nums[mid]==0){
            swap(nums[low],nums[mid]);
            low++; mid++;
        }
        else if(nums[mid]==1) mid++;
        else{
            swap(nums[mid],nums[high]);
            high--;
        }
    }
}
int main(){
    vector<int> nums {2,1,1,0,1,2,0};
    sortColors(nums);
    for(auto num: nums) cout<<num;
    cout<<"\n";
}
```

---

## Output

**Sample Input:**
```
[2, 1, 1, 0, 1, 2, 0]
```

**Sample Output:**
```
0011122
```

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Counting Sort | O(2N) | O(1) |
| Dutch National Flag | O(N) | O(1) |

---

## Key Takeaway
The Dutch National Flag algorithm is an elegant application of the three-pointer technique. It sorts an array of 3 distinct elements in exactly one pass and constant space.
