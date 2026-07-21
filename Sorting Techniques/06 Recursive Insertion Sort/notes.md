# Problem: Recursive Insertion Sort

## Problem Statement
Given an array of integers, sort it in ascending order using a recursive approach of the Insertion Sort algorithm.

**Link:** N/A  
**Difficulty:** Easy  
**Topic:** Sorting Techniques

---

## Approach
Instead of an outer loop that iterates from `1` to `n`, we use recursion to handle each element one by one.
- The function receives the current index `i` (starting from `0`) and the array size `n`.
- Base case: If `i == n`, we have processed the entire array, so we return.
- Otherwise, we take the element at index `i` and swap it backwards into its correct sorted position within the `0` to `i` portion.
- Finally, we recursively call the function for index `i+1`.

---

## Code
```cpp
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
| Best Case (Sorted) | O(N) | O(N) auxiliary stack space |

---

## Key Takeaway
The recursive version of Insertion Sort simulates the loop iterations using recursive calls. Like Recursive Bubble Sort, this requires $O(N)$ extra memory for the call stack, making the iterative approach practically superior.
