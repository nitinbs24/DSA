#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int>& nums, int low, int high, int target){

    if(low>high) return -1;

    int mid=(low+high)/2;
    
    if(nums[mid]==target) return mid+1;
    else if(target<nums[mid]) return binarySearch(nums,low,mid+1,target);
    else return binarySearch(nums,mid+1,high,target);
    
}
int main(){
    vector<int> nums {1,2,3,4,5,6,7};
    int target=2;
    int low=0,high=nums.size()-1;

    cout<<binarySearch(nums,low,high,target)<<endl;
}