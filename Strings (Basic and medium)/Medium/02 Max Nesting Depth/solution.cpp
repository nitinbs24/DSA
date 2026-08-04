#include<iostream>
using namespace std;

int maxDepth(string str){
    int p=0,ans=0;

    for(auto x: str){
        if(x=='(') p++;
        else if(x==')')p--;

        ans=max(ans,p);
    }
    return ans;
}

int main(){
    string str="(1)+((2))+(((3)))";

    cout<<maxDepth(str)<<endl;
}