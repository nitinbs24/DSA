# Problem: Union of Two Sorted Arrays

## Problem Statement
Given two sorted arrays `arr1[]` of size `n` and `arr2[]` of size `m`, find the union of these two arrays. The union of two arrays contains all unique elements present in either of the arrays, sorted in ascending order.

**Link:** [GeeksforGeeks - Union of Two Sorted Arrays](https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1)  
**Difficulty:** Easy  
**Topic:** Arrays, Two Pointers, Data Structures (Map / Set)

---

## Approach

### Approach 1: Brute Force (Using Map)
We can use a `std::map<int, int>` to store elements along with their frequencies. Since a map maintains keys in sorted order and stores unique keys, we iterate through both arrays and insert every element into the map. Finally, we traverse the map and push the keys into a vector to get the union.

### Approach 2: Better (Using Set)
We can use an ordered set `std::set<int>`. Sets automatically store only unique elements in sorted order. We insert all elements of both `arr1` and `arr2` into the set, and then construct a vector from the set.

### Approach 3: Optimal (Two Pointers)
Since both input arrays are already sorted, we can take advantage of this property using two pointers (`i` for `arr1` and `j` for `arr2`):
1. Compare `arr1[i]` and `arr2[j]`.
2. Push the smaller element into the union vector (if it is not a duplicate of the last inserted element) and advance the corresponding pointer.
3. If elements are equal, push the element once (if not a duplicate) and advance both pointers.
4. After the main loop, append any remaining elements from `arr1` or `arr2` while avoiding duplicates.

---

## Code

### Approach 1 (Using Map)
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> FindUnion(int arr1[], int arr2[], int n, int m) {
        map<int, int> freq;
        vector<int> Union;
        for (int i = 0; i < n; i++)
            freq[arr1[i]]++;
        for (int i = 0; i < m; i++)
            freq[arr2[i]]++;
        for (auto &it : freq)
            Union.push_back(it.first);
        return Union;
    }
};

int main() {
    int n = 10;
    int m = 7;
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[] = {2, 3, 4, 4, 5, 11, 12};
    Solution obj;
    vector<int> Union = obj.FindUnion(arr1, arr2, n, m);
    cout << "Union of arr1 and arr2 is " << endl;
    for (auto &val : Union)
        cout << val << " ";
    return 0;
}
```

### Approach 2 (Using Set)
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findUnion(int arr1[], int arr2[], int n, int m) {
        set<int> st;

        for (int i = 0; i < n; i++) {
            st.insert(arr1[i]);
        }

        for (int i = 0; i < m; i++) {
            st.insert(arr2[i]);
        }

        vector<int> unionArr(st.begin(), st.end());
        return unionArr;
    }
};

int main() {
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[] = {2, 3, 4, 4, 5, 11, 12};
    int n = 10, m = 7;

    Solution obj;
    vector<int> result = obj.findUnion(arr1, arr2, n, m);

    cout << "Union of arr1 and arr2 is: ";
    for (int val : result) {
        cout << val << " ";
    }
    return 0;
}
```

### Approach 3 (Optimal - Two Pointers)
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findUnion(int arr1[], int arr2[], int n, int m) {
        vector<int> Union;

        int i = 0, j = 0;

        while (i < n && j < m) {
            if (arr1[i] < arr2[j]) {
                if (Union.empty() || Union.back() != arr1[i])
                    Union.push_back(arr1[i]);
                i++;
            }
            else if (arr2[j] < arr1[i]) {
                if (Union.empty() || Union.back() != arr2[j])
                    Union.push_back(arr2[j]);
                j++;
            }
            else {
                if (Union.empty() || Union.back() != arr1[i])
                    Union.push_back(arr1[i]);
                i++; j++;
            }
        }

        while (i < n) {
            if (Union.empty() || Union.back() != arr1[i])
                Union.push_back(arr1[i]);
            i++;
        }

        while (j < m) {
            if (Union.empty() || Union.back() != arr2[j])
                Union.push_back(arr2[j]);
            j++;
        }

        return Union;
    }
};

int main() {
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[] = {2, 3, 4, 4, 5, 11, 12};
    int n = 10, m = 7;

    Solution obj;
    vector<int> result = obj.findUnion(arr1, arr2, n, m);

    cout << "Union of arr1 and arr2 is: ";
    for (int val : result) cout << val << " ";
    return 0;
}
```

---

## Output
```
Union of arr1 and arr2 is: 1 2 3 4 5 6 7 8 9 10 11 12
```

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Approach 1 (Map) | O((N + M) log(N + M)) | O(N + M) |
| Approach 2 (Set) | O((N + M) log(N + M)) | O(N + M) |
| Approach 3 (Optimal - Two Pointers) | O(N + M) | O(1) *(excluding output array)* |

---

## Key Takeaway
When combining two sorted arrays, the Two-Pointer pattern enables linear O(N + M) merging in a single pass without needing extra log(N) overhead from balanced tree structures like `std::set` or `std::map`.
