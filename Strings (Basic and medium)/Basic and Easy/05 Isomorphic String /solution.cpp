#include<iostream>
using namespace std;

bool isIsomorphic(string s,string t){
    int a[256]={0},b[256]={0};
    int n=s.size();

    for(int i=0;i<n;i++){
        if(a[s[i]]!=b[t[i]]) return false;
        a[s[i]]=i+1;
        b[t[i]]=i+1;
    }
    return true;
}

int main(){
    string s="paper",t="title";
    cout<<isIsomorphic(s,t)<<endl;
}