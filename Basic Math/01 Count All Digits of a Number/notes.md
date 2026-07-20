# Count All Digits of a Number (Solution 2)

This solution counts the total number of digits in a given number using a mathematical approach with logarithms.

## Logic Explanation
Instead of iterating through the number and dividing it by 10 in a loop (which takes `O(log n)` time complexity), this approach uses the base-10 logarithm to find the answer directly in `O(1)` time complexity.

The mathematical formula used is:
```cpp
count = (int)(log10(number) + 1);
```
- `log10(number)` returns the base-10 logarithm of the number. For example, `log10(100)` is `2`, and `log10(999)` is roughly `2.999`.
- When we add `1` and cast it to an `int`, it correctly gives the exact count of digits in the number.
- For example: `(int)(log10(12345) + 1)` -> `(int)(4.091 + 1)` -> `(int)(5.091)` -> `5`.

## Sample Input / Output

**Sample Input:**
```
Enter the digit: 12345
```

**Sample Output:**
```
Digits: 5
```

**Sample Input:**
```
Enter the digit: 987654321
```

**Sample Output:**
```
Digits: 9
```
