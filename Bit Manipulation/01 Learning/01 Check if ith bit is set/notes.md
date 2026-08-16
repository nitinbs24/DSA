# Problem: Check if i-th Bit is Set

## Problem Statement
Given an integer `num` and a 0-based bit position `i`, check whether the `i`-th bit (from the right/LSB) of `num` is set (i.e., equals `1`) or not.

**Link:** [GeeksforGeeks - Check K-th Bit is Set or Not](https://www.geeksforgeeks.org/problems/check-whether-k-th-bit-is-set-or-not-1587115620/1)  
**Difficulty:** Easy  
**Topic:** Bit Manipulation

---

## Approach

### Approach 1: Brute Force (Decimal to Binary String Conversion)
Convert the number to its binary representation by repeatedly taking modulo 2 (`num % 2`) and dividing by 2 (`num / 2`). The generated string naturally stores the LSB at index `0`, the 1st bit at index `1`, and so on. We check if index `i` exists within the string boundary and whether `binary[i] == '1'`.

### Approach 2: Optimal (Bitwise Left Shift / Bitwise AND)
Use bitwise operations to check the bit directly in O(1) time:
1. Create a bitmask by left-shifting `1` by `i` positions: `(1 << i)`. This creates a binary number with only the `i`-th bit set to `1`.
2. Perform a bitwise AND between `num` and `(1 << i)`: `num & (1 << i)`.
3. If the result is non-zero (`!= 0`), the `i`-th bit is set (`1`). Otherwise, it is not set (`0`).

*(Note: Alternatively, right-shifting `num` by `i` positions and masking with `1`, i.e., `(num >> i) & 1`, yields `1` if set and `0` if not set).*

---

## Code

### Approach 1 (Brute Force - Binary Conversion)
```cpp
#include<iostream>
using namespace std;

bool checkIthBit(int num,int i){
    string binary="";
    while(num>0){
        binary+=(num%2==0)?"0":"1";
        num=num/2;
    }
    if(i>=binary.size()) return false;

    return (binary[i]=='1');
}
int main() {
    int num = 5;
    int bitIndex = 2;

    if (checkIthBit(num, bitIndex)) {
        cout << "The " << bitIndex << "-th bit of " << num << " is set (1)." << endl;
    } else {
        cout << "The " << bitIndex << "-th bit of " << num << " is not set (0)." << endl;
    }

    return 0;
}
```

### Approach 2 (Optimal - Bitwise Operators)
```cpp
#include<iostream>
using namespace std;

bool checkIthBit(int num,int i){
    return (num&(1<<i))!=0;
}
int main() {
    int num = 5;
    int bitIndex = 2;

    if (checkIthBit(num, bitIndex)) {
        cout << "The " << bitIndex << "-th bit of " << num << " is set (1)." << endl;
    } else {
        cout << "The " << bitIndex << "-th bit of " << num << " is not set (0)." << endl;
    }

    return 0;
}
```

---

## Output
```
Input: num = 5, bitIndex = 2
Output: The 2-th bit of 5 is set (1).
```

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Approach 1 (Brute Force) | O(log₂ N) | O(log₂ N) |
| Approach 2 (Optimal) | O(1) | O(1) |

---

## Key Takeaway
To check if the i-th bit is set in O(1) time, use `(num & (1 << i)) != 0` or `((num >> i) & 1) != 0`.
