#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int> nums {1,2,3,4,5,6};

    reverse(nums.begin(),nums.end());

    for(auto num: nums) cout<<num<<endl;
}