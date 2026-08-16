# Problem: Linear Search

## Problem Statement
Given an array of integers `arr` of size `n` and an integer `num`, write a function to search for `num` in `arr`. If `num` is present in the array, return its 0-based index; otherwise, return `-1`.

**Link:** [GeeksforGeeks - Linear Search](https://www.geeksforgeeks.org/linear-search/)  
**Difficulty:** Easy  
**Topic:** Arrays, Searching

---

## Approach

### Approach 1: Linear Search
Traverse the array element by element from index `0` to `n-1`. At each position `i`, compare the element `arr[i]` with the target element `num`. If a match is found, return the current index `i`. If the loop finishes without finding the element, return `-1`.

---

## Code
```cpp
#include<stdio.h>

int search(int arr[], int n, int num)
{
    int i;

    for(i = 0; i < n; i++)
    {
        if(arr[i] == num)
            return i;
    }

    return -1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int num = 4;
    int n = sizeof(arr) / sizeof(arr[0]);
    int val = search(arr, n, num);

    printf("%d", val);

    return 0;
}
```

---

## Output
```
Input: arr = [1, 2, 3, 4, 5], num = 4
Output: 3
```

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Approach 1 (Linear Search) | O(N) | O(1) |

---

## Key Takeaway
Linear search is the simplest searching algorithm that inspects elements sequentially; it requires O(N) time in the worst case and works on both sorted and unsorted arrays.
