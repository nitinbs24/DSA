#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int isPossible(vector<int>& arr,int days,int m,int k){
    int count=0,bouquets=0;

    for(auto a:arr){
        if(a<=days){
            count++;
            if(count==k){
                bouquets++;
                count=0;
            }
        } else count=0;
    }
    return bouquets>=m;
}

int minDays(vector<int>& arr,int m,int k){
    long long flowers=1LL*m*k;
    if(flowers>arr.size()) return -1;


    int mini=*min_element(arr.begin(),arr.end()), maxi=*max_element(arr.begin(),arr.end());
    int ans = -1;

    int low = mini, high = maxi;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(isPossible(arr, mid, m, k)){
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main(){
    vector<int> arr {1,10,3,10,2};
    int m=3,k=1;

    cout<<minDays(arr,m,k)<<endl;
}