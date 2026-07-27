#include <algorithm>
#include<iostream>
#include<vector>
using namespace std;

string reverseWords(string s){
    vector<string> words;
    string word="";
    for(int i=0;i<s.size();i++){
        if(s[i]!=' '){
            word+=s[i];
        }
        else if(!word.empty()){
            words.push_back(word);
            word="";
        }
    }
    if(!word.empty()){
        words.push_back(word);
    }
    reverse(words.begin(),words.end());

    string result="";
    for(int w=0;w<words.size();w++){
        result+=words[w];
        if(w<words.size()-1){
            result+=" ";
        }
    }
    return result;
}

int main(){

    string s="Hello World";
    cout<<reverseWords(s)<<endl;
    
}