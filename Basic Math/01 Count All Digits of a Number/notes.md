# Problem: Count All Digits of a Number

## Problem Statement
Count the total number of digits in a given integer.

**Difficulty:** Easy  
**Topic:** Basic Math

---

## Approach
**Brute Force Approach:** Iterate through the number, continually dividing it by 10 (which removes the last digit). Keep a counter that increments by 1 for each division step until the number reaches 0.

**Optimal Approach:** Use the base-10 logarithm. The number of digits in an integer `N` is directly given by the formula `floor(log10(N)) + 1`.

---

## Code
### Optimal Solution
```cpp
#include<iostream>
#include<cmath>

using namespace std;

int countDigits(int dig){
    int count=(int)(log10(dig)+1);

    return count;
}

int main(){
    int dig;
    cout<<"Enter the digit: ";
    cin>>dig;

    cout<<"Digits: "<<countDigits(dig)<<endl;
}
```

---

## Output
**Sample Input:**
```
Enter the digit: 12345
```
**Sample Output:**
```
Digits: 5
```

---

## Complexity
| | Time | Space |
|---|---|---|
| Brute Force | O(log₁₀(N)) | O(1) |
| Optimal | O(1) | O(1) |

---

## Key Takeaway
Logarithmic math (`log10`) can calculate the number of digits in `O(1)` time, making it faster than a loop-based extraction.
