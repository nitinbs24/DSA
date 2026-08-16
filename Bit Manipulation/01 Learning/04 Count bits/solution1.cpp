#include<iostream>
using namespace std;

int counter(int n){
    int count=0;
    while(n>0){
        count+=(n&1);
        n>>=1;
    }
    return count;
}

int main(){
    cout<<counter(5)<<endl;
}