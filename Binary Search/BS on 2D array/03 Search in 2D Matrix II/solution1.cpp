#include<iostream>
#include<vector>
using namespace std;

bool binarySearch(vector<int>& nums,int low,int high,int x){
    while(low<=high){
        int mid=low+(high-low)/2;
        if(nums[mid]==x) return true;
        else if(nums[mid]>x) high=mid-1;
        else low=mid+1;
    }
    return false;
}

bool searchMatrix(vector<vector<int>>& matrix,int target){
    
    int n=matrix.size(),m=matrix[0].size();
    for(int i=0;i<n;i++){
        if(matrix[i][0]<=target && target<=matrix[i][m-1]){
            if(binarySearch(matrix[i],0,m-1,target)) return true;
        }
    }
    return false;
}

int main(){
    vector<vector<int>> matrix {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target=3;

    if(searchMatrix(matrix,target)) cout<<"Found\n";
    else cout<<"Not Found\n";
}