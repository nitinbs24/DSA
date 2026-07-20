# Problem: Armstrong Number

## Problem Statement
Check if a number is an Armstrong number. An Armstrong number (like 153) is a number that is equal to the sum of its own digits each raised to the power of the number of digits.

**Difficulty:** Easy  
**Topic:** Basic Math

---

## Approach
**Optimal Approach:** First, determine the number of digits in the number (let's call it `k`). Then, iterate through each digit of the number using modulo 10. Raise the extracted digit to the power of `k` and add it to a running sum. After processing all digits, if the sum equals the original number, it's an Armstrong number.

---

## Code
```cpp
#include <bits/stdc++.h>
using namespace std;

class ArmstrongChecker {
public:
    static bool isArmstrong(int num) {
        int k = to_string(num).length();
        int sum = 0;
        int n = num;

        while (n > 0) {
            int ld = n % 10;
            sum += pow(ld, k);
            n /= 10;
        }

        return sum == num;
    }
};

int main() {
    int number = 153;

    if (ArmstrongChecker::isArmstrong(number)) {
        cout << number << " is an Armstrong number." << endl;
    } else {
        cout << number << " is not an Armstrong number." << endl;
    }

    return 0;
}
```

---

## Output
**Sample Output:**
```
153 is an Armstrong number.
```

---

## Complexity
| | Time | Space |
|---|---|---|
| Optimal | O(log₁₀(N)) | O(1) |

---

## Key Takeaway
Combine digit extraction (`% 10` and `/ 10`) with `pow()` for mathematical validation on each digit.
