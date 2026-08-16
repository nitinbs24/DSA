#include<iostream>
using namespace std;

bool checkIthBit(int num,int i){
    return (num&(1<<i))!=0;
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