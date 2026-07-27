#include<iostream>
using namespace std;

string remover(string& str){
    string result="";
    int level=0;
    
    for(char ch:str){
        if(ch=='('){
            if(level>0) result+=ch;
            level++;
        }
        else if (ch==')'){
            level--;
            if(level>0) result+=ch;
        }
    }
    return result;
}

int main(){
    string str="((()))";
    cout<<remover(str)<<endl;
}