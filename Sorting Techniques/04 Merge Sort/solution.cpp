#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& arr,int low,int mid,int high){
    int left=low,right=mid+1;
    vector<int> temp;

    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]) temp.push_back(arr[left++]);
        else temp.push_back(arr[right++]);
    }

    while(left<=mid) temp.push_back(arr[left++]);

    while(right<=high) temp.push_back(arr[right++]);

    for(int i=low;i<=high;i++) arr[i]=temp[i-low]; 
}
void mergeSort(vector<int>& arr,int low, int high){
    if(low>=high) return;

    int mid=(low+high)/2;
    mergeSort(arr, low, mid);

    mergeSort(arr, mid+1, high);

    merge(arr,low,mid,high);
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

    mergeSort(arr,0,arr.size()-1);

    for(auto it: arr) cout<<it<<" ";

    cout<<"\n";
}