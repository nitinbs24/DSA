#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
    public:
    vector<vector<int>> merge(vector<vector<int>> nums){
        int n=nums.size();

        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<n;){
            int start=nums[i][0];
            int end=nums[i][1];

            int j=i+1;
            while(j<n && nums[j][0]<=end){
                end=max(end,nums[j][1]);
                j++;
            }
            ans.push_back({start,end});
            i=j;
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