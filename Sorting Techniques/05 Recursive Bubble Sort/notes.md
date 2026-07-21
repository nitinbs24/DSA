# Problem: Recursive Bubble Sort

## Problem Statement
Given an array of integers, sort it in ascending order using a recursive approach of the Bubble Sort algorithm.

**Link:** N/A  
**Difficulty:** Easy  
**Topic:** Sorting Techniques

---

## Approach
Instead of an outer loop that runs from `0` to `n-1`, we can use recursion to manage the boundary of the unsorted portion. 
- In each recursive call for size `n`, we loop through the array to push the largest element to the end.
- If no swaps are made during this pass (`didSwap` is false), the array is completely sorted, and we return.
- Otherwise, we recursively call the function for size `n-1`, ignoring the last element which is now in its correct position.

---

## Code
```cpp
#include<iostream>
#include<utility>
#include<vector>
using namespace std;

void bubbleSort(vector<int>& arr,int n){
    if (n==1) return;

    bool didSwap = false; 
    
    // Notice the boundary is now (n - 2) because we access arr[j+1]
    for (int j = 0; j <= n-2 ; j++) {
        if (arr[j] > arr[j + 1]) {
            swap(arr[j], arr[j + 1]);  
            didSwap = true;
        }
    }
    
    if (!didSwap) return;

    bubbleSort(arr, n-1);
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

    bubbleSort(arr,n);

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
| Worst/Average Case | O(N^2) | O(N) auxiliary stack space |
| Best Case (Sorted) | O(N) | O(1) auxiliary stack space |

---

## Key Takeaway
While recursion makes the structure elegant, the recursive version of Bubble Sort introduces $O(N)$ extra space complexity due to the recursion stack. It is primarily an exercise in understanding recursive transformations.
