# Problem: Remove Duplicates from Sorted Array

## Problem Statement
Given an integer array `nums` sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Return `k` (the number of unique elements).

**Link:** [LeetCode 26 - Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/)  
**Difficulty:** Easy  
**Topic:** Arrays, Two Pointers

---

## Approach

### Approach 1: Using HashSet (Brute Force)
Since the set data structure inherently stores only unique elements, we can iterate through the array and insert elements into a set. Then we replace the original elements of the array with the set contents. (Note: HashSet doesn't guarantee sorted order unless we use an ordered `std::set`, or because we are iterating sequentially and keeping a separate index).

### Approach 2: Two Pointers (Optimal)
Since the array is already sorted, all duplicates will be adjacent to each other. We can use two pointers `i` and `j`. 
- `i` keeps track of the index of the last unique element.
- `j` iterates through the array. 
- If `nums[i] != nums[j]`, it means we found a new unique element. We increment `i` and set `nums[i] = nums[j]`.
- Finally, the length of unique elements will be `i + 1`.

---

## Code

### Solution 1: HashSet (Brute Force)
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_set<int> seen;
        int index = 0;

        for (int num : nums) {
            if (seen.find(num) == seen.end()) {
                seen.insert(num);
                nums[index] = num;
                index++;
            }
        }
        return index;
    }
};

int main() {
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    Solution sol;
    int k = sol.removeDuplicates(nums);

    cout << "k = " << k << "\nArray after removing duplicates: ";
    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}
```

### Solution 2: Two Pointers (Optimal)
```cpp
#include<iostream>
#include<vector>
using namespace std;

int removeDuplicates(vector<int>& nums){
    int i=0;
    for(int j=1;j<nums.size();j++){
        if(nums[i]!=nums[j]){
            i++;
            nums[i]=nums[j];
        }
    }
    return i+1;
}

int main(){
    vector<int> nums {1,1,2,3,4,4};
    cout<<removeDuplicates(nums)<<endl;
}
```

---

## Output

**Sample Input:**
```
1 1 2 3 4 4
```

**Sample Output:**
```
5
```

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Brute Force (HashSet) | O(N) on avg | O(N) |
| Optimal (Two Pointers) | O(N) | O(1) |

---

## Key Takeaway
Whenever you need to process an array in-place and conditionally keep elements, a slow-fast Two Pointer approach is often the most optimal solution in terms of space complexity.
