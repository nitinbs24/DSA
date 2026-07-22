#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> twoSumChecker(vector<int>& nums,int target){
    unordered_map<int, int> mp;
    int n=nums.size();

    for(int i=0;i<n;i++){
        int num=target-nums[i];
        if(mp.find(num)!=mp.end()){
            return {mp[num],i};
        }
        mp[nums[i]]=i;
    }
    return {-1,-1};
}
int main(){
    vector<int> nums {11,43,66,22,87,21};
    int target=65;

    vector<int> res=twoSumChecker(nums,target);
    cout<<"["<<res[0]<<","<<res[1]<<"]\n";


}