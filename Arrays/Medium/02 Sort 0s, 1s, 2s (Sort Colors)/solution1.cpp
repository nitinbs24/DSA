#include<iostream>
#include<vector>
using namespace std;

void sortColors(vector<int>& nums){
    int zero=0,one=0,two=0;

    for(int i=0;i<nums.size();i++){
        if(nums[i]==0) zero++;
        else if (nums[i]==1) one++;
        else two++;
    }
    nums.clear();
    while(zero--) nums.push_back(0);
    while(one--) nums.push_back(1);
    while(two--) nums.push_back(2);
}
int main(){

    vector<int> nums {2,1,1,0,1,2,0};

    sortColors(nums);

    for(auto num: nums) cout<<num;
    cout<<"\n";
}
