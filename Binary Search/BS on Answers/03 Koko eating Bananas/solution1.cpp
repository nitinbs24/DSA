#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int countHours(vector<int> pair, int hours){
    int count=0;
    for(auto p:pair){
        count += (p - 1) / hours + 1;
    }
    return count;
}

int minEatingSpeed(vector<int> pair,int hours){
    int maxi=*max_element(pair.begin(),pair.end());
    int ans;
    for(int i=1;i<=maxi;i++){
        ans=countHours(pair,i);
        if(ans<=hours) return i;
    }
    return maxi;
}


int main(){
    vector<int> pair {7, 15, 6, 3};
    int hours=8;

    cout<<minEatingSpeed(pair,hours)<<endl;
}