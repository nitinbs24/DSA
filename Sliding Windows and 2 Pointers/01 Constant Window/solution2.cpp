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