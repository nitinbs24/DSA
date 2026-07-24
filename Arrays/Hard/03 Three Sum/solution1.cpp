#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums, int n){
    set<vector<int>> res;

    for(int i=0;i<n;i++){
        set<int> hashset;
        for(int j=i+1;j<n;j++){
            int third=-(nums[i]+nums[j]);

            if(hashset.find(third)!=hashset.end()){
                vector<int> temp {nums[i],nums[j],third};
                sort(temp.begin(),temp.end());
                res.insert(temp);
            }
            hashset.insert(nums[j]);
        }
    }
    return vector<vector<int>> (res.begin(),res.end());
}

int main(){
    vector<int> nums {-1,0,1,2,-1,-4};
    int n=nums.size();
    vector<vector<int>> res=threeSum(nums,n);
    for(auto&r: res){
        for(auto&c: r) cout<<c<<" ";
        cout<<endl;
    }
}