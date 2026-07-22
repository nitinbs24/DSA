#include<iostream>
#include<vector>
using namespace std;

int majorityElement(vector<int>& nums) {
        
        // Size of the given array
        int n = nums.size(),cnt = 0,el; 

        for (int i = 0; i < n; i++) {
            if (cnt == 0) {
                cnt = 1;
                el = nums[i];
            } else if (el == nums[i]) {
                cnt++;
            } else {
                cnt--;
            }
        }
        int cnt1 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == el) {
                cnt1++;
            }
        }
        if (cnt1 > (n / 2)) {
            return el;
        }
        return -1;
    }
int main(){
    vector<int> nums {2,1,1,2,2};

    cout<<majorityElement(nums)<<endl;
}