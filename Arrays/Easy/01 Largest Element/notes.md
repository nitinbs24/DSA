# Problem: Largest Element in an Array

## Problem Statement
Given an array of size `N`, find the largest element in the array.

**Link:** [GeeksForGeeks - Largest Element in Array](https://practice.geeksforgeeks.org/problems/largest-element-in-array/1)  
**Difficulty:** Easy  
**Topic:** Arrays

---

## Approach

### Approach 1: Linear Search (Optimal)
We can assume the first element to be the largest. Then we iterate through the array, comparing each element with the current largest element. If we find an element greater than our assumed maximum, we update the maximum value. This takes a single pass.

---

## Code

### Solution 1: Linear Search
```cpp
#include<iostream>
#include<vector>
using namespace std;

int findLargest(vector<int>& nums){
    int max=nums[0];

    for(auto it:nums){
        if(it>max) max=it;
    }

    return max;
}

int main(){
    int n;
    cin>>n;
    vector<int> nums;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        nums.push_back(x);
    }

    cout<<findLargest(nums)<<endl;
}
```

---

## Output

**Sample Input:**
```
5
1 8 7 56 90
```

**Sample Output:**
```
90
```

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Linear Search | O(N) | O(1) |

---

## Key Takeaway
A simple linear scan is the most optimal way to find the largest (or smallest) element in an unsorted array, running in exactly `N` operations without extra space.
