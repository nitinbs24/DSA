# Problem: Delete the Middle Node of a Linked List

## Problem Statement
You are given the `head` of a linked list. Delete the middle node, and return the `head` of the modified linked list.

The middle node of a linked list of size `n` is the `⌊n / 2⌋`th node from the start using 0-based indexing. (For example, if `n = 5`, the middle node is the 2nd node. If `n = 6`, the middle node is the 3rd node).

**Link:** https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
**Difficulty:** Medium
**Topic:** Linked List, Two Pointers

---

## Approach

### Optimal Approach (Modified Tortoise and Hare)
To delete a node in a singly linked list, you must have access to the node *immediately before* the one you want to delete. Therefore, instead of finding the exact middle node, we modify the two-pointer technique to find the node right before the middle.
1. **Base Case:** If the list is empty or has only one node, deleting the middle node empties the list. We delete the `head` and return `nullptr`.
2. Initialize the `slow` pointer to the `head`.
3. Initialize the `fast` pointer two steps ahead: `fast = head->next->next`.
4. Traverse the list: move `slow` by one step and `fast` by two steps as long as `fast` and `fast->next` are not `nullptr`.
5. **Why this works:** By giving the `fast` pointer a two-step head start, the `slow` pointer will end up pointing to the node exactly *one step before* the middle node when `fast` reaches the end.
6. Now that `slow` points to the node before the middle, we store the middle node: `middle = slow->next`.
7. Bypass the middle node: `slow->next = slow->next->next`.
8. Delete the `middle` node to prevent memory leaks and return the original `head`.

---

## Code

```cpp
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

Node* deleteMiddle(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        delete head;
        return nullptr;
    }

    Node* slow = head;
    Node* fast = head->next->next;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* middle = slow->next;
    slow->next = slow->next->next;
    delete middle;

    return head;
}
```

---

## Output
**Input:** 1 -> 2 -> 3 -> 4 -> 5
**Output:** 1 2 4 5

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Optimal (Tortoise and Hare) | O(N) | O(1) |

*(where N is the number of nodes. We traverse the list exactly once in O(N/2) steps, utilizing constant extra space).*

---

## Key Takeaway
When you need to delete or modify a specific node (like the middle node) in a singly linked list, you actually need a pointer to the node *before* it. You can achieve this with the Tortoise and Hare approach by giving the `fast` pointer a head start, or by starting both pointers at the head and keeping track of a `prev` node during traversal.
