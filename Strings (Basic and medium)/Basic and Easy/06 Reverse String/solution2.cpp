#include<iostream>
using namespace std;

bool rotateString(string& s, string& goal){
    if(s.length()!=goal.length()) return false;
    string ds=s+s;
    return ds.find(goal) != string::npos;
}

int main(){
    string s="hello", goal="lohel";

    cout<<rotateString(s,goal)<<endl;
}