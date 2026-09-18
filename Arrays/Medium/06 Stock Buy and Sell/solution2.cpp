#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int maxProfit(vector<int>& prices){
    int n=prices.size(),minPrice=INT_MAX,maxProfit=0;

    for(int i=0;i<n;i++){
        if(prices[i]<minPrice) minPrice=prices[i];
        else if(prices[i]-minPrice>maxProfit) maxProfit=prices[i]-minPrice;
    }
    return maxProfit;
}

int main(){
    vector<int> prices={7, 1, 5, 3, 6, 4};

    cout<<maxProfit(prices)<<endl;
}