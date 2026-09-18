# Problem: Best Time to Buy and Sell Stock

## Problem Statement
You are given an array `prices` where `prices[i]` is the price of a given stock on the `i`th day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return `0`.

**Link:** [LeetCode 121 - Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)  
**Difficulty:** Medium (LeetCode: Easy)  
**Topic:** Arrays, Dynamic Programming

---

## Approach

### Approach 1: Brute Force (Nested Loops)
We try all possible pairs of buy and sell days.
- Use an outer loop with index `i` from `0` to `n-1` representing the day we buy the stock.
- Use an inner loop with index `j` from `i+1` to `n-1` representing the day we sell the stock.
- Calculate the profit as `prices[j] - prices[i]`.
- Keep track of the maximum profit found across all pairs.
- If no profitable trade exists, the maximum profit remains `0`.
- **Drawback:** Requires comparing every pair, taking $O(N^2)$ time, which leads to Time Limit Exceeded (TLE) for large inputs.

### Approach 2: Linear Traversal (Optimal / One Pass)
We can find the maximum profit in a single pass ($O(N)$) by keeping track of the minimum price encountered so far.
- Maintain two variables: `minPrice` (initialized to `INT_MAX`) and `maxProfit` (initialized to `0`).
- Iterate through the `prices` array:
  - If the current price `prices[i]` is strictly less than `minPrice`, update `minPrice = prices[i]` (buying at a lower price allows for greater profit opportunities later).
  - Otherwise, evaluate selling on the current day: calculate profit `prices[i] - minPrice`. If this profit exceeds `maxProfit`, update `maxProfit`.
- This guarantees that when considering a sale on any given day, we always pair it with the lowest buying price seen up to that point.

---

## Code

### Solution 1: Brute Force
```cpp
#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int>& prices){
    int n=prices.size(),maxProfit=0;

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int profit=prices[j]-prices[i];

            maxProfit=max(maxProfit,profit);
        }
    }
    return maxProfit;
}

int main(){
    vector<int> prices={7, 1, 5, 3, 6, 4};

    cout<<maxProfit(prices)<<endl;
}
```

### Solution 2: Optimal (One Pass)
```cpp
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int maxProfit(vector<int>& prices){
    int n=prices.size(),minPrice=INT_MAX,maxProfit=0;

    for(int i=0;i<n;i++){
        if(prices[i]<minPrice) minPrice=prices[i];
        else if(prices[i]-minPrice>maxProfit) maxProfit=prices[i]-minPrice;
    }
    return maxProfit;
}

int main(){
    vector<int> prices={7, 1, 5, 3, 6, 4};

    cout<<maxProfit(prices)<<endl;
}
```

---

## Output

**Sample Input:**
```
prices = [7, 1, 5, 3, 6, 4]
```

**Sample Output:**
```
5
```
*(Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6 - 1 = 5. Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.)*

**Sample Input 2:**
```
prices = [7, 6, 4, 3, 1]
```

**Sample Output 2:**
```
0
```
*(Explanation: In this case, no transactions are done and the max profit = 0 since prices decrease monotonically.)*

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Approach 1 (Brute Force) | O(N²) | O(1) |
| Approach 2 (Optimal) | O(N) | O(1) |

---

## Key Takeaway
Instead of re-evaluating past buying points, dynamically track the minimum price seen so far. At every step, the best profit achievable if selling today is `current_price - min_price_so_far`, reducing an $O(N^2)$ search to a single $O(N)$ pass.
