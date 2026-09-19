# Problem: Longest Consecutive Sequence

## Problem Statement
Given an unsorted array of integers `nums`, return the length of the **longest consecutive elements sequence**.

You must write an algorithm that runs in **$O(N)$** time.

A consecutive sequence is a sequence of numbers in which each number is strictly greater than the previous number by exactly `1` (e.g., `[1, 2, 3, 4]`). Elements do not need to be contiguous in the original array.

**Link:** [LeetCode 128 - Longest Consecutive Sequence](https://leetcode.com/problems/longest-consecutive-sequence/)  
**Difficulty:** Medium  
**Topic:** Arrays, Hash Table, Sorting

---

## Approach

### Approach 1: Brute Force (Linear Search for Successors)
For each element in the array, treat it as the starting element of a consecutive sequence and search linearly for the consecutive numbers (`x + 1`, `x + 2`, ...):
1. For each `nums[i]`:
   - Set `x = nums[i]` and current streak length `cnt = 1`.
   - While `x + 1` exists in the array (using a helper function that scans the entire array linearly of size $N$):
     - Increment `x` by `1` and `cnt` by `1`.
   - Update `longest = max(longest, cnt)`.
2. **Drawback:** Linear search takes $O(N)$ for each successive number lookup, causing the algorithm to take $O(N^2)$ to $O(N^3)$ time in the worst case, leading to Time Limit Exceeded (TLE).

### Approach 2: Better (Sorting)
Sort the array so that consecutive numbers are positioned next to each other:
1. If the array is empty, return `0`.
2. Sort the array in ascending order ($O(N \log N)$).
3. Maintain three variables:
   - `longest = 1`: tracks the maximum consecutive streak found.
   - `prevSmallest = INT_MIN`: tracks the previous distinct element in the sequence.
   - `cnt = 0`: tracks the current streak length.
4. Iterate through the sorted array:
   - If `nums[i] - 1 == prevSmallest`: current number extends the streak. Increment `cnt++` and update `prevSmallest = nums[i]`.
   - Else if `nums[i] != prevSmallest`: current number is neither consecutive nor a duplicate. Reset streak with `cnt = 1` and update `prevSmallest = nums[i]`.
   - If `nums[i] == prevSmallest`: it is a duplicate; simply skip it without resetting `cnt`.
   - Update `longest = max(longest, cnt)` after each element.
5. **Drawback:** Sorting takes $O(N \log N)$ time, which does not strictly meet the $O(N)$ linear time requirement of the problem.

### Approach 3: Optimal (Hash Set / Sequence Starters)
To achieve true $O(N)$ time complexity, use an `unordered_set` for $O(1)$ average-time lookups and only start counting streaks from the **beginning** of each sequence:
1. Insert all elements into an `unordered_set<int> st` ($O(N)$ time, automatically handles duplicates).
2. Iterate through each unique number `it` in the set:
   - Check if `it` is the start of a sequence by verifying if `it - 1` exists in `st`.
   - If `it - 1` **is found**: `it` cannot be the start of a sequence, so **skip it**. (It will be counted when we process the smallest number of this sequence).
   - If `it - 1` **is NOT found**: `it` is indeed the start of a new consecutive sequence!
     - Set `cnt = 1` and `x = it`.
     - While `x + 1` exists in `st`:
       - Increment `x++` and `cnt++`.
     - Update `longest = max(longest, cnt)`.
3. **Why is this $O(N)$?** Each element is only visited in the inner `while` loop if it is part of a streak explored from its true minimum. Thus, every element is looked up in the set at most twice across the entire algorithm.

---

## Code

### Solution 1: Brute Force (Linear Search)
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Helper function to perform linear search
    bool linearSearch(vector<int>& a, int num) {
        int n = a.size(); 
        // Traverse through the array 
        for (int i = 0; i < n; i++) {
            if (a[i] == num)
                return true;
        }
        return false;
    }

public:
    // Function to find the longest consecutive sequence
    int longestConsecutive(vector<int>& nums) {
        // If the array is empty
        if (nums.size() == 0) {
            return 0;
        }
        int n = nums.size();
        // Initialize the longest sequence length
        int longest = 1; 

        // Iterate through each element in the array
        for (int i = 0; i < n; i++) {
            // Current element
            int x = nums[i]; 
            // Count of the current sequence
            int cnt = 1; 

            // Search for consecutive numbers
            while (linearSearch(nums, x + 1) == true) {
                // Move to the next number in the sequence
                x += 1; 
                // Increment the count of the sequence
                cnt += 1; 
            }

            // Update the longest sequence length found so far
            longest = max(longest, cnt);
        }
        return longest;
    }
};

int main() {
    vector<int> a = {100, 4, 200, 1, 3, 2};

    // Create an instance of the Solution class
    Solution solution;

    // Function call for longest consecutive sequence
    int ans = solution.longestConsecutive(a);
    cout << "The longest consecutive sequence is " << ans << "\n"; 
    return 0;
}
```

### Solution 2: Better (Sorting)
```cpp
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

class Solution{
    public:
    int longestConsecutive(vector<int> nums){
        int n=nums.size();
        if(n==0) return 0;

        int longest=1,prevSmallest=INT_MIN,cnt=0;

        sort(nums.begin(),nums.end());

        for(int i=0;i<n;i++){
            if(nums[i]-1 == prevSmallest){
                cnt++;
                prevSmallest=nums[i];
            }
            else if(nums[i]!=prevSmallest){
                cnt=1;
                prevSmallest=nums[i];
            }
            longest=max(longest,cnt);
        }
        return longest;
    }
};

int main(){
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    Solution sol;
    cout<<sol.longestConsecutive(nums)<<endl;
}
```

### Solution 3: Optimal (Hash Set)
```cpp
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution{
    public:
    int longestConsecutive(vector<int> nums){
        
        int n=nums.size();
        if(n==0) return 0;

        unordered_set<int> st;
        int longest=1;
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }

        for(auto it:st){
            if(st.find(it-1) == st.end()){
                int cnt=1;
                int x=it;

                while(st.find(x+1) != st.end()){
                    cnt++;
                    x++;
                }
                longest=max(longest,cnt);
            }
        }
        return longest;
    }
};

int main(){
    vector<int> nums {100, 4, 200, 1, 3, 2};
    Solution sol;

    cout<<sol.longestConsecutive(nums)<<endl;
}
```

---

## Output

**Sample Input 1:**
```
nums = [100, 4, 200, 1, 3, 2]
```

**Sample Output 1:**
```
4
```
*(Explanation: The longest consecutive elements sequence is [1, 2, 3, 4], which has length 4.)*

**Sample Input 2:**
```
nums = [0, 3, 7, 2, 5, 8, 4, 6, 0, 1]
```

**Sample Output 2:**
```
9
```
*(Explanation: The longest consecutive elements sequence is [0, 1, 2, 3, 4, 5, 6, 7, 8], which has length 9.)*

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Approach 1 (Brute Force) | O(N²) ~ O(N³) | O(1) |
| Approach 2 (Better - Sorting) | O(N log N) | O(1) |
| Approach 3 (Optimal - Hash Set) | O(N) | O(N) |

*(Note: Approach 3 has O(N) average time complexity because hash set operations take O(1) on average, and each number is processed inside the inner while loop at most once. In worst-case hash collision scenarios, unordered_set can degrade to O(N²), but in practice it runs in linear time.)*

---

## Key Takeaway
To achieve $O(N)$ time without sorting, store elements in an `unordered_set` and only expand sequences from true sequence starters—numbers for which `num - 1` does not exist in the set. This ensures no redundant sequence traversals and guarantees each element is visited at most twice.
