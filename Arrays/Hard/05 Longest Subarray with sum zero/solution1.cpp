#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int sumSubArray(vector<int>& nums){
    int maxi=0,sum,n=nums.size();
    for(int i=0;i<n;i++){
        sum=0;
        for(int j=i;j<n;j++){
            sum+=nums[j];

            if(sum==0) maxi=max(maxi, j - i + 1);
        }
    }
    return maxi;
}
int main(){
    vector<int> nums {9, -3, 3, -1, 6, -5};

    cout<<sumSubArray(nums)<<endl;
}