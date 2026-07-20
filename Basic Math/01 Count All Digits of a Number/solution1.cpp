#include<iostream>
using namespace std;

int counter(int num){
    int c=0;
    while(num>0){
        num=num/10;
        c++;
    }
    return c;
}
int main(){
    int num;
    cout<<"Enter number: ";
    cin>>num;

    cout<<"digit count: "<<counter(num)<<endl;
}