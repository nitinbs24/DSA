#include<iostream>
#include<algorithm>
using namespace std;


int GCD(int a,int b){
    for(int i=min(a,b);i>0;i--){
        if(a%i==0 and b%i==0) return i;
    }
    return 1;
}
int main(){
    int a,b;
    cout<<"Enter 2 numbers: ";
    cin>>a>>b;

    cout<<"GCD of "<<a<<" and "<<b<<" is:"<<GCD(a,b)<<endl;
}