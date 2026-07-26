# Problem: Row with Maximim 1

## Problem Statement
Given a boolean 2D array, where each row is sorted. Find the row with the maximum number of 1s.

**Link:** https://www.geeksforgeeks.org/problems/row-with-max-1s0023/1
**Difficulty:** Medium  
**Topic:** Binary Search, 2D Arrays

---

## Approach
### Approach 1 (Brute Force)
This approach iterates through every single row and counts the number of 1s using the `accumulate` function (or a simple loop). It keeps track of the maximum count found so far and the corresponding row index.

### Approach 2 (Optimal - Binary Search)
Since each row is sorted, all `0`s appear before all `1`s. We can use binary search (`lower_bound` logic) to find the first occurrence of `1` in each row. If the first `1` is at index `idx`, the number of `1`s in that row of size `m` is `m - idx`. We do this for each row and keep track of the maximum count and row index.

---

## Code
```cpp
// Approach 2: Optimal - Binary Search (solution2.cpp)
#include<iostream>
#include<vector>
using namespace std;

int findLowerBound(vector<int>& arr,int n,int x){
    int low=0,high=n-1,res=-1;
    while(low<=high){

        int mid=low+(high-low)/2;
        if(arr[mid]>=x){
            res=mid;
            high=mid-1;
        }
        else low=mid+1;
    }
    return res;
}

int withMax(vector<vector<int>>& arr, int n,int m){
    int count_max=0,ans=0,res=-1,ones_count;
    for(int i=0;i<n;i++){
        ans=findLowerBound(arr[i], m, 1);
        if(ans==-1) ones_count=0;
        else ones_count=m-ans;
        if((ones_count)>count_max){
            count_max=ones_count;
            res=i;
        }
    }
    return res;
}

int main(){
    vector<vector<int>> arr {{1,1,1},{0,0,1},{0,0,0}};
    int n=3,m=3;

    cout<<withMax(arr,n,m)<<endl;
}
```

---

## Output
```
Input: arr = {{1,1,1},{0,0,1},{0,0,0}}
Output: 0
```

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Approach 1 (Brute Force) | O(N * M) | O(1) |
| Approach 2 (Optimal) | O(N * log M) | O(1) |

---

## Key Takeaway
When you need to count occurrences in a sorted array (like 0s followed by 1s), Binary Search (`lower_bound`) reduces the time from `O(M)` to `O(log M)`.
