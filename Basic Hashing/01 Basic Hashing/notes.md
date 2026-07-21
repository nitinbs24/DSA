# Problem: Basic Hashing

## Problem Statement
Given an array of integers (or characters) and several queries, find the frequency of each queried element in the given array/string.

**Link:** N/A  
**Difficulty:** Easy  
**Topic:** Basic Hashing

---

## Approach

### Approach 1: Using Arrays (Precomputation for Numbers/Characters)
- Create a hash array of fixed size based on the maximum possible value of the elements (e.g., `hash[13]` for numbers up to 12, or `hash[256]` for characters).
- Iterate through the given array or string and increment the count at the index corresponding to the element's value: `hash[arr[i]]++`.
- For each query, fetch the frequency directly in O(1) time by accessing `hash[query_element]`.
- Note: This approach has limitations on array size. We cannot allocate huge arrays (like size $10^9$) inside functions or even globally.

### Approach 2: Using STL Map / Unordered Map (Optimal)
- Use a `std::map<int, int>` or `std::unordered_map<int, int>` to store the frequency of elements.
- Iterate through the given array and increment the count for each element: `mp[arr[i]]++`.
- For each query, fetch the frequency in O(log N) for `std::map` or O(1) on average for `std::unordered_map`.
- This approach handles large values and uses space proportional to the number of unique elements, not the maximum possible element value.

---

## Code
### Optimal Approach (using std::map)
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // precompute:
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        mp[arr[i]]++;
    }

    int q;
    cin >> q;
    while (q--) {
        int number;
        cin >> number;
        // fetch:
        cout << mp[number] << endl;
    }
    return 0;
}
```

---

## Output
```
Input:
5
1 2 1 3 2
3
1
2
4
Output:
2
2
0
```

---

## Complexity
| | Time | Space |
|---|---|---|
| Array Hash | O(N) precompute + O(Q) | O(Max Element Value) |
| Map (Optimal)| O(N log N) precompute + O(Q log N) | O(Number of Unique Elements) |

---

## Key Takeaway
Hashing is an effective technique for precomputing frequencies to answer multiple queries efficiently. Use an array for small bounded elements and `map`/`unordered_map` when elements are large or unstructured.
