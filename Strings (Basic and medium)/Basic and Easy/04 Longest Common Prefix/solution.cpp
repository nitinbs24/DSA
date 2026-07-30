#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

string longestCommonPrefix(vector<string> str){
    string ans="";
    sort(str.begin(),str.end());
    string first=str[0], last=str[str.size()-1];
    int minLeng=min(first.size(),last.size());
    
    for(int i=0;i<minLeng;i++){
        if(first[i]!=last[i]) break;
        ans+=first[i];
    }
    return ans;
}

int main(){
    vector<string> str {"interview", "internet", "internal", "interval"};

    cout<<longestCommonPrefix(str)<<endl;
}