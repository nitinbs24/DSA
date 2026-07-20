# Problem: Check for Prime Number

## Problem Statement
Determine if a given number `n` is a prime number. A prime number has exactly two factors: 1 and itself.

**Difficulty:** Easy  
**Topic:** Basic Math

---

## Approach
**Optimal Approach:** Iterate from 1 up to the square root of the number. Count the total number of divisors by checking if `n % i == 0`. When a divisor `i` is found, increment the count, and if its counterpart `n / i` is distinct (`n / i != i`), increment the count again. Finally, if the total divisor count is exactly 2, the number is prime.

---

## Code
```cpp
#include <bits/stdc++.h>
using namespace std;

bool checkPrime(int n) {
    int cnt = 0;

    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            cnt++;

            if (n / i != i) {
                cnt++;
            }
        }
    }
    if (cnt == 2) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int n = 1483;
    bool isPrime = checkPrime(n);

    if (isPrime) {
        cout << n << " is a prime number." << endl;
    } else {
        cout << n << " is not a prime number." << endl;
    }

    return 0;
}
```

---

## Output
**Sample Output:**
```
1483 is a prime number.
```

---

## Complexity
| | Time | Space |
|---|---|---|
| Optimal | O(√N) | O(1) |

---

## Key Takeaway
Prime checking uses the exact same `O(√N)` logic as finding all divisors. A number is prime if and only if its total number of divisors is exactly 2.
