#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
    public:
    vector<int> leaderNumbers(vector<int>& nums){
        vector<int> ans;

        if(nums.empty()) return ans;

        int max=nums[nums.size()-1];
        ans.push_back(max);

        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]>max){
                ans.push_back(nums[i]);
                max=nums[i];
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

int main(){
    Solution sol;

    vector<int> nums = {10, 22, 12, 3, 0, 6};

    vector<int> ans = sol.leaderNumbers(nums);

    cout<<"{ ";
    for(auto num:ans){
        cout<<num<<" ";
    }
    cout<<"}\n";
}