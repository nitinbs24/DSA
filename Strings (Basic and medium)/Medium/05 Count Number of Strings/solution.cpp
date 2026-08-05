#include<iostream>
#include <unordered_map>
using namespace std;

int kSubstring(string& str, int k){
    int left=0,res=0;
    unordered_map<char,int> freq;

    for(int right=0;right<str.size();right++){
        freq[str[right]]++;

        while(freq.size()>k){
            freq[str[left]]--;
            if(freq[str[left]]==0) freq.erase(str[left]);
            left++;
        }
        res+=(right-left+1);
    }
    return res;
}

int countSubstring(string& str, int k){
    return kSubstring(str,k)-kSubstring(str,k-1);
}

int main(){
    string str="pqpqs";
    int k=2;

    cout<<"Count: "<<countSubstring(str,k)<<endl;
}