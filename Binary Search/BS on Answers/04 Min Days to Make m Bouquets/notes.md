# Problem: Min Days to Make m Bouquets

## Problem Statement
You are given an integer array `bloomDay`, an integer `m` and an integer `k`. You want to make `m` bouquets. To make a bouquet, you need to use `k` **adjacent flowers** from the garden. The garden consists of `n` flowers, the `i`th flower will bloom in the `bloomDay[i]` and then can be used in exactly one bouquet. Return the minimum number of days you need to wait to be able to make `m` bouquets from the garden. If it is impossible to make `m` bouquets return `-1`.

**Link:** https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/  
**Difficulty:** Medium  
**Topic:** Binary Search on Answers, Arrays

---

## Approach
### Approach 1 (Optimal - Binary Search on Answer)
The minimum possible days is the minimum value in the array, and the maximum is the maximum value. If the total flowers needed (`m * k`) is greater than the array size, it's impossible (return `-1`).
We apply binary search on the range `[min(bloomDay), max(bloomDay)]`. For a candidate day `mid`, we iterate through the array and count how many adjacent flowers have bloomed (i.e., `bloomDay[i] <= mid`). If we get `k` adjacent flowers, we form a bouquet and reset the counter.
- If we can form `>= m` bouquets, this `mid` is a potential answer. We record it and search left (`high = mid - 1`) for a smaller day.
- If we cannot form `m` bouquets, we must wait longer, so we search right (`low = mid + 1`).

---

## Code
```cpp
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int isPossible(vector<int>& arr,int days,int m,int k){
    int count=0,bouquets=0;

    for(auto a:arr){
        if(a<=days){
            count++;
            if(count==k){
                bouquets++;
                count=0;
            }
        } else count=0;
    }
    return bouquets>=m;
}

int minDays(vector<int>& arr,int m,int k){
    long long flowers=1LL*m*k;
    if(flowers>arr.size()) return -1;


    int mini=*min_element(arr.begin(),arr.end()), maxi=*max_element(arr.begin(),arr.end());
    int ans = -1;

    int low = mini, high = maxi;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(isPossible(arr, mid, m, k)){
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main(){
    vector<int> arr {1,10,3,10,2};
    int m=3,k=1;

    cout<<minDays(arr,m,k)<<endl;
}
```

---

## Output
```
Input: bloomDay = [1,10,3,10,2], m = 3, k = 1
Output: 3
```

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Approach 1 (Optimal) | O(N * log(max(arr) - min(arr))) | O(1) |

---

## Key Takeaway
We can abstract the simulation logic into an `isPossible` function and use Binary Search over the time domain to find the earliest valid occurrence.
