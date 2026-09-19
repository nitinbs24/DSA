#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

class Solution{
    public:
    int longestConsecutive(vector<int> nums){
        int n=nums.size();
        if(n==0) return 0;

        int longest=1,prevSmallest=INT_MIN,cnt=0;

        sort(nums.begin(),nums.end());

        for(int i=0;i<n;i++){
            if(nums[i]-1 == prevSmallest){
                cnt++;
                prevSmallest=nums[i];
            }
            else if(nums[i]!=prevSmallest){
                cnt=1;
                prevSmallest=nums[i];
            }
            longest=max(longest,cnt);
        }
        return longest;
    }
};

int main(){
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    Solution sol;
    cout<<sol.longestConsecutive(nums)<<endl;
}