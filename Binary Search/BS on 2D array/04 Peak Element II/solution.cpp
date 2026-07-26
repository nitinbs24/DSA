#include <climits>
#include<iostream>
#include<vector>
using namespace std;

int findMax(vector<vector<int>>& nums,int col){
    int max_num=INT_MIN,ans;
    for(int i=0;i<nums.size();i++){
        if(nums[i][col]>max_num){
            max_num=nums[i][col];
            ans=i;
        }
    }
    return ans;
}

vector<int> findPeakGrid(vector<vector<int>>& nums){
    int n=nums.size(), m=nums[0].size();

    int low=0,high=m-1;;

    while(low<=high){
        int mid=(low+high)/2;

        int row=findMax(nums,mid);

        int left=mid-1>=0?nums[row][mid-1]:INT_MIN;
        int right=mid+1<m?nums[row][mid+1]:INT_MIN;

        if(nums[row][mid]>left && nums[row][mid]>right) return {row,mid};
        else if(left>nums[row][mid]) high=mid-1;
        else low=mid+1;
    }
    return {-1,-1};
}

int main(){
    vector<vector<int>> nums {{5, 10, 8}, {4, 25, 7}, {3, 9, 6}};

    vector<int> ans =findPeakGrid(nums);
    cout<<"["<<ans[0]<<","<<ans[1]<<"]\n";
}
