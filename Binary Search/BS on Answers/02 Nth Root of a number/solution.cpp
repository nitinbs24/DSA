#include<iostream>
using namespace std;

int myRoot(int n, int x){
    int low=1, high=x;

    while(low<=high){
        int ans=1, mid=(low+high)/2;

        for(int i=0;i<n;i++){
            ans*=mid;
            if(ans>x) break;
        }
        if(ans==x) return mid;
        else if(ans<x) low=mid+1;
        else high=mid-1;

    }
    return -1;
}

int main(){
    int x=27,n=3;
    cout<<myRoot(n,x)<<endl;
}