# Problem: Merge Sort

## Problem Statement
Given an array of integers, sort it in ascending order using the Merge Sort algorithm.

**Link:** N/A  
**Difficulty:** Medium  
**Topic:** Sorting Techniques

---

## Approach
Merge Sort is a Divide and Conquer algorithm. It divides the input array into two halves, recursively calls itself for the two halves, and then merges the two sorted halves. 
The `merge()` function assumes the two halves are already sorted and merges them into a single sorted array by using two pointers (`left` and `right`) and a temporary storage array `temp`.

---

## Code
```cpp
#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& arr,int low,int mid,int high){
    int left=low,right=mid+1;
    vector<int> temp;

    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while(left<=mid) {
        temp.push_back(arr[left]);
        left++;
    }

    while(right<=high) {
        temp.push_back(arr[right]);
        right++;
    }

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
```

---

## Output
```
Enter Size: 5
5 4 3 2 1
1 2 3 4 5 
```

---

## Complexity
| | Time | Space |
|---|---|---|
| All Cases | O(N log N) | O(N) |

---

## Key Takeaway
Merge sort guarantees a time complexity of $O(N \log N)$ in all cases (worst, average, and best). However, it requires an extra $O(N)$ space for the temporary array during the merge process.
