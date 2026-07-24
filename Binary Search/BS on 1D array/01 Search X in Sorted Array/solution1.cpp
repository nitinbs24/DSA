#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int>& nums, int target){
    int low=0,high=nums.size()-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]==target) return mid+1;
        else if(target<nums[mid]) high=mid-1;
        else low=mid+1;
    }
    return -1;
}
int main(){
    vector<int> nums {1,2,3,4,5,6,7};
    int target=2;

    cout<<binarySearch(nums,target)<<endl;
}