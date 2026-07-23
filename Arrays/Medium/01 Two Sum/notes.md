# Problem: Two Sum

## Problem Statement
Given an array of integers `nums` and an integer `target`, return indices of the two numbers such that they add up to `target`. You may assume that each input would have exactly one solution, and you may not use the same element twice.

**Link:** [LeetCode 1 - Two Sum](https://leetcode.com/problems/two-sum/)  
**Difficulty:** Medium (Often considered Easy, but good for Medium basics)  
**Topic:** Arrays, Hash Table, Two Pointers

---

## Approach

### Approach 1: Hash Map (Optimal for Time)
We can iterate through the array once. For each element `nums[i]`, we calculate the complement `target - nums[i]`. We check if this complement exists in our hash map. If it does, we return the current index and the index of the complement. If it doesn't, we add the current element and its index to the hash map.

### Approach 2: Sorting + Two Pointers (Optimal for Space if we only needed values)
Since we need to return indices, we first store the elements along with their original indices in a vector of pairs. We sort this vector based on the elements. Then, we use two pointers (`left = 0` and `right = n - 1`). If the sum of elements at `left` and `right` equals the target, we return their original indices. If the sum is less than the target, we increment `left`. If the sum is greater, we decrement `right`.

---

## Code

### Solution 1: Hash Map
```cpp
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> twoSumChecker(vector<int>& nums,int target){
    unordered_map<int, int> mp;
    int n=nums.size();

    for(int i=0;i<n;i++){
        int num=target-nums[i];
        if(mp.find(num)!=mp.end()){
            return {mp[num],i};
        }
        mp[nums[i]]=i;
    }
    return {-1,-1};
}
int main(){
    vector<int> nums {11,43,66,22,87,21};
    int target=65;

    vector<int> res=twoSumChecker(nums,target);
    cout<<"["<<res[0]<<","<<res[1]<<"]\n";
}
```

### Solution 2: Sorting + Two Pointers
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSumIndices(vector<int> arr, int target) {
        int n = arr.size();
        vector<pair<int, int>> numsWithIndex;
        for (int i = 0; i < n; i++) {
            numsWithIndex.push_back({arr[i], i});
        }
        sort(numsWithIndex.begin(), numsWithIndex.end());

        int left = 0, right = n - 1;
        while (left < right) {
            int sum = numsWithIndex[left].first + numsWithIndex[right].first;
            if (sum == target) {
                return {numsWithIndex[left].second, numsWithIndex[right].second};
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
        return {-1, -1};
    }
};

int main() {
    Solution sol;
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 14;

    vector<int> res = sol.twoSumIndices(arr, target);
    cout << "[" << res[0] << ", " << res[1] << "]\n";

    return 0;
}
```

---

## Output

**Sample Input:**
```
nums = [11, 43, 66, 22, 87, 21], target = 65
```

**Sample Output:**
```
[1,3]
```
*(Explanation: nums[1] + nums[3] = 43 + 22 = 65)*

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Hash Map | O(N) | O(N) |
| Sorting + Two Pointers | O(N log N) | O(N) (To store pairs of value and index) |

---

## Key Takeaway
Using a Hash Map allows us to do a constant time lookup for the missing pair value, bringing the time complexity down to linear $O(N)$ at the cost of some memory.
