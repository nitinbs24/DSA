#include<iostream>
using namespace std;

bool checkIthBit(int num,int i){
    string binary="";
    while(num>0){
        binary+=(num%2==0)?"0":"1";
        num=num/2;
    }
    if(i>=binary.size()) return false;

    return (binary[i]=='1');
}
int main() {
    int num = 5;
    int bitIndex = 2;

    if (checkIthBit(num, bitIndex)) {
        cout << "The " << bitIndex << "-th bit of " << num << " is set (1)." << endl;
    } else {
        cout << "The " << bitIndex << "-th bit of " << num << " is not set (0)." << endl;
    }

    return 0;
}