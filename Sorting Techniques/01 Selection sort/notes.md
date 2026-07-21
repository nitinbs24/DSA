# Problem: Selection Sort

## Problem Statement
Given an array of integers, sort it in ascending order using the Selection Sort algorithm.

**Link:** N/A  
**Difficulty:** Easy  
**Topic:** Sorting Techniques

---

## Approach
Selection sort works by repeatedly finding the minimum element from the unsorted part of the array and putting it at the beginning of the unsorted region. 
We maintain two subarrays: the already sorted subarray (at the beginning) and the remaining unsorted subarray. In every iteration, the minimum element from the unsorted subarray is picked and swapped with the first element of the unsorted subarray.

---

## Code
```cpp
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
| All Cases | O(N^2) | O(1) |

---

## Key Takeaway
Selection Sort is simple but inefficient for large datasets. It performs at most $O(N)$ swaps, which makes it useful when memory write operations are costly.
