#include<iostream>
#include<algorithm>
using namespace std;

bool comparator(pair<int,char> p1,pair<int,char> p2){
    if(p1.first>p2.first) return true;
    if(p1.first<p2.first) return false;
    return p1.second<p2.second;
}

string frequencySort(string& str){
    pair<int,char> freq[256];
    for(int i=0;i<256;i++){
        freq[i]={0,i};
    }

    for(char ch:str){
        freq[ch].first++;
    }
    
    sort(freq,freq+256,comparator);

    string ans = "";
    for(int i=0;i<256;i++) {
        if(freq[i].first>0) {
            ans.append(freq[i].first, freq[i].second);
        }
    }

    return ans;
}

int main(){
    string str="tree";
    string res=frequencySort(str);
    cout<<res<<endl;
}