#include<iostream>
#include<vector>
using namespace std;

int findLargest(vector<int>& nums){
    int max=nums[0];

    for(auto it:nums){
        if(it>max) max=it;
    }

    return max;
}

int main(){
    int n;
    cin>>n;
    vector<int> nums;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        nums.push_back(x);
    }

    cout<<findLargest(nums)<<endl;
}