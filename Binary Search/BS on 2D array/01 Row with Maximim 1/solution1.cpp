#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

int withMax(vector<vector<int>>& arr, int n,int m){
    int count_max=0,ans=0,res=-1;
    for(int i=0;i<n;i++){
        ans=accumulate(arr[i].begin(),arr[i].end(),0);
        if(ans>count_max){
            count_max=ans;
            res=i;
        }
    }
    return res;
}

int main(){
    vector<vector<int>> arr {{1,1,1},{0,0,1},{0,0,0}};
    int n=3,m=3;

    cout<<withMax(arr,n,m)<<endl;
}