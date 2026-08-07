# Problem: Reverse Linked List

## Problem Statement
Given the `head` of a singly linked list, reverse the list, and return the reversed list.

**Link:** https://leetcode.com/problems/reverse-linked-list/
**Difficulty:** Easy
**Topic:** Linked List, Recursion

---

## Approach

### Approach 1 (Iterative)
The iterative approach uses three pointers to reverse the list in-place:
1. Initialize `prev = NULL` and `temp = head`.
2. Traverse the list using `temp`. Inside the loop:
   - First, temporarily store the next node (`front = temp->next`) so we don't lose the rest of the list.
   - Reverse the current node's pointer to point backwards (`temp->next = prev`).
   - Shift the pointers forward for the next iteration: `prev = temp`, then `temp = front`.
3. When the loop ends (`temp` is `NULL`), `prev` will be pointing to the last node of the original list, which is the new head of the reversed list.

### Approach 2 (Recursive)
The recursive approach leverages the call stack to go to the end of the list and reverse the links as it unwinds:
1. **Base Case:** If `head` is `NULL` or `head->next` is `NULL`, return `head`. This base case returns the last node of the list, which will become the new head.
2. **Recursive Step:** Recursively call `reverseList(head->next)` and store the result in `newNode`. This `newNode` is the new head of the reversed portion.
3. **Reversing Links:** As the recursion unwinds, we take the node next to the current `head` (which is `head->next`) and make it point back to `head` (`head->next->next = head`).
4. **Break Original Link:** Set `head->next = NULL` to break the original forward link and prevent a cycle.
5. Return the `newNode` back up the call stack.

---

## Code

### Iterative Solution (`solution1.cpp`)
```cpp
#include <bits/stdc++.h>
using namespace std;

class ListNode {
    public:
    int val;
    ListNode* next;

    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

class Solution {
    public:
    ListNode* reverseList(ListNode* head){
        ListNode* prev=NULL;
        ListNode* temp=head;

        while(temp!=NULL){
            ListNode* front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }
};
```

### Recursive Solution (`solution2.cpp`)
```cpp
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;

        ListNode* newNode=reverseList(head->next);

        ListNode* front=head->next;
        front->next=head;
        head->next=NULL;

        return newNode;
    }
};
```

---

## Output
**Input:** 1 -> 2 -> 3 -> 4 -> 5
**Output:** 5 4 3 2 1

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Approach 1 (Iterative) | O(N) | O(1) |
| Approach 2 (Recursive) | O(N) | O(N) |

*(where N is the number of nodes in the linked list. The recursive space complexity is due to the recursion call stack)*

---

## Key Takeaway
Reversing a linked list iteratively involves tracking three nodes (previous, current, and next) to safely reverse the links without losing access to the remainder of the list. The recursive approach elegantly relies on the call stack to reach the end before unwinding to reverse links, though it uses O(N) auxiliary space.
