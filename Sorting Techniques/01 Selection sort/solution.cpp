#include<iostream>
#include<utility>
#include<vector>
using namespace std;


void selectionSort(vector<int>& arr){
    int min,size=arr.size();

    for(int i=0;i<size-1;i++){
        min=i;

        for(int j=i+1;j<size;j++){
            if (arr[j]<arr[min]) min=j;
        }

        if(min != i) swap(arr[i],arr[min]);
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

    selectionSort(arr);

    for(auto it: arr) cout<<it<<" ";

    cout<<"\n";
}