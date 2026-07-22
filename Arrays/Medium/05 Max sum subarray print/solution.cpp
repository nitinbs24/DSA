#include <bits/stdc++.h>
using namespace std;


int maxSubArray(vector<int>& nums) {

    int maxi=INT_MIN,start=0,sum=0,ansStart=-1,ansEnd=-1;
    for(int i=0;i<nums.size();i++){
        if(sum==0) start=i;

        sum+=nums[i];

        if(sum>maxi){
            maxi=sum;
            ansStart=start;
            ansEnd=i;
        }

        if(sum<0) sum=0;
    }
    cout << "The subarray is: [";
    for (int i = ansStart; i <= ansEnd; i++) {
        cout << nums[i] << " ";
    }
    cout << "]" << endl;
    return maxi;
}


int main() {
    vector<int> arr = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
    int maxSum = maxSubArray(arr);
    cout << "The maximum subarray sum is: " << maxSum << endl;
}