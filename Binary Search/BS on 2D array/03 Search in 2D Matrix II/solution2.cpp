#include<iostream>
#include<vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix,int target){
    
    int n=matrix.size(),m=matrix[0].size();
    int row=0, column=m-1;

    while(row<n && column>=0){
        if(matrix[row][column]==target) return true;
        else if(matrix[row][column]>target) column--;
        else row++;
    }

    return false;
}

int main(){
    vector<vector<int>> matrix {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    int target=5;

    if(searchMatrix(matrix,target)) cout<<"Found\n";
    else cout<<"Not Found\n";
}