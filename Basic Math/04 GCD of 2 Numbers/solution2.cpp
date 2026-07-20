#include<iostream>
using namespace std;


int GCD(int a,int b){

    while(a>0 && b>0){
        if(a>b) a=a%b;
        else b=b%a;
    }

    if(a==0) return b;
    return a;
}
int main(){
    int a,b;
    cout<<"Enter 2 numbers: ";
    cin>>a>>b;

    cout<<"GCD of "<<a<<" and "<<b<<" is:"<<GCD(a,b)<<endl;
}