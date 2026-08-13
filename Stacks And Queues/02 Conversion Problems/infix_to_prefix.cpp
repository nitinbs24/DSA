#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

int prec(char c){
    if (c=='^') return 3;
    else if(c=='/' || c=='*') return 2;
    else if(c=='+' || c=='-') return 1;
    else return -1;
}

void infixToPrefix(string exp){

    reverse(exp.begin(),exp.end());
    for(int i=0;i<exp.size();i++){
        if(exp[i]==')') exp[i]='(';
        else if(exp[i]=='(') exp[i]=')';
    }
    string result="";
    stack<char> st;
    for(char c:exp){
        if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9')) result+=c;
        else if (c=='(') st.push(c);
        else if(c==')'){
            while(st.top()!='('){
                result+=st.top();
                st.pop();
            }
            st.pop();
        }
        else {
            while(!st.empty() && (prec(c)<prec(st.top()) || (c == '^' && prec(c) == prec(st.top())))){
                result+=st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while(!st.empty()){
        result+=st.top();
        st.pop();
    }

    reverse(result.begin(),result.end());
    cout<<"Ans:"<<result<<endl;
}

int main() {
    string exp = "(p+q)*(m-n)";
    cout << "Infix expression: " << exp << endl;
    infixToPrefix(exp);
    return 0;
} 