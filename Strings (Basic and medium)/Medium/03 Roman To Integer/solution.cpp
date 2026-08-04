#include<iostream>
#include<unordered_map>
using namespace std;

int romanToInt(string num){
    unordered_map<char,int> roman ={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
    int res=0;
    for(int i=0;i<num.size()-1;i++){
        if(roman[num[i]]<roman[num[i+1]]) res-=roman[num[i]];
        else res+=roman[num[i]];
    }
    return res+roman[num.back()];
}

int main(){
    string num="III";
    cout<<romanToInt(num)<<endl;
}