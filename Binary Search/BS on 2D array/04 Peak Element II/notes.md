# Problem: Peak Element II

## Problem Statement
A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right, top, and bottom. Given an `m x n` matrix `mat` where no two adjacent cells are equal, find any peak element and return its coordinates.

**Link:** https://leetcode.com/problems/find-a-peak-element-ii/
**Difficulty:** Medium  
**Topic:** Binary Search, 2D Arrays

---

## Approach
### Approach 1 (Optimal - Binary Search on Columns)
We can apply binary search on the columns of the matrix (from `0` to `m-1`). For the middle column `mid`, we find the global maximum element in that column. Let's say it's at `row`. Because it is the maximum in its column, it is guaranteed to be strictly greater than its top and bottom neighbors. 
Thus, we only need to check its left and right neighbors:
- If it is greater than both its left and right neighbors, it is a peak element! We return `{row, mid}`.
- If its left neighbor is greater than it, a peak must exist in the left half, so we search left (`high = mid - 1`).
- Otherwise, a peak must exist in the right half, so we search right (`low = mid + 1`).

---

## Code
```cpp
#include <climits>
#include<iostream>
#include<vector>
using namespace std;

int findMax(vector<vector<int>>& nums,int col){
    int max_num=INT_MIN,ans;
    for(int i=0;i<nums.size();i++){
        if(nums[i][col]>max_num){
            max_num=nums[i][col];
            ans=i;
        }
    }
    return ans;
}

vector<int> findPeakGrid(vector<vector<int>>& nums){
    int n=nums.size(), m=nums[0].size();

    int low=0,high=m-1;;

    while(low<=high){
        int mid=(low+high)/2;

        int row=findMax(nums,mid);

        int left=mid-1>=0?nums[row][mid-1]:INT_MIN;
        int right=mid+1<m?nums[row][mid+1]:INT_MIN;

        if(nums[row][mid]>left && nums[row][mid]>right) return {row,mid};
        else if(left>nums[row][mid]) high=mid-1;
        else low=mid+1;
    }
    return {-1,-1};
}

int main(){
    vector<vector<int>> nums {{5, 10, 8}, {4, 25, 7}, {3, 9, 6}};

    vector<int> ans =findPeakGrid(nums);
    cout<<"["<<ans[0]<<","<<ans[1]<<"]\n";
}
```

---

## Output
```
Input: nums = {{5, 10, 8}, {4, 25, 7}, {3, 9, 6}}
Output: [1,1]
```

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Approach 1 (Optimal) | O(N * log M) | O(1) |

---

## Key Takeaway
Finding the maximum element in a specific dimension (column) satisfies the peak condition for that dimension automatically. This allows you to reduce a 2D peak finding problem into a 1D binary search problem over the columns.
