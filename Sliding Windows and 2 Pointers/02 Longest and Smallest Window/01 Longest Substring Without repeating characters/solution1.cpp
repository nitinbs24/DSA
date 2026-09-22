#include <algorithm>
#include<iostream>
#include <unordered_set>
using namespace std;

class Solution{
    public:
    int longestSubstring(string s){
        int left=0,right=0,maxLen=0;
        unordered_set<char> window;

        while(right<s.length()){
            while(window.count(s[right])){
                window.erase(s[left]);
                left++;
            }

            window.insert(s[right]);
            maxLen=max(maxLen,right-left+1);
            right++;
        }
        return maxLen;
    }
};

int main(){
    string name="nitin";
    Solution sol;
    cout<< sol.longestSubstring(name)<<endl;
    
}