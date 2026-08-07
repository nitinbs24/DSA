# Problem: Find length of Loop

## Problem Statement
Given a linked list, check whether it contains a loop. If a loop is present, return the count of nodes in the loop. Otherwise, return `0`.

**Link:** https://www.geeksforgeeks.org/problems/find-length-of-loop/1
**Difficulty:** Easy
**Topic:** Linked List, Two Pointers, Hash Table

---

## Approach

### Approach 1 (Using Hash Map / Hashing)
We can use a hash map to keep track of the nodes we have already visited and the exact "step" or "count" at which we visited them.
1. Initialize an `unordered_map<Node*, int> freq` to store nodes and an integer `count = 0`.
2. Traverse the linked list. For each node:
   - Check if the node already exists in the hash map.
   - If it does, we have found the loop. The length of the loop is simply `count - freq[temp]` (the difference between the current step count and the step count when the node was first visited). Return this value.
   - Otherwise, store the node with its `count` in the map, increment `count`, and move to the next node.
3. If the traversal reaches a `nullptr`, there is no loop. Return `0`.

### Approach 2 (Optimal: Tortoise and Hare Algorithm)
This approach finds the loop length using O(1) space.
1. **Detect Cycle:** Initialize two pointers, `slow` and `fast`, both pointing to the `head` of the list. Move `slow` by one step and `fast` by two steps. 
2. If `fast` or `fast->next` becomes `NULL`, there is no cycle (return `0`).
3. **Calculate Length:** If `slow` and `fast` meet, it indicates a cycle exists. To find the length:
   - Keep a `temp` pointer at the meeting point.
   - Initialize a `length` counter to `1`.
   - Move `temp` forward one step at a time, incrementing `length`, until `temp->next` reaches the meeting point again.
   - Return the `length`.

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
    int lengthOfLoop(Node* head) {
        unordered_map<Node*, int> visitedNodes;
        Node* temp = head;
        int timer = 0;

        while (temp != NULL) {
            if (visitedNodes.find(temp) != visitedNodes.end()) {
                int loopLength = timer - visitedNodes[temp];
                return loopLength;
            }

            visitedNodes[temp] = timer;
            temp = temp->next;
            timer++;
        }

        return 0;
    }
};
```

### Approach 2: Optimal Tortoise and Hare (`solution2.cpp`)
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
    int lengthOfLoop(Node* head) {
        Node* slow = head;
        Node* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return countLoopLength(slow);
            }
        }
        return 0;
    }

    int countLoopLength(Node* meetingPoint) {
        Node* temp = meetingPoint;
        int length = 1;

        while (temp->next != meetingPoint) {
            temp = temp->next;
            length++;
        }
        return length;
    }
};
```

---

## Output
**Input:** 1 -> 2 -> 3 -> 4 -> 5 -> (points back to 2)
**Output:** Length of the loop: 4

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Approach 1 (Hashing) | O(N) | O(N) |
| Approach 2 (Tortoise and Hare) | O(N) | O(1) |

*(where N is the number of nodes in the linked list. The hash map stores at most N nodes, requiring O(N) space. The two-pointer approach uses constant extra memory)*

---

## Key Takeaway
The Tortoise and Hare algorithm provides an elegant, O(1) space solution to find a cycle's length. Once the slow and fast pointers meet inside the loop, iterating one pointer around the loop back to the meeting point gives the exact loop length.
