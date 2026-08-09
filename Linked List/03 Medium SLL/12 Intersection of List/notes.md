# Problem: Intersection of Two Linked Lists

## Problem Statement
Given the heads of two singly linked-lists `head1` and `head2`, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return `null`.

**Link:** [LeetCode 160. Intersection of Two Linked Lists](https://leetcode.com/problems/intersection-of-two-linked-lists/)  
**Difficulty:** Medium  
**Topic:** Linked List

---

## Approach

### Approach 1 (Brute Force)
For every node in the first linked list, traverse the entire second linked list and check if the current node from the first list matches any node in the second list.
- **Why it's slow:** This requires nested traversal resulting in quadratic time complexity.

### Approach 2 (Hashing)
Traverse the first linked list and store all its nodes (the memory addresses, not just values) in a Hash Set. Then traverse the second linked list and for each node, check if it already exists in the set.
- **Why it's better:** It brings the time complexity down to linear time, but uses extra O(N) space for the Hash Set.

### Approach 3 (Length Difference)
1. Find the lengths of both linked lists.
2. Calculate the difference in lengths `diff = |len1 - len2|`.
3. Move the head pointer of the longer list forward by `diff` steps.
4. Now, both head pointers are equidistant from the intersection point (if it exists). Move both pointers one step at a time until they meet.
- **Why it's optimal:** It achieves O(N + M) time complexity with O(1) space, avoiding the extra space needed by hashing.

### Approach 4 (Two Pointers - Most Elegant)
1. Initialize two pointers `d1` and `d2` to the heads of the two lists.
2. Traverse through the lists. When `d1` reaches the end of list 1, redirect it to the head of list 2.
3. Similarly, when `d2` reaches the end of list 2, redirect it to the head of list 1.
4. If there is an intersection, they will eventually meet at the intersection node. If there is no intersection, they will both reach the end (`NULL`) at the exact same time after traversing a total distance of `len1 + len2`.
- **Why it's the best:** It achieves O(N + M) time and O(1) space with a single, elegant loop and without explicitly calculating the lengths of the lists.

---

## Code
```cpp
class Solution {
public:
    node* intersectionPresent(node* head1, node* head2) {
        node* d1 = head1;
        node* d2 = head2;
        
        while (d1 != d2) {
            d1 = d1 == NULL ? head2 : d1->next;
            d2 = d2 == NULL ? head1 : d2->next;
        }
        
        return d1;
    }
};
```

---

## Output
```
List1: 1->3->1->2->4
List2: 3->2->4
The intersection point is 2
```

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Approach 1 (Brute Force) | O(N * M) | O(1) |
| Approach 2 (Hashing) | O(N + M) | O(N) |
| Approach 3 (Length Difference) | O(N + M) | O(1) |
| Approach 4 (Two Pointers) | O(N + M) | O(1) |

*(Where N and M are the lengths of the two linked lists)*

---

## Key Takeaway
The "Two Pointers" swapping approach is a beautiful trick to align two sequences of different lengths without explicitly calculating those lengths. By having each pointer traverse both lists (`List1 + List2`), we guarantee they travel the exact same total distance!
