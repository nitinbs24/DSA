#include<iostream>
#include<utility>
#include<vector>
using namespace std;


void insertionSort(vector<int>& arr,int i,int n){
    
    if (i==n) return;
    int j=i;        
    while(j>0 && arr[j-1]>arr[j]){
        swap(arr[j],arr[j-1]);
        j--;
    }

    insertionSort(arr, i+1 , n);
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

    insertionSort(arr,0,n);

    for(auto it: arr) cout<<it<<" ";

    cout<<"\n";
}