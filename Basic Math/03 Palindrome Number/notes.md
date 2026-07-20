# Problem: Palindrome Number

## Problem Statement
Check if a given number reads the same forwards and backwards.

**Difficulty:** Easy  
**Topic:** Basic Math

---

## Approach
**Optimal Approach:** Reverse the entire number using the standard digit extraction technique (modulo 10 and divide by 10). After calculating the reversed number, simply compare it with the original number. If they are equal, it's a palindrome.

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
    int num,rev_num;
    cout<<"Enter number: ";
    cin>>num;

    rev_num=reverseNumber(num);
    if(rev_num==num) cout<<"Palindrome\n";
    else cout<<"Not Palindrome\n";
}
```

---

## Output
**Sample Input:**
```
Enter number: 121
```
**Sample Output:**
```
Palindrome
```

---

## Complexity
| | Time | Space |
|---|---|---|
| Optimal | O(log₁₀(N)) | O(1) |

---

## Key Takeaway
A palindrome number problem can be reduced to a "Reverse a Number" problem.
