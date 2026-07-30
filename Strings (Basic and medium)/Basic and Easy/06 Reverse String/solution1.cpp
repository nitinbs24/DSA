#include<iostream>

using namespace std;

bool rotateString(string& s, string& goal){
    if(s.length()!=goal.length()) return false;
    for(int i=0;i<s.length();i++){
        string res=s.substr(i)+s.substr(0,i);
        if(res==goal) return true;
    }
    return false;
}

int main(){
    string s="hello", goal="lohel";

    cout<<rotateString(s,goal)<<endl;
}