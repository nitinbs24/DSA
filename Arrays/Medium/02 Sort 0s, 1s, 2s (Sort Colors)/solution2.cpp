#include<iostream>
#include<vector>
#include<utility>
using namespace std;

void sortColors(vector<int>& nums){
    
    int low=0,high=nums.size()-1,mid=0;

    while(mid<=high){

        if(nums[mid]==0){
            swap(nums[low],nums[mid]);
            low++; mid++;
        }
        else if(nums[mid]==1) mid++;

        else{
            swap(nums[mid],nums[high]);
            high--;
        }
    }
}
int main(){

    vector<int> nums {2,1,1,0,1,2,0};

    sortColors(nums);

    for(auto num: nums) cout<<num;
    cout<<"\n";
}
