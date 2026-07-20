#include<iostream>
using namespace std;

bool palindromeCheck(int i,string name){

    if(i>=name.length()/2) return true;

    if(name[i] != name[name.length()-1-i]) return false;

    return palindromeCheck(i+1, name);

}
int main(){
    string name="nitin";

    cout<<"Is "<<name<<" a palidrome?: "<<palindromeCheck(0,name)<<endl;
}