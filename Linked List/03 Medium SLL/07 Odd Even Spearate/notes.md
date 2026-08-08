# Problem: Odd Even Linked List

## Problem Statement
Given the `head` of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

**Note:**
- The first node is considered odd, and the second node is even, and so on.
- You must solve the problem in `O(1)` extra space complexity and `O(n)` time complexity.
- The relative order inside both the even and odd groups should remain as it was in the input.

**Link:** https://leetcode.com/problems/odd-even-linked-list/
**Difficulty:** Medium
**Topic:** Linked List, Two Pointers

---

## Approach

### Optimal Approach (In-Place Pointer Manipulation)
We can solve this efficiently by maintaining two separate sub-lists conceptually (one for odd nodes and one for even nodes) and linking them together at the end.
1. Initialize two pointers: `odd` pointing to `head`, and `even` pointing to `head->next`.
2. Keep a reference to the start of the even list (`evenHead = even`) so we can attach it to the end of the odd list later.
3. Traverse the list in a loop as long as `even` and `even->next` are not `NULL`:
   - Connect the current odd node to the next odd node: `odd->next = even->next`
   - Move the `odd` pointer forward: `odd = odd->next`
   - Connect the current even node to the next even node: `even->next = odd->next`
   - Move the `even` pointer forward: `even = even->next`
4. Once the traversal is complete, attach the head of the even list to the tail of the odd list: `odd->next = evenHead`.
5. Return the original `head`.

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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;

        while (even != nullptr && even->next != nullptr) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }

        odd->next = evenHead;

        return head;
    }
};
```

---

## Output
**Input:** 1 -> 2 -> 3 -> 4 -> 5
**Output:** 1 3 5 2 4

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Optimal (In-Place Two Pointers) | O(N) | O(1) |

*(where N is the number of nodes in the linked list. We traverse the list exactly once, only rewiring existing pointers).*

---

## Key Takeaway
For problems requiring rearranging elements based on alternating indices in a linked list, maintaining two separate pointers (`odd` and `even`) and rewiring them simultaneously is an optimal `O(1)` space pattern. Always remember to store the head of the second list (`evenHead`) to merge them back together!
