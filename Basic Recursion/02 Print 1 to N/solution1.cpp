#include<iostream>
using namespace std;

void printer(int current, int n){
    if(current>n) return;

    cout<<current<<endl;

    printer(current+1,n);
}

int main(){

    int n=10;

    printer(1,n);

    return 0;
}