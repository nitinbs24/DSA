#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int>& prices){
    int n=prices.size(),maxProfit=0;

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int profit=prices[j]-prices[i];

            maxProfit=max(maxProfit,profit);
        }
    }
    return maxProfit;
}

int main(){
    vector<int> prices={7, 1, 5, 3, 6, 4};

    cout<<maxProfit(prices)<<endl;
}