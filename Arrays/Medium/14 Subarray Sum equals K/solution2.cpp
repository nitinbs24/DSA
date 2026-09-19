#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int subarraySum(vector<int>& arr, int k) {

        int n = arr.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
 
            int sum = 0;

            for (int j = i; j < n; j++) {
                sum += arr[j];
                if (sum == k) {
                    count++;
                }
            }
        }

        return count;
    }
};

int main() {

    vector<int> arr = {3, 1, 2, 4};
    int k = 6;
    Solution sol;

    int result = sol.subarraySum(arr, k);

    cout << "The number of subarrays is: " << result << "\n";

    return 0;
}
