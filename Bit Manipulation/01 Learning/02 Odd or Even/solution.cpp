#include<iostream>
using namespace std;

bool checker(int num){
    return (num&1)==0;
}

int main(){
    int num=9;
    if(checker(num)) cout<<"even\n";
    else cout<<"odd\n";
}