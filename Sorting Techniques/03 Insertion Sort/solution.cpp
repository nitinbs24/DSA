#include<iostream>
#include<vector>
using namespace std;


void insertionSort(vector<int>& arr){
    int n=arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j=i-1;
        
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
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

    insertionSort(arr);

    for(auto it: arr) cout<<it<<" ";

    cout<<"\n";
}