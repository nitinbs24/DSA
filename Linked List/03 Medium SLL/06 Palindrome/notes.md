# Problem: Palindrome Linked List

## Problem Statement
Given the `head` of a singly linked list, return `true` if it is a palindrome or `false` otherwise.

**Link:** https://leetcode.com/problems/palindrome-linked-list/
**Difficulty:** Easy
**Topic:** Linked List, Two Pointers, Stack

---

## Approach

### Approach 1 (Using Stack - Brute Force)
A simple approach is to use a stack since it follows Last-In-First-Out (LIFO) semantics, effectively reversing the data.
1. Initialize an empty `stack`.
2. Traverse the entire linked list and push every node's value onto the stack.
3. Once fully traversed, the top of the stack will hold the last node's value. 
4. Reset a pointer back to the `head` of the list. Iterate through the list again. At each step, compare the node's value with the value popped from the stack.
5. If a mismatch occurs, return `false`. If the traversal completes with all matches, return `true`.

### Approach 2 (Optimal: Find Middle & Reverse Half)
This approach cleverly modifies the linked list in place to achieve O(1) space complexity.
1. **Find Middle:** Use the Tortoise and Hare algorithm (`slow` and `fast` pointers) to find the middle of the linked list. When `fast` reaches the end, `slow` will be at the middle.
2. **Reverse Second Half:** Reverse the second half of the linked list starting from the node immediately after the middle (`slow->next`). Keep track of this reversed list's head (`newHead`).
3. **Compare Halves:** Setup one pointer at the start of the list (`first = head`) and another at the start of the reversed half (`second = newHead`). Iterate and compare their values. If any pair doesn't match, it's not a palindrome.
4. **Restore List:** As a good practice, reverse the second half back to its original state so the input structure is preserved.
5. Return the result.

---

## Code

### Approach 1: Stack (`solution1.cpp`)
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

bool isPalindrome(Node* head) {
    stack<int> st;
    Node* temp = head;

    while (temp != NULL) {
        st.push(temp->data);
        temp = temp->next;
    }

    temp = head;
    while (temp != NULL) {
        if (temp->data != st.top()) {
            return false;
        }
        st.pop();
        temp = temp->next;
    }

    return true;
}
```

### Approach 2: Optimal Two-Pointer (`solution2.cpp`)
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

Node* reverseLinkedList(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    Node* newHead = reverseLinkedList(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}

bool isPalindrome(Node* head) {
    if (head == NULL || head->next == NULL) {
        return true;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* newHead = reverseLinkedList(slow->next);
    Node* first = head;
    Node* second = newHead;

    while (second != NULL) {
        if (first->data != second->data) {
            reverseLinkedList(newHead);
            return false;
        }
        first = first->next;
        second = second->next;
    }

    reverseLinkedList(newHead);
    return true;
}
```

---

## Output
**Input:** 1 -> 5 -> 2 -> 5 -> 1
**Output:** The linked list is a palindrome.

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Approach 1 (Stack) | O(2N) ≈ O(N) | O(N) |
| Approach 2 (Two Pointers) | O(N) | O(1) |

*(where N is the number of nodes in the linked list. Finding the middle takes N/2, reversing takes N/2, and comparison takes N/2 steps, summing to O(N) time for the optimal approach).*

---

## Key Takeaway
For linked lists, since we cannot iterate backwards like in an array, the optimal pattern to check symmetry involves finding the exact midpoint, reversing the latter half in-place, and stepping through both halves simultaneously.
