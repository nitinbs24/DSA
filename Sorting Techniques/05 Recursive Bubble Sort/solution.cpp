#include<iostream>
#include<utility>
#include<vector>
using namespace std;


void bubbleSort(vector<int>& arr,int n){
    
    if (n==1) return;

    bool didSwap = false; 
    
    // Notice the boundary is now (n - i - 1)
    for (int j = 0; j <= n-2 ; j++) {
        if (arr[j] > arr[j + 1]) {
            swap(arr[j], arr[j + 1]);  
            didSwap = true;
        }
    }
    
    if (!didSwap) return;

    bubbleSort(arr, n-1);
}

int main(){
    vector<int> arr;
    int n,num;
    cout<<"Enter Size: ";
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>num;
        arr.push_back(num);

    }

    bubbleSort(arr,n);

    for(auto it: arr) cout<<it<<" ";

    cout<<"\n";
}