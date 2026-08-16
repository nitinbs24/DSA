#include<iostream>
using namespace std;

bool checker(int n){
    return (n>0 && (n&(n-1))==0);
}

int main(){
    if(checker(16)) cout<<"True\n";
    else cout<<"False\n";
}