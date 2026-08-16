# Problem: Left Rotate an Array by One

## Problem Statement
Given an array of integers, left rotate the array by exactly one position. This means the first element of the array should be moved to the last position, and all other elements should be shifted to the left by one index.

**Link:** [GeeksforGeeks](https://www.geeksforgeeks.org/left-rotate-an-array-by-one-element/)  
**Difficulty:** Easy  
**Topic:** Arrays

---

## Approach

### Approach 1: Brute Force (Using Extra Space)
We can create a new temporary array (`temp`). We iterate through the original array starting from the second element (index `1`) and push all elements into `temp`. Finally, we append the first element of the original array (at index `0`) to the end of `temp`. This correctly rotates the array but uses extra space.

### Approach 2: Optimal (In-Place Shift)
To optimize the space complexity, we can perform the rotation in-place:
1. Store the first element of the array in a temporary variable, e.g., `temp = arr[0]`.
2. Iterate through the array starting from index `1` to the end, and shift each element one position to the left by setting `arr[i-1] = arr[i]`.
3. Finally, place the value stored in the `temp` variable at the last index of the array (`arr[arr.size()-1] = temp`).

---

## Code

### Approach 1 (Brute Force)
```cpp
#include<iostream>
#include<vector>
using namespace std;

void rotateLeft(vector<int>& arr){
    vector<int> temp;

    for(int i=1;i<arr.size();i++){
        temp.push_back(arr[i]);
    }
    temp.push_back(arr[0]);

    for(int num:temp){
        cout<<num<<" ";
    }
}

int main(){
    vector<int> arr {1,2,3,4,5};
    rotateLeft(arr);
}
```

### Approach 2 (Optimal)
```cpp
#include<iostream>
#include<vector>
using namespace std;

void rotateLeft(vector<int>& arr){
    int temp=arr[0];

    for(int i=1;i<arr.size();i++){
        arr[i-1]=arr[i];
    }
    arr[arr.size()-1]=temp;

    for(int num:arr){
        cout<<num<<" ";
    }
}

int main(){
    vector<int> arr {1,2,3,4,5};
    rotateLeft(arr);
}
```

---

## Output
```
Input: arr = [1, 2, 3, 4, 5]
Output: 2 3 4 5 1
```

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Approach 1 (Brute Force) | O(N) | O(N) |
| Approach 2 (Optimal) | O(N) | O(1) |

---

## Key Takeaway
Array elements can be shifted in-place by storing the out-of-bounds element (in this case, the first element) in a temporary variable and sliding the remaining elements over in a single pass.
