# Problem: Middle of the Linked List

## Problem Statement
Given the head of a singly linked list, return the middle node of the linked list. If there are two middle nodes, return the second middle node.

**Link:** https://leetcode.com/problems/middle-of-the-linked-list/
**Difficulty:** Easy
**Topic:** Linked List, Two Pointers

---

## Approach

### Optimal Approach (Tortoise and Hare Algorithm)
This problem can be efficiently solved using the slow and fast pointer technique. 
1. Initialize two pointers, `slow` and `fast`, both pointing to the `head` of the list.
2. Traverse the list such that `slow` moves one step (`slow = slow->next`) and `fast` moves two steps (`fast = fast->next->next`) per iteration.
3. Because `fast` is moving at twice the speed of `slow`, by the time `fast` reaches the end of the list (or steps out of bounds), `slow` will have traveled exactly half the distance, landing right on the middle node.
4. For odd-length lists, the loop terminates when `fast->next` is `NULL`. For even-length lists, the loop terminates when `fast` itself is `NULL`. In both cases, returning `slow` yields the correct middle node (specifically the second middle node in even-length lists).

---

## Code
```cpp
#include <iostream>
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

Node *findMiddle(Node *head) {
    Node *slow = head; 
    Node *fast = head; 

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next; 
        fast = fast->next->next; 
    }

    return slow; 
}
```

---

## Output
**Input 1:** 1 -> 2 -> 3 -> 4 -> 5
**Output 1:** 3

**Input 2:** 1 -> 2 -> 3 -> 4 -> 5 -> 6
**Output 2:** 4

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Optimal (Tortoise and Hare) | O(N/2) ≈ O(N) | O(1) |

*(where N is the number of nodes in the linked list)*

---

## Key Takeaway
The slow and fast pointer (Tortoise and Hare) technique is a fundamental pattern for linked list problems, highly effective for finding midpoints, detecting cycles, or determining intersections in a single pass with O(1) space.
