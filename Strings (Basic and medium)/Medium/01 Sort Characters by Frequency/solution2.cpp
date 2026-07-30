#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;

string frequencySort(string& str){
    unordered_map<char,int> mp;
    for(auto ch:str){
        mp[ch]++;
    }
    vector<pair<int,char>> arr;
    for(auto it:mp){
        arr.push_back({it.second,it.first});
    }
    sort(arr.rbegin(),arr.rend());
    string ans="";
    for(int i=0;i<arr.size();i++) ans+=string(arr[i].first,arr[i].second);

    return ans;
}

int main(){
    string str="nitin";
    string res=frequencySort(str);
    cout<<res<<endl;
}