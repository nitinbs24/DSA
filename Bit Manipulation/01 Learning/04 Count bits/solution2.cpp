#include<iostream>
using namespace std;

int counter(int n){
    int count=0;
    while(n){
        n&=(n-1);
        count++;
    }
    return count;
}

int main(){
    cout<<counter(15)<<endl;
}