#include<iostream>
using namespace std;

void swapper(int a,int b){
    cout<<a<<" "<<b<<endl;

    a=a^b;
    b=a^b;
    a=a^b;

    cout<<a<<" "<<b<<endl;
}

int main(){
    swapper(5,3);
}