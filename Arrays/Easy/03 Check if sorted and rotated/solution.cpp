#include<iostream>
#include<vector>
using namespace std;
bool checkSort(vector<int>& nums){
    int drop=0;
    for(int i=1;i<nums.size();i++){
        if(nums[i-1]>nums[i]) drop++;
    }
    if(nums[nums.size()-1]>nums[0]) drop++;

    return drop<2;
}
int main(){
    vector<int> nums {4,5,1,2,3};

    cout<<checkSort(nums)<<endl;

}