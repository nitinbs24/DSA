#include<iostream>
#include <utility>
#include<vector>
using namespace std;

int partition(vector<int>& arr, int low, int high){
    int pivot=arr[high];

    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);

    return i + 1;
}
void quickSort(vector<int>& arr,int low, int high){
    
    if(low<high){
        int pivot = partition(arr, low, high);

        quickSort(arr, low, pivot - 1);

        quickSort(arr, pivot+1, high);
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

    quickSort(arr,0,arr.size()-1);

    for(auto it: arr) cout<<it<<" ";

    cout<<"\n";
}