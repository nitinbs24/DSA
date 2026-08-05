#include<iostream>
using namespace std;

int helper(string& str, int left, int right){
    while(left>=0 && right<str.length() && str[left]==str[right]){
        left--;
        right++;
    }
    return right-left-1;
}

string longestPalindrome(string& str){
    int start=0,end=0;

    for(int i=0;i<str.size();i++){

        int len1=helper(str,i,i);

        int len2=helper(str,i,i+1);

        int max_len=max(len1,len2);

        if(max_len>end-start){
            start=i-(max_len-1)/2;
            end=i+max_len/2;
        }
    }
    return str.substr(start,end-start+1);
}

int main(){
    string str="babad";
    cout<<longestPalindrome(str)<<endl;
}