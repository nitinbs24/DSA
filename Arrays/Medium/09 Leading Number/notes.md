# Problem: Leaders in an Array (Leading Numbers)

## Problem Statement
Given an array `nums` of integers, find all the **leaders** in the array.

An element of the array is considered a **leader** (or superior element) if it is strictly greater than all the elements to its right. The rightmost element is always a leader because there are no elements to its right.

Return an array of all the leaders in the array. The leaders should appear in the same relative order as they appeared in the original array.

**Link:** [GeeksforGeeks - Array Leaders](https://www.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1) / [Coding Ninjas - Superior Elements](https://www.naukri.com/code360/problems/superior-elements_6783446)  
**Difficulty:** Medium (Striver A2Z Sheet) / Easy (GFG)  
**Topic:** Arrays

---

## Approach

### Approach 1: Brute Force (Nested Loops)
For every element in the array, check if every element to its right is strictly smaller:
- Use an outer loop with index `i` from `0` to `n-1`.
- Assume `nums[i]` is a leader (`isLeader = true`).
- Run an inner loop with index `j` from `i+1` to `n-1`:
  - If any `nums[j] >= nums[i]`, then `nums[i]` cannot be a leader. Set `isLeader = false` and break early.
- If `isLeader` remains `true` after checking all elements to the right, append `nums[i]` to `ans`.
- **Drawback:** In the worst case (e.g., an array sorted in ascending order), the inner loop checks all elements to the right for each element, leading to $O(N^2)$ time complexity.

### Approach 2: Optimal (Right-to-Left Traversal with Running Maximum)
An element is a leader if and only if it is strictly greater than the maximum of all elements appearing to its right. Instead of repeatedly searching to the right for each element, traverse the array from right to left while keeping track of the maximum element seen so far:
1. The rightmost element `nums[n-1]` has no elements to its right, so it is unconditionally a leader. Initialize `max = nums[n-1]` and add it to `ans`.
2. Iterate backwards from index `n-2` down to `0`:
   - If `nums[i] > max`: it is greater than all elements to its right! Add `nums[i]` to `ans` and update `max = nums[i]`.
3. Because elements were collected from right to left, reverse `ans` to restore their original left-to-right order.
- **Advantage:** Each element is visited only once, reducing the time complexity to $O(N)$ with $O(1)$ auxiliary space.

---

## Code

### Solution 1: Brute Force (Nested Loops)
```cpp
#include<iostream>
#include<vector>
using namespace std;

vector<int> leaderNumber(vector<int>& nums){
    vector<int> ans;
    int i=0;
    for(i=0;i<nums.size();i++){
        bool isLeader=true;
        for(int j=i+1;j<nums.size();j++){
            if(nums[j]>=nums[i]){
                isLeader=false;
                break;
            }
        }
        if(isLeader){
            ans.push_back(nums[i]);
        }
    }
    return ans;
}

int main(){
    vector<int> nums = {10, 22, 12, 3, 0, 6};

    vector<int> ans=leaderNumber(nums);
    cout<<"{ ";
    for(auto num:ans){
        cout<<num<<" ";
    }
    cout<<"}\n";
}
```

### Solution 2: Optimal (Right-to-Left Traversal)
```cpp
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
    public:
    vector<int> leaderNumbers(vector<int>& nums){
        vector<int> ans;

        if(nums.empty()) return ans;

        int max=nums[nums.size()-1];
        ans.push_back(max);

        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]>max){
                ans.push_back(nums[i]);
                max=nums[i];
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

int main(){
    Solution sol;

    vector<int> nums = {10, 22, 12, 3, 0, 6};

    vector<int> ans = sol.leaderNumbers(nums);

    cout<<"{ ";
    for(auto num:ans){
        cout<<num<<" ";
    }
    cout<<"}\n";
}
```

---

## Output

**Sample Input 1:**
```
nums = [10, 22, 12, 3, 0, 6]
```

**Sample Output 1:**
```
{ 22 12 6 }
```
*(Explanation: 
- 22 is greater than [12, 3, 0, 6] -> Leader
- 12 is greater than [3, 0, 6] -> Leader
- 6 is the rightmost element -> Leader
- 10, 3, and 0 have larger elements to their right, so they are not leaders.)*

**Sample Input 2:**
```
nums = [4, 7, 1, 0]
```

**Sample Output 2:**
```
{ 7 1 0 }
```
*(Explanation: 7 > [1, 0], 1 > [0], and 0 is the last element.)*

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Approach 1 (Brute Force) | O(N²) | O(1) |
| Approach 2 (Optimal) | O(N) | O(1) |

*(Note: Space complexity is O(1) auxiliary space, excluding the space used for the returned output array.)*

---

## Key Takeaway
Whenever an operation requires comparing each element against all elements to its right, traverse from right to left. Maintaining a running maximum from the right eliminates redundant nested comparisons and reduces an $O(N^2)$ algorithm to $O(N)$.
