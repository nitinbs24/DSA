#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSumIndices(vector<int> arr, int target) {
        int n = arr.size();
        vector<pair<int, int>> numsWithIndex;
        for (int i = 0; i < n; i++) {
            numsWithIndex.push_back({arr[i], i});
        }
        sort(numsWithIndex.begin(), numsWithIndex.end());

        int left = 0, right = n - 1;
        while (left < right) {
            int sum = numsWithIndex[left].first + numsWithIndex[right].first;
            if (sum == target) {
                return {numsWithIndex[left].second, numsWithIndex[right].second};
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
        return {-1, -1};
    }
};

int main() {
    Solution sol;
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 14;

    vector<int> res = sol.twoSumIndices(arr, target);
    cout << "[" << res[0] << ", " << res[1] << "]\n";

    return 0;
}
