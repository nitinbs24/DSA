# Problem: Print all Divisors

## Problem Statement
Find and print all the divisors of a given integer `num`.

**Difficulty:** Easy  
**Topic:** Basic Math

---

## Approach
**Optimal Approach:** Instead of iterating from 1 to `num`, iterate from 1 up to the square root of `num`. If `i` is a divisor (`num % i == 0`), add `i` to the list of divisors. Additionally, its counterpart `num / i` is also a divisor, so add that as well. To avoid adding duplicate divisors for perfect squares, ensure `i != num / i` before adding the counterpart.

---

## Code
```cpp
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

vector<int> divisor(int num){
    vector<int> a;
    int N=(int)sqrt(num);
    for(int i=1;i<=N;i++){
        if(num%i==0){
            a.push_back(i);
            if(i != num/i) a.push_back(num/i);
        } 
    }
    return a;
}

int main(){
    int num;
    vector<int> a;
    cout<<"Enter number: ";
    cin>>num;

    cout<<"Divisors:\n";
    a=divisor(num);

    for(auto n:a){
        cout<<n<<"\t";
    }
    cout<<endl;
}
```

---

## Output
**Sample Input:**
```
Enter number: 20
```
**Sample Output:**
```
Divisors:
1       20      2       10      4       5
```

---

## Complexity
| | Time | Space |
|---|---|---|
| Optimal | O(√N) | O(1) (excluding output storage) |

---

## Key Takeaway
Divisors always occur in pairs `(i, num/i)`. Iterating up to `sqrt(num)` significantly reduces the time complexity from `O(N)` to `O(√N)`.
