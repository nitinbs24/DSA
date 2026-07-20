#include<iostream>
using namespace std;

int factorial(int x){
    int ans=1;
    
    for(int i=1;i<=x;i++) ans*=i;

    return ans;
}
int main(){
    int x=5;

    cout<<factorial(x)<<endl;
}