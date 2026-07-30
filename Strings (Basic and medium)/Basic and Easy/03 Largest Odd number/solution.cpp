#include<iostream>
#include <string>
using namespace std;

string largestOddNumber(string num){
    int ind=-1;
    for(int i=num.length()-1;i>=0;i--){
        if((num[i]-'0')%2==1){
            ind=i;
            break;
        }
    }
    int i=0;
    while(i<=ind && num[i]=='0') i++;

    return num.substr(i,ind-i+1);
}

int main(){
    string num="02468";
    cout<<largestOddNumber(num)<<endl;
}