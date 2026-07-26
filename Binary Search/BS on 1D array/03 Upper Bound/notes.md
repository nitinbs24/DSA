# Problem: Upper Bound

## Problem Statement
Given a sorted array of `N` integers and an integer `X`, find the upper bound of `X`. The upper bound is the index of the first element in the array which is strictly greater than `X`. If no such element exists, the upper bound is the size of the array.

**Link:** https://www.geeksforgeeks.org/problems/ceil-the-floor2802/1 (Similar concept)
**Difficulty:** Easy  
**Topic:** Binary Search, Arrays

---

## Approach
### Approach 1 (Optimal - Binary Search)
We use binary search to find the upper bound. We initialize `ans` to the size of the array. At each step, we calculate `mid`. If `nums[mid] > x`, this element is strictly greater than `x`, meaning it could be our answer. We record `ans = mid` and move to the left half (`high = mid - 1`) to find a potentially smaller valid index. If `nums[mid] <= x`, the target element or elements smaller than it are at `mid`, so our answer must be in the right half (`low = mid + 1`).

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
        if(nums[mid]>x){
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
Upper bound is just a slight variation of lower bound where the condition `nums[mid] >= x` changes to `nums[mid] > x` to find the strictly greater element.
