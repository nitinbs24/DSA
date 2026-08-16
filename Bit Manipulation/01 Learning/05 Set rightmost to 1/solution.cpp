#include<iostream>
using namespace std;

int setter(int n){
    return n|1;
}

int main(){
    cout<<setter(10)<<endl;
}