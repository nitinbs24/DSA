#include<iostream>
#include<vector>
//#include<cmath>
#include<algorithm>
using namespace std;

int smallestDivisor(vector<int>& nums,int threshold){

    int low=1, high=*max_element(nums.begin(),nums.end());
    int ans=0;
    while(low<=high){

        long long sum=0;
        int mid=low+(high-low)/2;
        for(int i=0;i<nums.size();i++){
            sum+=(nums[i]-1)/mid+1;
        }
        if(sum<=threshold){
            ans=mid;
            high=mid-1;
        }
        else low=mid+1;
    }
    return ans;
}

int main(){
    vector<int> nums {1,2,5,9};
    int threshold=6;

    cout<<smallestDivisor(nums,threshold)<<endl;
}