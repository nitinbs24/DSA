# Problem: Majority Element

## Problem Statement
Given an array `nums` of size `n`, return the majority element. The majority element is the element that appears more than `⌊n / 2⌋` times. You may assume that the majority element always exists in the array.

**Link:** [LeetCode 169 - Majority Element](https://leetcode.com/problems/majority-element/)  
**Difficulty:** Medium  
**Topic:** Arrays, Hash Table, Counting

---

## Approach

### Approach 1: Hash Map (Better)
Iterate through the array and maintain a frequency count of each element using an `unordered_map`. Then iterate over the map to find the element whose frequency is strictly greater than `n / 2`. 

### Approach 2: Moore's Voting Algorithm (Optimal)
We can find the majority element in a single pass with $O(1)$ space. 
- Maintain a `cnt` and a candidate element `el`.
- If `cnt == 0`, we pick the current element as the new candidate `el` and set `cnt = 1`.
- If the current element is the same as the candidate `el`, we increment `cnt`.
- Otherwise, we decrement `cnt`.
Since the majority element occurs more than `N/2` times, its count will mathematically always surpass the combined counts of all other elements by the end of the iteration. (Note: If the problem states the majority element might not exist, a second pass is needed to verify if the final candidate truly occurs > N/2 times).

---

## Code

### Solution 1: Hash Map
```cpp
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int majorityElement(vector<int>& nums){
    unordered_map<int, int> mp;
    for(int num:nums) mp[num]++;

    for(auto& pair:mp){
        if(pair.second>(nums.size()/2)) return pair.first;
    }
    return -1;
}
int main(){
    vector<int> nums {2,1,1,2,2};
    cout<<majorityElement(nums)<<endl;
}
```

### Solution 2: Moore's Voting Algorithm (Optimal)
```cpp
#include<iostream>
#include<vector>
using namespace std;

int majorityElement(vector<int>& nums) {
    int n = nums.size(),cnt = 0,el; 

    for (int i = 0; i < n; i++) {
        if (cnt == 0) {
            cnt = 1;
            el = nums[i];
        } else if (el == nums[i]) {
            cnt++;
        } else {
            cnt--;
        }
    }
    
    // Optional verification pass (Required if majority element is not guaranteed)
    int cnt1 = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] == el) {
            cnt1++;
        }
    }
    if (cnt1 > (n / 2)) {
        return el;
    }
    return -1;
}
int main(){
    vector<int> nums {2,1,1,2,2};
    cout<<majorityElement(nums)<<endl;
}
```

---

## Output

**Sample Input:**
```
[2, 1, 1, 2, 2]
```

**Sample Output:**
```
2
```

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Hash Map | O(N) | O(N) |
| Moore's Voting Algo | O(N) | O(1) |

---

## Key Takeaway
Moore's Voting Algorithm is a beautiful technique to find a majority element by "canceling out" differing elements. It heavily relies on the mathematical guarantee that the majority element frequency > N/2.
