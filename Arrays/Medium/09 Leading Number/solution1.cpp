#include<iostream>
#include<vector>
using namespace std;

vector<int> leaderNumber(vector<int>& nums){
    vector<int> ans;
    int i=0;
    for(i=0;i<nums.size();i++){
        bool isLeader=true;
        for(int j=i+1;j<nums.size();j++){
            if(nums[j]>=nums[i]){
                isLeader=false;
                break;
            }
        }
        if(isLeader){
            ans.push_back(nums[i]);
        }
    }
    return ans;
}

int main(){
    vector<int> nums = {10, 22, 12, 3, 0, 6};

    vector<int> ans=leaderNumber(nums);
    cout<<"{ ";
    for(auto num:ans){
        cout<<num<<" ";
    }
    cout<<"}\n";
}