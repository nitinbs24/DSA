#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    vector<vector<int>> rotate90(vector<vector<int>> nums){


        int n=nums.size(),m=nums[0].size();
        vector<vector<int>> rotated (m,vector<int> (n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                rotated[j][n-i-1]=nums[i][j];
            }
        }
        return rotated;
    }
};

int main(){
    vector<vector<int>> nums {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    for(auto i:nums){
        for(auto j:i) cout<<j<<" ";
        cout<<endl;
    }
    Solution sol;
    vector<vector<int>> rotated=sol.rotate90(nums);

    cout<<"After:\n";
    for(auto i:rotated){
        for(auto j:i) cout<<j<<" ";
        cout<<endl;
    }
}