# Problem: Lower Bound

## Problem Statement
Given a sorted array of `N` integers and an integer `X`, find the lower bound of `X`. The lower bound is the index of the first element in the array which is greater than or equal to `X`. If no such element exists, the lower bound is the size of the array.

**Link:** https://www.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1 (Similar concept, exact problem is lower bound)
**Difficulty:** Easy  
**Topic:** Binary Search, Arrays

---

## Approach
### Approach 1 (Optimal - Binary Search)
We can use a modified binary search to find the lower bound. We maintain an `ans` variable initialized to the size of the array (representing the hypothetical index out of bounds). We compute `mid`. If `nums[mid] >= x`, it means `mid` could be our answer, so we update `ans = mid`, but since we want the *first* such element, we continue searching in the left half by setting `high = mid - 1`. If `nums[mid] < x`, the answer must lie in the right half, so we set `low = mid + 1`. 

---

## Code
```cpp
#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int>& nums, int x){

    int low=0,high=nums.size()-1, ans=nums.size();
    
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]>=x){
            ans=mid;
            high=mid-1;
        }
        else low=mid+1;
    }
    return ans;
}
int main(){
    vector<int> nums {3,5,8,15,19};
    int x=7;

    cout<<binarySearch(nums,x)<<endl;
}
```

---

## Output
```
Input: nums = {3, 5, 8, 15, 19}, x = 7
Output: 2
```

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Approach 1 (Optimal) | O(log N) | O(1) |

---

## Key Takeaway
Lower bound is a fundamental application of Binary Search used to find the first occurrence of an element greater than or equal to a target value.
