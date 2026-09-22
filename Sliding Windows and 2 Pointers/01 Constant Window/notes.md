# Problem: Maximum Points You Can Obtain from Cards

## Problem Statement
There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array `cardPoints`.

In one step, you can take one card from the beginning or from the end of the row. You have to take exactly `k` cards.

Your score is the sum of the points of the cards you have taken.

Given the integer array `cardPoints` and the integer `k`, return the **maximum score** you can obtain.

**Link:** [LeetCode 1423 - Maximum Points You Can Obtain from Cards](https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/)  
**Difficulty:** Medium  
**Topic:** Arrays, Sliding Window, Prefix Sum

---

## Approach

### Approach 1: Brute Force (Evaluate All Splits from Scratch)
Because you can only take cards from the two outer ends, taking $k$ cards means choosing:
- `leftCount` cards from the beginning ($0 \le \text{leftCount} \le k$).
- `rightCount = k - leftCount` cards from the end.

1. Loop through all possible `leftCount` values from `0` to `k`.
2. For each split, calculate the score by iterating through the first `leftCount` cards and the last `rightCount` cards.
3. Track the maximum score across all splits.
- **Drawback:** There are $k + 1$ possible splits, and each split takes $O(k)$ time to sum from scratch, leading to an overall time complexity of $O(k^2)$.

### Approach 2: Better (Precomputed Prefix & Suffix Sums)
To avoid recalculating the sum for every split, precompute cumulative sums for both ends:
1. Create two arrays:
   - `leftSum[i]`: sum of the first `i` cards from the left.
   - `rightSum[i]`: sum of the last `i` cards from the right.
2. Fill `leftSum` and `rightSum` in $O(k)$ time:
   - `leftSum[i] = leftSum[i - 1] + cardPoints[i - 1]`
   - `rightSum[i] = rightSum[i - 1] + cardPoints[n - i]`
3. Loop `leftCount` from `0` to `k`:
   - Obtain the score in $O(1)$: `currentScore = leftSum[leftCount] + rightSum[k - leftCount]`.
   - Update `maxScore = max(maxScore, currentScore)`.
- **Complexity:** Reduces time to $O(k)$, but requires $O(k)$ auxiliary space for the prefix/suffix arrays.

### Approach 3: Optimal (Constant Window / Sliding Shift in $O(1)$ Space)
Instead of storing all prefix/suffix sums, dynamically transition between splits using a sliding window technique:
1. **Initial Window:** Start by taking all $k$ cards from the left (`i = 0` to `k - 1`). Compute this sum as `currentScore` and set `maxScore = currentScore`.
2. Initialize `rightIndex = n - 1`.
3. **Sliding Shift:** In each step, drop one card from the left and pick one card from the right:
   - For `leftIndex = k - 1` down to `0`:
     - Subtract the discarded left card: `currentScore -= cardPoints[leftIndex]`.
     - Add the newly included right card: `currentScore += cardPoints[rightIndex]`.
     - Decrement `rightIndex--`.
     - Update `maxScore = max(maxScore, currentScore)`.
4. Return `maxScore`.
- **Advantage:** Explores all $k + 1$ combinations in a single pass of $O(k)$ time while using strictly $O(1)$ auxiliary space.

---

## Code

### Solution 1: Brute Force (Recomputing Splits)
```cpp
#include <climits>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution{
    public:
    int maxScore(vector<int>& cardPoints, int k){

        int n = cardPoints.size();
        if(k < 0 || k > n) return -1;
        if(k == 0) return 0;
        if(k == n) return accumulate(cardPoints.begin(), cardPoints.end(), 0);

        int maxScore = INT_MIN;

        for(int leftCount = 0; leftCount <= k; leftCount++){

            int rightCount = k - leftCount;

            int score = 0;

            for(int i = 0; i < leftCount; i++) score += cardPoints[i];

            for(int i = 0; i < rightCount; i++) score += cardPoints[n - i - 1];

            maxScore = max(maxScore, score);
        }
        return maxScore;
    }
};

int main() {
    vector<int> cardPoints = {1, 2, 3, 4, 5, 6, 1};
    int k = 3;

    Solution solution;
    cout << solution.maxScore(cardPoints, k) << endl;

    return 0;
}
```

### Solution 2: Better (Precomputed Prefix and Suffix Sums)
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Finds the maximum score using precomputed left and right sums.
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        // Invalid k cannot form a valid selection.
        if (k < 0 || k > n) {
            return -1;
        }

        // Picking no cards gives a score of zero.
        if (k == 0) {
            return 0;
        }

        // Picking all cards requires the complete array sum.
        if (k == n) {
            return accumulate(cardPoints.begin(), cardPoints.end(), 0);
        }

        vector<int> leftSum(k + 1, 0);
        vector<int> rightSum(k + 1, 0);

        // Store sums for every possible number of left cards.
        for (int i = 1; i <= k; i++) {
            leftSum[i] = leftSum[i - 1] + cardPoints[i - 1];
        }

        // Store sums for every possible number of right cards.
        for (int i = 1; i <= k; i++) {
            rightSum[i] = rightSum[i - 1] + cardPoints[n - i];
        }

        int maxScore = INT_MIN;

        // Combine each valid left count with its matching right count.
        for (int leftCount = 0; leftCount <= k; leftCount++) {
            int rightCount = k - leftCount;

            int currentScore =
                leftSum[leftCount] + rightSum[rightCount];

            // Keep the maximum score among all possible splits.
            if (currentScore > maxScore) {
                maxScore = currentScore;
            }
        }

        return maxScore;
    }
};

int main() {
    vector<int> cardPoints = {1, 2, 3, 4, 5, 6, 1};
    int k = 3;

    Solution solution;
    cout << solution.maxScore(cardPoints, k) << endl;

    return 0;
}
```

### Solution 3: Optimal (Constant Window / Sliding Shift)
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Finds the maximum score by shifting selections between both ends.
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        // Invalid k cannot form a valid selection.
        if (k < 0 || k > n) {
            return -1;
        }

        // Picking no cards gives a score of zero.
        if (k == 0) {
            return 0;
        }

        // Picking all cards requires the complete array sum.
        if (k == n) {
            return accumulate(cardPoints.begin(), cardPoints.end(), 0);
        }

        int currentScore = 0;

        // Start with all k selected cards taken from the left.
        for (int i = 0; i < k; i++) {
            currentScore += cardPoints[i];
        }

        int maxScore = currentScore;
        int rightIndex = n - 1;

        // Replace one left card with one right card in each step.
        for (int leftIndex = k - 1; leftIndex >= 0; leftIndex--) {
            currentScore -= cardPoints[leftIndex];
            currentScore += cardPoints[rightIndex];
            rightIndex--;

            // Keep the best score after each new split.
            if (currentScore > maxScore) {
                maxScore = currentScore;
            }
        }

        return maxScore;
    }
};

int main() {
    vector<int> cardPoints = {1, 2, 3, 4, 5, 6, 1};
    int k = 3;

    Solution solution;
    cout << solution.maxScore(cardPoints, k) << endl;

    return 0;
}
```

---

## Output

**Sample Input 1:**
```
cardPoints = [1, 2, 3, 4, 5, 6, 1], k = 3
```

**Sample Output 1:**
```
12
```
*(Explanation: Take cards 5, 6, and 1 from the right end. Total score = 5 + 6 + 1 = 12.)*

**Sample Input 2:**
```
cardPoints = [2, 2, 2], k = 2
```

**Sample Output 2:**
```
4
```
*(Explanation: Regardless of which 2 cards are chosen, score is always 2 + 2 = 4.)*

**Sample Input 3:**
```
cardPoints = [9, 7, 7, 9, 7, 7, 9], k = 7
```

**Sample Output 3:**
```
55
```
*(Explanation: You must take all cards. Their sum is 55.)*

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Approach 1 (Brute Force) | O(k²) | O(1) |
| Approach 2 (Precomputed Left/Right Sums) | O(k) | O(k) |
| Approach 3 (Optimal - Sliding Shift) | O(k) | O(1) |

*(Where k is the number of cards to pick. Approach 3 performs a single pass over at most 2k elements with O(1) extra memory.)*

---

## Key Takeaway
Whenever asked to select $k$ elements from the boundaries of an array, start with an initial window containing all $k$ elements from one side (left). Then slide the selection boundary across by subtracting one element from the left and adding one from the right in each step (`currentScore += rightCard - leftCard`), achieving $O(k)$ time and $O(1)$ space.
