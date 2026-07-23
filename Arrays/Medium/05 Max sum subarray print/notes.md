# Problem: Print the Maximum Sum Subarray

## Problem Statement
Given an integer array `nums`, find the contiguous subarray (containing at least one number) which has the largest sum, and print that subarray itself (along with its maximum sum).

**Link:** (Extension of LeetCode 53)  
**Difficulty:** Medium  
**Topic:** Arrays, Dynamic Programming

---

## Approach

### Approach: Kadane's Algorithm with Index Tracking
This is a straightforward extension of Kadane's Algorithm. To print the subarray, we simply need to track its start and end indices.
- When `sum == 0` (which happens at the beginning or right after resetting a negative prefix), it means a new subarray is starting. We record this index as `start`.
- Whenever we find a new maximum `sum > maxi`, it means our current contiguous sequence from `start` to `i` yields the best result so far. We update `ansStart = start` and `ansEnd = i`.
- If `sum < 0`, we reset `sum = 0`.
At the end of the loop, the subarray causing the maximum sum resides between `nums[ansStart]` and `nums[ansEnd]`.

---

## Code

### Solution: Modified Kadane's Algorithm
```cpp
#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int maxi=INT_MIN, start=0, sum=0, ansStart=-1, ansEnd=-1;
    
    for(int i=0;i<nums.size();i++){
        if(sum==0) start=i; // Potential new start of max subarray

        sum+=nums[i];

        if(sum>maxi){
            maxi=sum;
            ansStart=start;
            ansEnd=i;
        }

        if(sum<0) sum=0;
    }
    
    cout << "The subarray is: [";
    for (int i = ansStart; i <= ansEnd; i++) {
        cout << nums[i] << " ";
    }
    cout << "]" << endl;
    
    return maxi;
}

int main() {
    vector<int> arr = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
    int maxSum = maxSubArray(arr);
    cout << "The maximum subarray sum is: " << maxSum << endl;
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
The subarray is: [4 -1 2 1 ]
The maximum subarray sum is: 6
```

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Kadane's with tracking | O(N) | O(1) |

---

## Key Takeaway
Whenever you need to *reconstruct* or *print* the result of a dynamic programming/greedy algorithm (like Kadane's), think about which variables represent the boundaries of the answer and update them alongside your running maximum variable.
