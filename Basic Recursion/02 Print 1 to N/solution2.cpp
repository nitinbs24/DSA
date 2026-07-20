#include<iostream>
using namespace std;

void printer(int current, int n){
    if(current>n) return;

    printer(current+1,n);

    cout<<current<<endl;
}

int main(){

    int n=10;

    printer(1,n);

    return 0;
}