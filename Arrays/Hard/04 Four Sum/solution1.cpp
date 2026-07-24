#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<int>> fourSum(vector<int>& arr, int target) {
        int n = arr.size();
        set<vector<int>> st;  

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                unordered_set<int> seen;

                for (int k = j + 1; k < n; k++) {
                    long long required = (long long)target - arr[i] - arr[j] - arr[k];

                    if (seen.count(required)) {
                        vector<int> temp = {arr[i], arr[j], arr[k], (int)required};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }

                    seen.insert(arr[k]);
                }
            }
        }

        return vector<vector<int>>(st.begin(), st.end());
    }
};

int main() {
    vector<int> arr = {1, 0, -1, 0, -2, 2};
    int target = 0;

    Solution obj;
    vector<vector<int>> ans = obj.fourSum(arr, target);

    for (auto quad : ans) {
        for (int num : quad) cout << num << " ";
        cout << endl;
    }
    return 0;
}
