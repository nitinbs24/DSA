# Problem: Smallest Divisor Given Threshold

## Problem Statement
Given an array of integers `nums` and an integer `threshold`, we will choose a positive integer `divisor`, divide all the array by it, and sum the division's result. Find the smallest `divisor` such that the result mentioned above is less than or equal to `threshold`. Each result of the division is rounded to the nearest integer greater than or equal to that element (i.e., ceiling).

**Link:** https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/  
**Difficulty:** Medium  
**Topic:** Binary Search on Answers, Arrays

---

## Approach
### Approach 1 (Optimal - Binary Search on Answer)
The search space for the divisor is `[1, max(nums)]`. We perform a binary search in this range.
- For a candidate `mid`, we calculate the sum of divisions using ceiling logic: `sum += (nums[i] - 1) / mid + 1`.
- If the `sum <= threshold`, this `mid` is a valid divisor. We store it and try to find an even smaller divisor by searching left (`high = mid - 1`).
- If the `sum > threshold`, the divisor is too small (causing the sum to be too large), so we search right (`low = mid + 1`).

---

## Code
```cpp
#include<iostream>
#include<vector>
//#include<cmath>
#include<algorithm>
using namespace std;

int smallestDivisor(vector<int>& nums,int threshold){

    int low=1, high=*max_element(nums.begin(),nums.end());
    int ans=0;
    while(low<=high){

        long long sum=0;
        int mid=low+(high-low)/2;
        for(int i=0;i<nums.size();i++){
            sum+=(nums[i]-1)/mid+1;
        }
        if(sum<=threshold){
            ans=mid;
            high=mid-1;
        }
        else low=mid+1;
    }
    return ans;
}

int main(){
    vector<int> nums {1,2,5,9};
    int threshold=6;

    cout<<smallestDivisor(nums,threshold)<<endl;
}
```

---

## Output
```
Input: nums = [1,2,5,9], threshold = 6
Output: 5
```

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Approach 1 (Optimal) | O(N * log(max(nums))) | O(1) |

---

## Key Takeaway
Using `(numerator - 1) / denominator + 1` is a robust way to compute the ceiling of division for positive integers without using floating-point math or the `<cmath>` library.
