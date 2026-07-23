# Problem: Second Smallest and Largest Element in an Array

## Problem Statement
Given an array of `N` integers, find the second smallest and second largest elements in the array. If they do not exist, return `-1`.

**Link:** [GeeksForGeeks - Second Largest](https://practice.geeksforgeeks.org/problems/second-largest3735/1)  
**Difficulty:** Easy  
**Topic:** Arrays

---

## Approach

### Approach 1: Two Passes (Better)
In the first pass, we can find the absolute smallest and largest elements. In the second pass, we iterate again to find the elements that are smallest (but strictly greater than the absolute smallest) and largest (but strictly smaller than the absolute largest).

### Approach 2: One Pass (Optimal)
Instead of two passes, we can maintain the `small` and `second_small` as well as `large` and `second_large` variables simultaneously in a single pass. 
- For largest: if the current element is greater than `large`, `second_large` becomes `large` and `large` becomes the current element. If it's between `second_large` and `large`, we just update `second_large`.
- We apply the exact same logic inversely for the smallest element.

---

## Code

### Solution 1: Two Passes Approach
```cpp
#include<bits/stdc++.h>
using namespace std;

void getElements(int arr[], int n)
{
    if (n == 0 || n == 1)
        cout << -1 << " " << -1 << endl;

    int small = INT_MAX, second_small = INT_MAX;
    int large = INT_MIN, second_large = INT_MIN;
    int i;

    // First pass
    for (i = 0; i < n; i++) {
        small = min(small, arr[i]);
        large = max(large, arr[i]);
    }

    // Second pass
    for (i = 0; i < n; i++) {
        if (arr[i] < second_small && arr[i] != small)
            second_small = arr[i];
        
        if (arr[i] > second_large && arr[i] != large)
            second_large = arr[i];
    }

    cout << "Second smallest is " << second_small << endl;
    cout << "Second largest is " << second_large << endl;
}

int main()
{
    int arr[] = {1, 2, 4, 6, 7, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    getElements(arr, n);
    return 0;
}
```

### Solution 2: One Pass Approach (Optimal)
```cpp
#include<bits/stdc++.h>
using namespace std;

int secondSmallest(int arr[], int n) {
    if (n < 2) return -1;
    int small = INT_MAX, second_small = INT_MAX;

    for (int i = 0; i < n; i++) {
        if (arr[i] < small) {
            second_small = small;
            small = arr[i];
        } else if (arr[i] < second_small && arr[i] != small) {
            second_small = arr[i];
        }
    }
    return second_small;
}

int secondLargest(int arr[], int n) {
    if (n < 2) return -1;
    int large = INT_MIN, second_large = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (arr[i] > large) {
            second_large = large;
            large = arr[i];
        } else if (arr[i] > second_large && arr[i] != large) {
            second_large = arr[i];
        }
    }
    return second_large;
}

int main() {
    int arr[] = {1, 2, 4, 7, 7, 5};  
    int n = sizeof(arr) / sizeof(arr[0]);
    int sS = secondSmallest(arr, n);
    int sL = secondLargest(arr, n);
    cout << "Second smallest is " << sS << endl;
    cout << "Second largest is " << sL << endl;
    return 0;
}
```

---

## Output

**Sample Input:**
```
1 2 4 7 7 5
```

**Sample Output:**
```
Second smallest is 2
Second largest is 5
```

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Two Passes | O(2N) | O(1) |
| One Pass | O(N) | O(1) |

---

## Key Takeaway
We can collapse multiple independent sequential tasks (like finding largest, then second largest) into a single iteration by updating both states simultaneously. This improves time from `O(2N)` to `O(N)`.
