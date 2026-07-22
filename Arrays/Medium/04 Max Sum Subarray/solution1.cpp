#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int maxSubArray(vector<int>& nums){
    int maxi=INT_MIN,n=nums.size();
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=nums[j];
            maxi=max(sum,maxi);
        }
    }
    return maxi;
}

int main(){
    vector<int> nums {-2,1,-3,4,-1,2,1,-5,4};

    cout<<maxSubArray(nums)<<endl;
}