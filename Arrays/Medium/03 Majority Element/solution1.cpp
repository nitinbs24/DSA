#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int majorityElement(vector<int>& nums){
    unordered_map<int, int> mp;
    for(int num:nums) mp[num]++;

    for(auto& pair:mp){
        if(pair.second>(nums.size()/2)) return pair.first;
    }
    return -1;

}
int main(){
    vector<int> nums {2,1,1,2,2};

    cout<<majorityElement(nums)<<endl;
}