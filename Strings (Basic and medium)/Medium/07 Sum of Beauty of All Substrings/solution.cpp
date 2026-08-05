#include <climits>
#include<iostream>
#include<unordered_map>
using namespace std;

int beautySum(string& str){
    int n=str.size();
    int sum=0;

    for(int i=0;i<n;i++){
        unordered_map<char,int> freq;
        for(int j=i;j<n;j++){
            freq[str[j]]++;

            int mini=INT_MAX;
            int maxi=INT_MIN;

            for(auto a: freq){
                mini=min(mini,a.second);
                maxi=max(maxi,a.second);
            }
            sum+=(maxi-mini);
        }
    }
    return sum;
}

int main(){
    string str="aabcb";
    cout<<beautySum(str)<<endl;
}