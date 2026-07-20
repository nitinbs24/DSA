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
    int num,rev_num;
    cout<<"Enter number: ";
    cin>>num;

    rev_num=reverseNumber(num);
    if(rev_num==num) cout<<"Palindrome\n";
    else cout<<"Not Palindrome\n";
}