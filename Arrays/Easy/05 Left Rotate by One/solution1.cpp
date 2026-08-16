#include<iostream>
#include<vector>
using namespace std;

void rotateLeft(vector<int>& arr){
    vector<int> temp;

    for(int i=1;i<arr.size();i++){
        temp.push_back(arr[i]);
    }
    temp.push_back(arr[0]);

    for(int num:temp){
        cout<<num<<" ";
    }
}

int main(){
    vector<int> arr {1,2,3,4,5};
    rotateLeft(arr);
}