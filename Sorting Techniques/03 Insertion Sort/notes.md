# Problem: Insertion Sort

## Problem Statement
Given an array of integers, sort it in ascending order using the Insertion Sort algorithm.

**Link:** N/A  
**Difficulty:** Easy  
**Topic:** Sorting Techniques

---

## Approach
Insertion sort builds the final sorted array one item at a time. It assumes the first element is already sorted. Then it takes the next element and inserts it into its correct position in the already sorted part by shifting elements that are larger than the current element one position to the right.

---

## Code
```cpp
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
| Worst/Average Case | O(N^2) | O(1) |
| Best Case (Sorted) | O(N) | O(1) |

---

## Key Takeaway
Insertion Sort is highly efficient for small data sets and works extremely well for arrays that are mostly sorted (or "almost sorted").
