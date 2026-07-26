#include<iostream>
#include<vector>
using namespace std;

int findLowerBound(vector<int>& arr,int n,int x){
    int low=0,high=n-1,res=-1;
    while(low<=high){

        int mid=low+(high-low)/2;
        if(arr[mid]>=x){
            res=mid;
            high=mid-1;
        }
        else low=mid+1;
    }
    return res;
}

int withMax(vector<vector<int>>& arr, int n,int m){
    int count_max=0,ans=0,res=-1,ones_count;
    for(int i=0;i<n;i++){
        ans=findLowerBound(arr[i], m, 1);
        if(ans==-1) ones_count=0;
        else ones_count=m-ans;
        if((ones_count)>count_max){
            count_max=ones_count;
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