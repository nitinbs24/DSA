#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
    public:
    vector<vector<int>> merge(vector<vector<int>> nums){

        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;

        for(auto num:nums){
            if(ans.empty() || ans.back()[1]<num[0]) ans.push_back(num);
            else ans.back()[1]=max(ans.back()[1],num[1]);
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> nums = {{1,3}, {2,6}, {8,10}, {15,18}};
    vector<vector<int>> result = sol.merge(nums);

    for (auto interval : result) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
}