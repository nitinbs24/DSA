# Problem: Add Two Numbers

## Problem Statement
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

**Link:** https://leetcode.com/problems/add-two-numbers/
**Difficulty:** Medium
**Topic:** Linked List, Math

---

## Approach
We use a dummy head node to simplify the logic of constructing the resulting linked list. We iterate through both linked lists simultaneously, starting from the head. During each iteration, we add the corresponding digits from `l1` and `l2` along with the `carry` from the previous addition. If one list is shorter, we treat its missing digits as 0. The sum of the digits gives the value for the new node (`sum % 10`), and the carry is updated as `sum / 10`. We continue this process until both lists are exhausted and there is no remaining carry.

---

## Code
```cpp
#include <bits/stdc++.h>
using namespace std;
        
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(); 
        ListNode *temp = dummy; 
        int carry = 0;
        while( (l1 != NULL || l2 != NULL) || carry) {
            int sum = 0; 
            if(l1 != NULL) {
                sum += l1->val; 
                l1 = l1 -> next; 
            }
            if(l2 != NULL) {
                sum += l2 -> val; 
                l2 = l2 -> next; 
            }
            sum += carry; 
            carry = sum / 10; 
            ListNode *node = new ListNode(sum % 10); 
            temp -> next = node; 
            temp = temp -> next; 
        }
        return dummy -> next; 
    }
};

ListNode* createList(vector arr) {
    ListNode *head = new ListNode(arr[0]);
    ListNode *temp = head;
    for (int i = 1; i < arr.size(); i++) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }
    return head;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    vector num1 = {2, 4, 3};
    vector num2 = {5, 6, 4};
    ListNode* l1 = createList(num1);
    ListNode* l2 = createList(num2);

    Solution sol;
    ListNode* result = sol.addTwoNumbers(l1, l2);
    printList(result);
    return 0;
}
```

---

## Output
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Approach 1 (Optimal) | O(max(N, M)) | O(max(N, M)) |

*(N and M are lengths of the two linked lists)*

---

## Key Takeaway
Using a dummy node simplifies linked list construction. Dealing with carry correctly and handling unequal list lengths are key aspects of this elementary math simulation.
