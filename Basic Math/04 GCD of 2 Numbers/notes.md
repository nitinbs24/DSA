# Problem: GCD of 2 Numbers

## Problem Statement
Find the Greatest Common Divisor (GCD) or Highest Common Factor (HCF) of two numbers `a` and `b`.

**Difficulty:** Easy / Medium  
**Topic:** Basic Math

---

## Approach
**Brute Force Approach:** Iterate from the minimum of the two numbers down to 1. The first number that divides both `a` and `b` cleanly (with modulo 0) is the GCD.

**Optimal Approach (Euclidean Algorithm):** Keep replacing the larger number with the remainder of the larger divided by the smaller. In code, `a = a % b` or `b = b % a` depending on which is larger. Continue this until one of them becomes 0. The non-zero number is the GCD.

---

## Code
### Optimal Solution
```cpp
#include<iostream>
using namespace std;

int GCD(int a,int b){
    while(a>0 && b>0){
        if(a>b) a=a%b;
        else b=b%a;
    }
    if(a==0) return b;
    return a;
}

int main(){
    int a,b;
    cout<<"Enter 2 numbers: ";
    cin>>a>>b;

    cout<<"GCD of "<<a<<" and "<<b<<" is:"<<GCD(a,b)<<endl;
}
```

---

## Output
**Sample Input:**
```
Enter 2 numbers: 12 18
```
**Sample Output:**
```
GCD of 12 and 18 is:6
```

---

## Complexity
| | Time | Space |
|---|---|---|
| Brute Force | O(min(a, b)) | O(1) |
| Optimal | O(log(min(a, b))) | O(1) |

---

## Key Takeaway
The Euclidean algorithm is extremely efficient and operates in logarithmic time, making it the standard approach for finding the GCD.
