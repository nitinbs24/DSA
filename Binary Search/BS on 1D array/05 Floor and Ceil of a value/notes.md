# Problem: Floor and Ceil of a value

## Problem Statement
Given a sorted array and a value `x`, find the floor and ceiling of `x` in the array. 
- **Floor**: The largest element in the array smaller than or equal to `x`.
- **Ceiling**: The smallest element in the array greater than or equal to `x` (this is the same as the Lower Bound value).

**Link:** https://www.geeksforgeeks.org/problems/ceil-the-floor2802/1  
**Difficulty:** Easy  
**Topic:** Binary Search, Arrays

---

## Approach
### Approach 1 (Optimal - Binary Search)
We can write two separate binary search functions for Floor and Ceil.
1. **Find Floor**: We aim to find the largest number `<= x`. If `arr[mid] <= x`, this element is a potential candidate for the floor. We record it and move right (`low = mid + 1`) to find an even larger valid number. If `arr[mid] > x`, it cannot be the floor, so we move left (`high = mid - 1`).
2. **Find Ceil**: We aim to find the smallest number `>= x` (same as Lower Bound logic but returning the element instead of the index). If `arr[mid] >= x`, it is a potential candidate. We record it and move left (`high = mid - 1`) to find an even smaller valid number. If `arr[mid] < x`, we move right (`low = mid + 1`).

---

## Code
```cpp
#include <bits/stdc++.h>
using namespace std;

class FloorCeilFinder {
public:
    int findFloor(int arr[], int n, int x) {
        int low = 0, high = n - 1;
        int ans = -1;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] <= x) {
                ans = arr[mid];
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }


    int findCeil(int arr[], int n, int x) {
        int low = 0, high = n - 1;
        int ans = -1;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] >= x) {
                ans = arr[mid];
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
        int f = findFloor(arr, n, x);
        int c = findCeil(arr, n, x);
        return make_pair(f, c);
    }
};

int main() {
    int arr[] = {3, 4, 4, 7, 8, 10};
    int n = 6, x = 5;
    FloorCeilFinder finder;
    pair<int, int> ans = finder.getFloorAndCeil(arr, n, x);
    cout << "The floor and ceil are: " << ans.first << " " << ans.second << endl;
    return 0;
}
```

---

## Output
```
Input: arr = {3, 4, 4, 7, 8, 10}, x = 5
Output: The floor and ceil are: 4 7
```

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Approach 1 (Optimal) | O(log N) for each function, Total: O(log N) | O(1) |

---

## Key Takeaway
Floor and Ceil are direct applications of Binary Search. Floor is the largest element `<= x` and Ceil is the smallest element `>= x`. Both can be found in `O(log N)` time.
