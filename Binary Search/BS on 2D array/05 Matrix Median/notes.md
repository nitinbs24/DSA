# Problem: Matrix Median

## Problem Statement
Given a row-wise sorted matrix of size `R x C` where `R * C` is always odd, find the median of the matrix.

**Link:** https://www.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1
**Difficulty:** Hard  
**Topic:** Binary Search on Answers, 2D Arrays

---

## Approach
### Approach 1 (Optimal - Binary Search on Answers)
The median of a matrix with `N` total elements is the smallest number that has at least `(N + 1) / 2` elements less than or equal to it. We can perform binary search on the answer space.
1. Our search space is `[min_element, max_element]` in the matrix.
2. We calculate `mid = (low + high) / 2` as a candidate median.
3. We count how many elements in the entire matrix are `<= mid`. Since each row is sorted, we can use `upper_bound` on each row to do this efficiently in `O(log C)` time per row.
4. If the total count is less than `(R * C + 1) / 2`, our candidate is too small, so we search the right half (`low = mid + 1`).
5. Otherwise, the candidate could be the median or the median is smaller, so we search the left half (`high = mid`).

---

## Code
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countLessEqual(vector<int>& row, int mid) {
        return upper_bound(row.begin(), row.end(), mid) - row.begin();
    }

    int findMedian(vector<vector<int>>& matrix) {

        int rows = matrix.size();
        int cols = matrix[0].size();

        int low = matrix[0][0];
        int high = matrix[0][cols - 1];

        for (int i = 1; i < rows; i++) {
            low = min(low, matrix[i][0]);
            high = max(high, matrix[i][cols - 1]);
        }

        while (low < high) {
            int mid = (low + high) / 2;
            int count = 0;
            for (int i = 0; i < rows; i++) {
                count += countLessEqual(matrix[i], mid);
            }

            if (count < (rows * cols + 1) / 2)
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }
};

int main() {
    Solution obj;
    vector<vector<int>> matrix = {
        {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9}
    };
    cout << "Median: " << obj.findMedian(matrix) << endl;
    return 0;
}
```

---

## Output
```
Input: matrix = {{1, 3, 5}, {2, 6, 9}, {3, 6, 9}}
Output: Median: 5
```

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Approach 1 (Optimal) | O(R * log(C) * log(Max - Min)) | O(1) |

---

## Key Takeaway
When you cannot easily find an element by index, but you can count how many elements are smaller than a given value, "Binary Search on Answers" allows you to find quantiles (like the median) efficiently without fully sorting the data.
