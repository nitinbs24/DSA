#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int>& nums, int x){

    int low=0,high=nums.size()-1, ans=nums.size();
    
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]>=x){
            ans=mid;
            high=mid-1;
        }
        else low=mid+1;
    }
    if (ans<nums.size() && nums[ans]==x) return ans;
    else{
        nums.insert(nums.begin()+ans,x);
        return ans;
    }
}
int main(){
    vector<int> nums {3,5,8,15,19};
    int x=8;

    cout<<binarySearch(nums,x)<<endl;

    for(auto num:nums) cout<<num<<" ";
}