# Problem: Koko eating Bananas

## Problem Statement
Koko loves to eat bananas. There are `n` piles of bananas, the `i`th pile has `piles[i]` bananas. The guards have gone and will come back in `h` hours. Koko can decide her bananas-per-hour eating speed of `k`. Each hour, she chooses some pile of bananas and eats `k` bananas from that pile. If the pile has less than `k` bananas, she eats all of them instead and will not eat any more bananas during this hour. Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
Return the minimum integer `k` such that she can eat all the bananas within `h` hours.

**Link:** https://leetcode.com/problems/koko-eating-bananas/  
**Difficulty:** Medium  
**Topic:** Binary Search on Answers, Arrays

---

## Approach
### Approach 1 (Brute Force)
We can check all possible eating speeds starting from `k = 1` up to the maximum pile size (since eating faster than the max pile size doesn't save any hours). For each speed `i`, we calculate the total hours required. The first speed `i` that results in a total time less than or equal to `h` is our minimum eating speed.

### Approach 2 (Optimal - Binary Search on Answer)
Since the total hours required monotonically decreases as the eating speed increases, we can apply Binary Search on the answer space `[1, max(piles)]`. 
- Calculate `mid` as the candidate speed.
- Evaluate the total hours taken at speed `mid`.
- If `totalHours <= h`, it means this speed is sufficient. We save this `mid` as a potential answer and try to find an even smaller speed by searching the left half (`high = mid - 1`).
- If `totalHours > h`, the speed is too slow, so we must search the right half (`low = mid + 1`).

---

## Code
```cpp
// Approach 2: Optimal - Binary Search (solution2.cpp)
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long countHours(const vector<int>& pair, int hours){
    long long count=0;
    for(auto p:pair){
        count += (p - 1) / hours + 1; // ceiling division
    }
    return count;
}

int minEatingSpeed(const vector<int>& pair,int hours){
    int low=1, high=*max_element(pair.begin(),pair.end());
    int ans;
    while (low<=high){

        int mid=low+(high-low)/2;
        long long totalHours=countHours(pair, mid);
        if(totalHours<=hours){
            ans=mid;
            high=mid-1;
        }
        else low=mid+1;
    }
    return ans;
}

int main(){
    vector<int> pair {7, 15, 6, 3};
    int hours=8;

    cout<<minEatingSpeed(pair,hours)<<endl;
}
```

---

## Output
```
Input: piles = [7, 15, 6, 3], h = 8
Output: 5
```

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Approach 1 (Brute Force) | O(max(piles) * N) | O(1) |
| Approach 2 (Optimal) | O(N * log(max(piles))) | O(1) |

---

## Key Takeaway
When you need to find a minimum or maximum threshold that satisfies a monotonic condition, use Binary Search on the range of possible answers.
