#include<iostream>
using namespace std;

int reverseNumber(int num){
    int reverse=0,n;

    while(num>0){
        n=num%10;
        reverse=reverse*10+n;
        num=num/10;
    }
    return reverse;
}

int main(){
    int num;
    cout<<"Enter number: ";
    cin>>num;

    cout<<"Reversed number: "<<reverseNumber(num)<<endl;
}