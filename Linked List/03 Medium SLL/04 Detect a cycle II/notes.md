# Problem: Linked List Cycle II

## Problem Statement
Given the `head` of a linked list, return the node where the cycle begins. If there is no cycle, return `null`.
Do not modify the linked list.

**Link:** https://leetcode.com/problems/linked-list-cycle-ii/
**Difficulty:** Medium
**Topic:** Linked List, Two Pointers, Hash Table

---

## Approach

### Approach 1 (Using Hash Set / Hashing)
We can use a hash set to keep track of the nodes we have already visited.
1. Initialize an `unordered_set` to store the memory addresses of the nodes.
2. Traverse the linked list. For each node:
   - Check if the node already exists in the hash set.
   - If it does, we have visited this node before, which means this is the first node of the cycle. Return this node.
   - Otherwise, add the node to the hash set and move to the next node.
3. If the traversal reaches a `null` pointer, it means the list has an end and thus no cycle. Return `null`.

### Approach 2 (Optimal: Tortoise and Hare Algorithm)
This approach finds the starting node using O(1) space. It consists of two phases:
1. **Phase 1 (Detect Cycle):** Initialize two pointers, `slow` and `fast`, both pointing to the `head` of the list. Move `slow` by one step and `fast` by two steps until they meet. If `fast` reaches `null`, there is no cycle (return `null`).
2. **Phase 2 (Find Entry):** When `slow` and `fast` meet, it indicates a cycle exists. To find the start of the cycle:
   - Reset the `slow` pointer back to the `head` of the list.
   - Keep the `fast` pointer at the meeting point.
   - Move both `slow` and `fast` pointers one step at a time. 
   - The exact node where they meet again is guaranteed to be the starting node of the cycle.

---

## Code

### Approach 1: Hashing (`solution1.cpp`)
```cpp
#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        unordered_set<ListNode*> visited;

        while (head != NULL) {
            if (visited.find(head) != visited.end()) {
                return head;
            }
            visited.insert(head);
            head = head->next;
        }
        return NULL;
    }
};
```

### Approach 2: Optimal Tortoise and Hare (`solution2.cpp`)
```cpp
#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};
```

---

## Output
**Input:** 3 -> 2 -> 0 -> -4 -> (points back to 2)
**Output:** Cycle starts at node with value: 2

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Approach 1 (Hashing) | O(N) | O(N) |
| Approach 2 (Tortoise and Hare) | O(N) | O(1) |

*(where N is the number of nodes in the linked list. The hash set takes up O(N) memory, while the two-pointer approach uses constant memory)*

---

## Key Takeaway
Finding the start of a cycle is a classic mathematical property of the Tortoise and Hare algorithm: if a cycle is detected, resetting one pointer to the head and moving both pointers at a speed of 1 step will guarantee they converge exactly at the cycle's entry point.
