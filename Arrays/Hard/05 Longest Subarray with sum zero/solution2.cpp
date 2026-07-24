#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

int sumSubArray(vector<int>& nums){
    int maxi=0,sum=0;
    unordered_map<int, int> map;
    for(int i=0;i<nums.size();i++){
        sum+=nums[i];

        if(sum==0) maxi=i+1;
        else{
            if(map.find(sum)!=map.end()){
                maxi=max(maxi,i-map[sum]);
            }
            else map[sum]=i;
        
        }
    }
    return maxi;
}
int main(){
    vector<int> nums {9, -3, 3, -1, 6, -5};

    cout<<sumSubArray(nums)<<endl;
}