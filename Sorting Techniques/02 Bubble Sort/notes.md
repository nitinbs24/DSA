# Problem: Bubble Sort

## Problem Statement
Given an array of integers, sort it in ascending order using the Bubble Sort algorithm.

**Link:** N/A  
**Difficulty:** Easy  
**Topic:** Sorting Techniques

---

## Approach
Bubble Sort repeatedly steps through the list, compares adjacent elements and swaps them if they are in the wrong order. 
This process is repeated until the list is sorted. The largest element "bubbles" up to the end of the array with each iteration. We optimize this by keeping track of whether a swap happened in an iteration (`didSwap`). If no swaps occurred, the array is already sorted, and we can break out early.

---

## Code
```cpp
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
By adding a boolean flag `didSwap`, Bubble Sort can identify a sorted array in $O(N)$ time, making it adaptive.
