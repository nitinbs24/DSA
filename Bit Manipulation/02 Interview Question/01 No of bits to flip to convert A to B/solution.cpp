#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minBitsFlip(int start, int goal) {
        int num = start ^ goal;
        int count = 0;

        for(int i = 0; i < 32; i++) {
            count += (num & 1); 
            num = num >> 1;
        }
        return count;
    }
};

int main() {
    int start = 10, goal = 7;
    
    Solution sol; 
    int ans = sol.minBitsFlip(start, goal);
    
    cout << "The minimum bit flips to convert number is: " << ans;
    
    return 0;
}
