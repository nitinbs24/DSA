#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    vector<int> spiralTraverse(vector<vector<int>>& nums){
        int top=0;
        int right=nums[0].size()-1;
        int bottom=nums.size()-1;
        int left=0;

        vector<int> res;

        while(left<=right && top<=bottom){

            for(int i=left;i<=right;i++){
                res.push_back(nums[top][i]);
            }
            top++;

            for(int i=top;i<=bottom;i++){
                res.push_back(nums[i][right]);
            }
            right--;

            if(top<=bottom){
                for(int i=right;i>=left;i--){
                    res.push_back(nums[bottom][i]);
                }
                bottom--;
            }

            if(left<=right){
                for(int i=bottom;i>=top;i--){
                    res.push_back(nums[i][left]);
                }
                left++;
            }
        }
        return res;
    }
};


int main(){
    Solution sol;

    vector<vector<int>> nums {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<int> res = sol.spiralTraverse(nums);

    for(auto num: res){
        
        cout<<num<<" ";
    } 
    cout<<endl;
}