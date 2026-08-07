# Problem: Linked List Cycle

## Problem Statement
Given the `head` of a linked list, determine if the linked list has a cycle in it.
A cycle exists in a linked list if there is some node in the list that can be reached again by continuously following the `next` pointer.

**Link:** https://leetcode.com/problems/linked-list-cycle/
**Difficulty:** Easy
**Topic:** Linked List, Two Pointers, Hash Table

---

## Approach

### Approach 1 (Using Hash Map / Hashing)
We can use a hash map to keep track of the nodes we have already visited.
1. Initialize an `unordered_map` to store the memory addresses of the nodes.
2. Traverse the linked list. For each node:
   - Check if the node already exists in the hash map.
   - If it does, we have visited this node before, which means there is a cycle. Return `true`.
   - Otherwise, add the node to the hash map and move to the next node.
3. If the traversal reaches a `null` pointer, it means the list has an end and thus no cycle. Return `false`.

### Approach 2 (Optimal: Tortoise and Hare Algorithm)
This is a much more space-efficient approach that uses two pointers moving at different speeds.
1. Initialize two pointers, `slow` and `fast`, both pointing to the `head` of the list.
2. Traverse the list such that `slow` moves one step (`slow = slow->next`) and `fast` moves two steps (`fast = fast->next->next`).
3. If the list has a cycle, the `fast` pointer will eventually lap the `slow` pointer, and they will meet at the exact same node (`slow == fast`). At this point, return `true`.
4. If there is no cycle, the `fast` pointer will reach the end of the list (i.e., `fast` or `fast->next` becomes `null`). Return `false`.

---

## Code

### Approach 1: Hashing (`solution1.cpp`)
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

class Solution {
public:
    bool detectLoop(Node* head) {
        Node* temp = head;
        unordered_map<Node*, int> nodeMap;

        while (temp != nullptr) {
            if (nodeMap.find(temp) != nodeMap.end()) {
                return true;
            }
            nodeMap[temp] = 1;
            temp = temp->next;
        }

        return false;
    }
};
```

### Approach 2: Tortoise and Hare (`solution2.cpp`)
```cpp
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int data1) : val(data1), next(NULL) {}
    ListNode(int data1, ListNode *next1) : val(data1), next(next1) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return true;
            }
        }

        return false;
    }
};
```

---

## Output
**Input:** 1 -> 2 -> 3 -> 4 -> 5 -> (points back to 3)
**Output:** Loop detected in the linked list.

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Approach 1 (Hashing) | O(N) | O(N) |
| Approach 2 (Tortoise and Hare) | O(N) | O(1) |

*(where N is the number of nodes in the linked list. The map operations take O(1) on average, resulting in overall O(N) time for hashing)*

---

## Key Takeaway
The Tortoise and Hare algorithm is the definitive method for cycle detection in a linked list. It brings the space complexity down to O(1) while maintaining O(N) time complexity, outperforming the hashing method which requires O(N) extra space.
