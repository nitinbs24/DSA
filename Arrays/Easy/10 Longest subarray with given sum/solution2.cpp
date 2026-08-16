#include<iostream>
#include<vector>
using namespace std;

int longestSubarray(vector<int>& nums,int k){
    int sum=nums[0],maxLength=0;
    int left=0,right=0;
    int n=nums.size();
    while(right<n){
        while(left<=right && sum>k){
            sum-=nums[left];
            left++;
        }

        if(sum==k) maxLength=max(maxLength,right-left+1);

        right++;

        if(right<n) sum+=nums[right];
    }
    return maxLength;
}

int main() {
	vector<int> nums = {10, 5, 2, 7, 1, 9};
    int k = 15;

	int ans = longestSubarray(nums, k);

	cout << "The length of longest subarray having sum k is: " << ans;

	return 0;
}