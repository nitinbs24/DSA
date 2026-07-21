# Problem: Highest Occurring Element in an Array

## Problem Statement
Given an array, find the element with the highest frequency (occurrence) and the element with the lowest frequency.

**Link:** N/A  
**Difficulty:** Easy  
**Topic:** Basic Hashing

---

## Approach

### Approach 1: Using Two Loops (Brute Force)
- Initialize `maxFreq = 0` and `minFreq = n` (array size), along with `maxEle` and `minEle` to store the respective elements.
- Create a `visited` array to keep track of elements that have already been counted.
- Iterate over the array. If the element is not visited, start counting its frequency using a nested loop. Mark all identical elements as visited.
- After counting, compare the count with `maxFreq` and `minFreq` to update them and their corresponding elements `maxEle` and `minEle`.

### Approach 2: Using Hashing (Optimal)
- Traverse the array and store the frequency of each element in an `unordered_map`.
- Initialize `maxFreq = 0`, `minFreq = n`, `maxEle = 0`, and `minEle = 0`.
- Iterate through the map: for each key-value pair, check if its frequency (value) is greater than `maxFreq` or less than `minFreq`, and update the variables accordingly.
- Finally, print `maxEle` and `minEle`.

---

## Code
### Optimal Approach
```cpp
#include <bits/stdc++.h>
using namespace std;

class FrequencyCounter {
public:
    void Frequency(int arr[], int n) {
        unordered_map<int, int> map;

        for (int i = 0; i < n; i++)
            map[arr[i]]++;

        int maxFreq = 0, minFreq = n;
        int maxEle = 0, minEle = 0;

        for (auto it : map) {
            int element = it.first;
            int count = it.second;

            if (count > maxFreq) {
                maxFreq = count;
                maxEle = element;
            }

            if (count < minFreq) {
                minFreq = count;
                minEle = element;
            }
        }

        cout << "The highest frequency element is: " << maxEle << "\n";
        cout << "The lowest frequency element is: " << minEle << "\n";
    }
};

int main() {
    FrequencyCounter fc;
    int arr[] = {10, 5, 10, 15, 10, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    fc.Frequency(arr, n);
    return 0;
}
```

---

## Output
```
The highest frequency element is: 10
The lowest frequency element is: 15
```
*(Note: If there is a tie, this implementation will store the first/last encountered max/min element based on unordered_map's iteration order)*

---

## Complexity
| | Time | Space |
|---|---|---|
| Brute Force | O(N^2) | O(N) |
| Optimal | O(N) | O(N) |

---

## Key Takeaway
By precomputing frequencies with a hash map, determining max/min counts becomes a simple linear pass over the unique elements, providing a vast performance boost over nested loops.
