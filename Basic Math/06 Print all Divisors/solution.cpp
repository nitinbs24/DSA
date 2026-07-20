#include<iostream>
#include<cmath>
#include<vector>
using namespace std;


vector<int> divisor(int num){
    vector<int> a;
    int N=(int)sqrt(num);
    for(int i=1;i<=N;i++){
        if(num%i==0){
            a.push_back(i);
            if(i != num/i) a.push_back(num/i);
        } 
    }
    return a;
}
int main(){
    int num;
    vector<int> a;
    cout<<"Enter number: ";
    cin>>num;

    cout<<"Divisors:\n";
    a=divisor(num);

    for(auto n:a){
        cout<<n<<"\t";
    }
    cout<<endl;
}