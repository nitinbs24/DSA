#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long countHours(const vector<int>& pair, int hours){
    long long count=0;
    for(auto p:pair){
        count += (p - 1) / hours + 1;
    }
    return count;
}

int minEatingSpeed(const vector<int>& pair,int hours){
    int low=1, high=*max_element(pair.begin(),pair.end());
    int ans;
    while (low<=high){

        int mid=low+(high-low)/2;
        long long totalHours=countHours(pair, mid);
        if(totalHours<=hours){
            ans=mid;
            high=mid-1;
        }
        else low=mid+1;
    }
    return ans;
}

int main(){
    vector<int> pair {7, 15, 6, 3};
    int hours=8;

    cout<<minEatingSpeed(pair,hours)<<endl;
}