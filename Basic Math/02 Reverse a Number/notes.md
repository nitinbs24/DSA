# Problem: Reverse a Number

## Problem Statement
Given an integer `num`, reverse the digits of the number.

**Difficulty:** Easy  
**Topic:** Basic Math

---

## Approach
**Optimal Approach:** Extract the last digit of the number using modulo 10 (`num % 10`). Build the reversed number by multiplying the current reversed number by 10 and adding the extracted digit (`reverse = reverse * 10 + n`). Divide the original number by 10 to remove the last digit. Continue this loop while `num > 0`.

---

## Code
```cpp
#include<iostream>
using namespace std;

int reverseNumber(int num){
    int reverse=0,n;

    while(num>0){
        n=num%10;
        reverse=reverse*10+n;
        num=num/10;
    }
    return reverse;
}

int main(){
    int num;
    cout<<"Enter number: ";
    cin>>num;

    cout<<"Reversed number: "<<reverseNumber(num)<<endl;
}
```

---

## Output
**Sample Input:**
```
Enter number: 1234
```
**Sample Output:**
```
Reversed number: 4321
```

---

## Complexity
| | Time | Space |
|---|---|---|
| Optimal | O(log₁₀(N)) | O(1) |

---

## Key Takeaway
Using modulo (`% 10`) and integer division (`/ 10`) is the standard pattern to extract and manipulate digits of a number from right to left.
