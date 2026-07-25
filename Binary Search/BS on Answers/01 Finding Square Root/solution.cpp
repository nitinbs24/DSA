#include<iostream>
using namespace std;

int mySqrt(int x){
    if(x<2) return x;

    int low=1,high=x/2,ans;

    while(low<=high){
        int mid=low+(high-low)/2;

        if(mid*mid<=x){ 
            ans=mid;
            low=mid+1;
        }
        else high=mid-1;
    }
    return ans;
}

int main(){
    int x=16;
    cout<<mySqrt(x)<<endl;
}