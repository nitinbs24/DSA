# Problem: Longest Subarray with Given Sum K

## Problem Statement
Given an array `nums` of size `n` and an integer `k`, find the length of the longest contiguous subarray whose elements sum up to `k`. If no such subarray exists, return `0`.

**Link:** [GeeksforGeeks - Longest Subarray with Sum K](https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1)  
**Difficulty:** Easy  
**Topic:** Arrays, Two Pointers, Sliding Window

---

## Approach

### Approach 1: Brute Force (Three Nested Loops)
Generate all possible subarrays using two pointers `startIndex` and `endIndex`. For every pair of `(startIndex, endIndex)`, calculate the sum of elements in `nums[startIndex...endIndex]` using a third loop. If `currentSum == k`, update `maxLength = max(maxLength, endIndex - startIndex + 1)`.

### Approach 2: Optimal (Two Pointers / Sliding Window)
For arrays with non-negative numbers, we can use the dynamic sliding window technique:
1. Maintain two pointers `left` and `right` starting at `0`, and a running `sum = nums[0]`.
2. Expand the window to the right by incrementing `right` and adding `nums[right]` to `sum`.
3. Whenever `sum > k`, shrink the window from the left by subtracting `nums[left]` and incrementing `left` until `sum <= k`.
4. Whenever `sum == k`, update `maxLength = max(maxLength, right - left + 1)`.
5. Repeat until `right` reaches the end of the array.

---

## Code

### Approach 1 (Brute Force)
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestSubarray(vector<int> &nums, int k)
    {
        int n = nums.size(); 
        int maxLength = 0;

        for (int startIndex = 0; startIndex < n; startIndex++) { 
            for (int endIndex = startIndex; endIndex < n; endIndex++) { 
                int currentSum = 0;
                for (int i = startIndex; i <= endIndex; i++) {
                    currentSum += nums[i];
                }

                if (currentSum == k)
                    maxLength = max(maxLength, endIndex - startIndex + 1);
            }
        }
        return maxLength;
    }
};

int main()
{
    vector<int> a = { -1, 1, 1 };
    int k = 1;

    Solution solution;
    int len = solution.longestSubarray(a, k);
    
    cout << "The length of the longest subarray is: " << len << "\n";
    return 0;
}
```

### Approach 2 (Optimal - Two Pointers)
```cpp
#include<iostream>
#include<vector>
using namespace std;

int longestSubarray(vector<int>& nums,int k){
    int sum=nums[0],maxLength=0;
    int left=0,right=0;
    int n=nums.size();
    while(right<n){
        while(left<=right && sum>k){
            sum-=nums[left];
            left++;
        }

        if(sum==k) maxLength=max(maxLength,right-left+1);

        right++;

        if(right<n) sum+=nums[right];
    }
    return maxLength;
}

int main() {
    vector<int> nums = {10, 5, 2, 7, 1, 9};
    int k = 15;

    int ans = longestSubarray(nums, k);

    cout << "The length of longest subarray having sum k is: " << ans;

    return 0;
}
```

---

## Output
```
Input: nums = [10, 5, 2, 7, 1, 9], k = 15
Output: 4
(The longest subarray having sum 15 is [5, 2, 7, 1])
```

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Approach 1 (Brute Force) | O(N³) | O(1) |
| Approach 2 (Optimal - Two Pointers) | O(N) | O(1) |

---

## Key Takeaway
For non-negative numbers, the sliding window / two-pointer pattern guarantees an O(N) time complexity because both `left` and `right` pointers move forward monotonically without stepping back.
