# Problem: Quick Sort

## Problem Statement
Given an array of integers, sort it in ascending order using the Quick Sort algorithm.

**Link:** N/A  
**Difficulty:** Medium  
**Topic:** Sorting Techniques

---

## Approach
Quick Sort is a Divide and Conquer algorithm. It relies on a `partition` function that:
1. Picks a `pivot` element (e.g., the last element).
2. Rearranges the array such that all elements smaller than or equal to the pivot are placed to its left, and all greater elements are placed to its right.
3. Returns the final sorted position (index) of the pivot.

The main `quickSort` function then recursively calls itself on the left sub-array (elements before the pivot) and the right sub-array (elements after the pivot).

---

## Code
```cpp
#include<iostream>
#include <utility>
#include<vector>
using namespace std;

int partition(vector<int>& arr, int low, int high){
    int pivot = arr[high];
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

        // Pivot is correctly placed, recurse for left and right
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
| Average Case | O(N log N) | O(log N) |
| Worst Case | O(N^2) | O(N) |

---

## Key Takeaway
Quick Sort is highly efficient in practice because its inner loop is very tight and it does not require auxiliary array space like Merge Sort. However, if poorly pivoted (e.g., already sorted array with highest/lowest element chosen), it degrades to $O(N^2)$ time.
