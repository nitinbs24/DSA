# Problem: Counting Frequencies of Array Elements

## Problem Statement
Given an array, we have found the number of occurrences of each element in the array.

**Link:** N/A  
**Difficulty:** Easy  
**Topic:** Basic Hashing

---

## Approach

### Approach 1: Using Two Loops (Brute Force)
- Iterate through the array using a loop (say `i`).
- For each element `arr[i]`, use a nested loop `j` from `i+1` to `n-1` to count its occurrences.
- To avoid counting the same element multiple times, maintain a boolean `visited` array of size `n` initialized to `false`.
- If an element is already marked `visited`, skip it. Otherwise, count all its occurrences, mark them as `visited`, and print the result.

### Approach 2: Using Hashing (Optimal)
- Use a `std::unordered_map<int, int>` to store the elements as keys and their frequencies as values.
- Traverse the array once, and for each element, increment its count in the map.
- After the map is fully populated, iterate through the map to print the elements and their respective frequencies.

---

## Code
### Optimal Approach (using unordered_map)
```cpp
#include <bits/stdc++.h>
using namespace std;

void Frequency(int arr[], int n) {
    unordered_map<int, int> map;

    for (int i = 0; i < n; i++) {
        map[arr[i]]++;
    }

    for (auto x : map) {
        cout << x.first << " " << x.second << endl;
    }
}

int main() {
    int arr[] = {10, 5, 10, 15, 10, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    Frequency(arr, n);
    return 0;
}
```

---

## Output
```
10 3
5 2
15 1
```
*(Note: Output order may vary due to the use of unordered_map)*

---

## Complexity
| | Time | Space |
|---|---|---|
| Brute Force | O(N^2) | O(N) for visited array |
| Optimal | O(N) | O(N) |

---

## Key Takeaway
Using a Hash Map minimizes the time complexity from $O(N^2)$ to $O(N)$ when counting frequencies of array elements.
