#include<iostream>
#include<cmath>

using namespace std;

int countDigits(int dig){
    int count=(int)(log10(dig)+1);

    return count;
}

int main(){
    int dig;
    cout<<"Enter the digit: ";
    cin>>dig;

    cout<<"Digits: "<<countDigits(dig)<<endl;
}