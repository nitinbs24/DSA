# Problem: Maximum Subarray Sum

## Problem Statement
Given an integer array `nums`, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

**Link:** [LeetCode 53 - Maximum Subarray](https://leetcode.com/problems/maximum-subarray/)  
**Difficulty:** Medium  
**Topic:** Arrays, Dynamic Programming

---

## Approach

### Approach 1: Nested Loops (Brute Force/Better)
We can generate all possible subarrays and calculate their sum. By using two nested loops, `i` points to the starting index and `j` iterates from `i` to the end, calculating a running sum. We keep updating the maximum sum encountered. This runs in $O(N^2)$ time.

### Approach 2: Kadane's Algorithm (Optimal)
We can find the maximum subarray sum in a single pass. 
- We maintain a running `sum` and a `maxi` sum (initialized to the smallest possible integer).
- As we iterate through the array, we add the current element to `sum` and update `maxi = max(maxi, sum)`.
- The key insight is that if the running `sum` drops below `0`, it will only pull down the sum of any subsequent subarray. Therefore, if `sum < 0`, we reset `sum = 0`.

---

## Code

### Solution 1: Nested Loops
```cpp
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int maxSubArray(vector<int>& nums){
    int maxi=INT_MIN,n=nums.size();
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=nums[j];
            maxi=max(sum,maxi);
        }
    }
    return maxi;
}

int main(){
    vector<int> nums {-2,1,-3,4,-1,2,1,-5,4};
    cout<<maxSubArray(nums)<<endl;
}
```

### Solution 2: Kadane's Algorithm (Optimal)
```cpp
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int maxSubArray(vector<int>& nums){
    int maxi=INT_MIN,n=nums.size(),sum=0;
    for(int i=0;i<n;i++){
        sum+=nums[i];
        if(sum>maxi) maxi=sum;

        if(sum<0) sum=0;
    }
    return maxi;
}

int main(){
    vector<int> nums {-2,1,-3,4,-1,2,1,-5,4};
    cout<<maxSubArray(nums)<<endl;
}
```

---

## Output

**Sample Input:**
```
[-2, 1, -3, 4, -1, 2, 1, -5, 4]
```

**Sample Output:**
```
6
```
*(Explanation: The subarray [4, -1, 2, 1] has the largest sum = 6)*

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Nested Loops | O(N²) | O(1) |
| Kadane's Algorithm | O(N) | O(1) |

---

## Key Takeaway
Kadane's Algorithm is the standard way to solve maximum subarray problems. The intuition is simple: a negative prefix sum will only hurt our chances of getting a larger maximum sum in the future, so we drop it (reset to 0).
