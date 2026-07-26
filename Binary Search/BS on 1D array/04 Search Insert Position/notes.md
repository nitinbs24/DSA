# Problem: Search Insert Position

## Problem Statement
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

**Link:** https://leetcode.com/problems/search-insert-position/  
**Difficulty:** Easy  
**Topic:** Binary Search, Arrays

---

## Approach
### Approach 1 (Optimal - Binary Search)
The logic to find the insert position is exactly the same as finding the Lower Bound. We use binary search to find the first index where the element is greater than or equal to the target `x`. After finding this lower bound index (`ans`), if the element at `ans` is equal to `x`, it means the element is found, and we return `ans`. If it is not found, we return the calculated index as the insertion point. Note: the provided code actually performs the `insert` operation on the vector if the element is not found.

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
    if (ans<nums.size() && nums[ans]==x) return ans;
    else{
        nums.insert(nums.begin()+ans,x);
        return ans;
    }
}
int main(){
    vector<int> nums {3,5,8,15,19};
    int x=8;

    cout<<binarySearch(nums,x)<<endl;

    for(auto num:nums) cout<<num<<" ";
}
```

---

## Output
```
Input: nums = {3, 5, 8, 15, 19}, x = 8
Output: 2 (Index of 8 is 2, the array becomes: 3 5 8 8 15 19)
```

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Approach 1 (Optimal) | O(log N) to find position, O(N) for insertion | O(1) |

---

## Key Takeaway
Finding the insertion position of an element in a sorted array is identical to finding the lower bound of that element.
