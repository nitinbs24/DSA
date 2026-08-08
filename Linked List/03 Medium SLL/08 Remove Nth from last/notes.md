# Problem: Remove Nth Node From End of List

## Problem Statement
Given the `head` of a linked list, remove the `n`th node from the end of the list and return its head.

**Link:** https://leetcode.com/problems/remove-nth-node-from-end-of-list/
**Difficulty:** Medium
**Topic:** Linked List, Two Pointers

---

## Approach

### Optimal Approach (One-Pass Two Pointers)
We can remove the Nth node from the end in a single pass using two pointers (`fast` and `slow`) separated by a fixed gap.
1. **Dummy Node:** Create a `dummy` node that points to the `head`. This elegantly handles edge cases, such as when the node to be removed is the very first node in the list.
2. Initialize both `fast` and `slow` pointers to point to the `dummy` node.
3. **Create Gap:** Move the `fast` pointer forward exactly `n + 1` steps. This establishes a gap of `n` nodes between `fast` and `slow`.
4. **Traverse:** Move both `fast` and `slow` pointers forward one step at a time until `fast` reaches `nullptr` (the end of the list).
5. **Delete:** Because of the gap we created, `slow` will now point exactly to the node *immediately preceding* the node we want to delete.
6. Rewire the pointers to skip the target node: `slow->next = slow->next->next`.
7. **Cleanup:** Delete the bypassed node and the `dummy` node to free memory. Return `dummy->next` as the new head of the list.

---

## Code

```cpp
#include <iostream>
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* fast = dummy;
        ListNode* slow = dummy;

        while (n >= 0) {
            fast = fast->next;
            n--;
        }

        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode* toDelete = slow->next;
        slow->next = slow->next->next;
        delete toDelete;
        
        ListNode* newHead = dummy->next;
        delete dummy;
        
        return newHead;
    }
};
```

---

## Output
**Input:** 1 -> 2 -> 3 -> 4 -> 5, n = 2
**Output:** 1 -> 2 -> 3 -> 5

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Optimal (One Pass Two Pointers) | O(N) | O(1) |

*(where N is the number of nodes in the linked list. We traverse the list exactly once with constant extra space).*

---

## Key Takeaway
Using a `dummy` node is a standard linked list trick to gracefully handle deletions at the head. Furthermore, setting two pointers apart by a gap of `n` allows us to locate the end-relative node in a single O(N) traversal.
