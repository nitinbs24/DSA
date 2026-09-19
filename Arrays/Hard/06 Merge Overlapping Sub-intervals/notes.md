# Problem: Merge Overlapping Sub-intervals

## Problem Statement
Given an array of `intervals` where `intervals[i] = [start_i, end_i]`, merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

Two intervals `[a, b]` and `[c, d]` overlap if `c <= b` (assuming `a <= c`).

**Link:** [LeetCode 56 - Merge Intervals](https://leetcode.com/problems/merge-intervals/)  
**Difficulty:** Medium (Hard in Striver's Sheet)  
**Topic:** Arrays, Sorting, Two Pointers

---

## Approach

### Approach 1: Sorting + Nested Grouping (Two Pointers / Lookahead)
1. **Sort the intervals** by their start times: `sort(nums.begin(), nums.end())`. Sorting ensures that all intervals that could possibly overlap are placed contiguously.
2. Maintain an outer pointer `i` starting at index `0`:
   - Set current interval boundaries: `start = nums[i][0]` and `end = nums[i][1]`.
   - Run an inner pointer `j = i + 1` to check subsequent intervals:
     - If `nums[j][0] <= end`, interval `j` overlaps with the current merged range. Extend the boundary: `end = max(end, nums[j][1])` and advance `j++`.
     - As soon as `nums[j][0] > end`, interval `j` does not overlap. Break out of the inner loop.
   - Push `{start, end}` into the answer list `ans`.
   - Update `i = j` to jump directly to the next unmerged interval.
- **Complexity:** Sorting takes $O(N \log N)$. In the traversal, each element is visited at most twice, taking $O(N)$ time. Total time is $O(N \log N)$.

### Approach 2: Optimal Single Pass Insertion (Linear Scan with `ans.back()`)
Instead of lookahead with a nested `while` loop, we can build the merged list incrementally in a single clean pass:
1. **Sort the intervals** by start time: `sort(nums.begin(), nums.end())`.
2. Initialize an empty result vector `ans`.
3. Iterate through each interval `num` in the sorted list:
   - **Case 1 (No Overlap / First Interval):** If `ans` is empty OR the current interval's start is strictly greater than the last merged interval's end (`ans.back()[1] < num[0]`), then `num` represents a new, disjoint interval. Push `num` into `ans`.
   - **Case 2 (Overlap):** If the current interval starts before or at the end of the last merged interval (`num[0] <= ans.back()[1]`), merge them by extending the last interval's end:
     $$\text{ans.back()[1]} = \max(\text{ans.back()[1]}, \text{num}[1])$$
4. Return `ans`.
- **Advantage:** Eliminates manual index handling and provides cleaner, idiomatic code while running in the same $O(N \log N)$ optimal time.

---

## Code

### Solution 1: Sorting + Nested Grouping
```cpp
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
    public:
    vector<vector<int>> merge(vector<vector<int>> nums){
        int n=nums.size();

        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<n;){
            int start=nums[i][0];
            int end=nums[i][1];

            int j=i+1;
            while(j<n && nums[j][0]<=end){
                end=max(end,nums[j][1]);
                j++;
            }
            ans.push_back({start,end});
            i=j;
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> nums = {{1,3}, {2,6}, {8,10}, {15,18}};
    vector<vector<int>> result = sol.merge(nums);

    for (auto interval : result) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
}
```

### Solution 2: Optimal Single Pass Insertion
```cpp
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
    public:
    vector<vector<int>> merge(vector<vector<int>> nums){

        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;

        for(auto num:nums){
            if(ans.empty() || ans.back()[1]<num[0]) ans.push_back(num);
            else ans.back()[1]=max(ans.back()[1],num[1]);
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> nums = {{1,3}, {2,6}, {8,10}, {15,18}};
    vector<vector<int>> result = sol.merge(nums);

    for (auto interval : result) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
}
```

---

## Output

**Sample Input 1:**
```
intervals = [[1, 3], [2, 6], [8, 10], [15, 18]]
```

**Sample Output 1:**
```
[1,6] [8,10] [15,18] 
```
*(Explanation: Since intervals [1, 3] and [2, 6] overlap, merge them into [1, 6].)*

**Sample Input 2:**
```
intervals = [[1, 4], [4, 5]]
```

**Sample Output 2:**
```
[1,5] 
```
*(Explanation: Intervals [1, 4] and [4, 5] are considered overlapping because they share the boundary point 4.)*

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Approach 1 (Sorting + Grouping) | O(N log N) | O(1) |
| Approach 2 (Optimal Single Pass) | O(N log N) | O(1) |

*(Note: Sorting the array dominates the time complexity at O(N log N). Traversal takes O(N). Auxiliary space is O(1) excluding the space required for the returned merged intervals and internal sorting stack.)*

---

## Key Takeaway
Always **sort intervals by their start time** first. Once sorted, overlapping intervals are guaranteed to be consecutive, allowing you to merge in a single linear scan simply by comparing each incoming interval against `ans.back()` and extending `ans.back()[1] = max(ans.back()[1], current[1])`.
