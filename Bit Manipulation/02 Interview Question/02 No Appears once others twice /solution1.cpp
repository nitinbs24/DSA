#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int getSingleElement(vector<int>& arr) {
        unordered_map<int, int> hash;

        for (int i = 0; i < arr.size(); i++) {
            hash[arr[i]]++;
        }

        for (int i = 0; i < arr.size(); i++) {
            if (hash[arr[i]] == 1)
                return arr[i];
        }

        return -1; 
    }
};

int main() {
    vector<int> arr = {4, 1, 2, 1, 2};
    Solution obj;
    int ans = obj.getSingleElement(arr);
    cout << "The single element is: " << ans << endl;
    return 0;
}