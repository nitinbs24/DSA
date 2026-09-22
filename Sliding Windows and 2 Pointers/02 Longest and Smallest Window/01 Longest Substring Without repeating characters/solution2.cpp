#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash (128,-1);
        int left=0,maxLen=0;

        for(int right=0;right<s.length();right++){

            if(hash[s[right]]>=left) left=hash[s[right]]+1;

            hash[s[right]]=right;
            maxLen=max(maxLen,right-left+1);
        }
        return maxLen;
    }
};

int main(){
    Solution sol;
    string name="nitin";

    cout<<sol.lengthOfLongestSubstring(name)<<endl;

}