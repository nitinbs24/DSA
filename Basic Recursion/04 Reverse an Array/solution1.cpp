#include<iostream>
#include<vector>
using namespace std;

void reverseArray(vector<int>& nums){
    int a=0,b=nums.size()-1;

    while(a<b){
        swap(nums[a],nums[b]);
        a++,b--;
    }
}
int main(){
    vector<int> nums {1,2,3,4,5};

    reverseArray(nums);

    for(auto num:nums) cout<<num<<endl;
}