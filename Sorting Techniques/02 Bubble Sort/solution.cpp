#include<iostream>
#include<utility>
#include<vector>
using namespace std;


void bubbleSort(vector<int>& arr){
    int n=arr.size();
    for (int i = 0; i < n - 1; i++) {
    bool didSwap = false; 
    
    // Notice the boundary is now (n - i - 1)
    for (int j = 0; j < n - i - 1; j++) {
        if (arr[j] > arr[j + 1]) {
            swap(arr[j], arr[j + 1]);  
            didSwap = true;
        }
    }
    
    if (!didSwap) {
        break;
    }
}
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

    bubbleSort(arr);

    for(auto it: arr) cout<<it<<" ";

    cout<<"\n";
}