#include<iostream>
#include<vector>

using namespace std;

void moveZeroes(vector<int>& nums){
    int j=-1;
    for(int i=0;i<nums.size();i++){
        if(nums[i]==0){
            j=i;
            break;
        }
    }
    if(j==-1) return;

    for(int i=j+1;i<nums.size();i++){
        if(nums[i]!=0){
            swap(nums[i],nums[j]);
            j++;
        }
    }

    for(int num:nums) cout<<num<<" ";
}

int main(){
    vector<int> nums {1,0,2,0,0,3,8,5};
    moveZeroes(nums);
}