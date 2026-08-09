# Problem: Sort List

## Problem Statement
Given the `head` of a linked list, return the list after sorting it in ascending order.
Can you sort the linked list in `O(n log n)` time and `O(1)` memory (i.e. constant space)?

**Link:** https://leetcode.com/problems/sort-list/
**Difficulty:** Medium
**Topic:** Linked List, Divide and Conquer, Merge Sort, Sorting

---

## Approach

### Optimal Approach (Merge Sort)
Merge Sort is the most efficient sorting algorithm for linked lists. Unlike arrays, linked lists do not have contiguous memory allocations, making Quick Sort less ideal due to the lack of random access. Merge Sort guarantees `O(n log n)` time and works seamlessly with pointer manipulation.
1. **Base Case:** If the list is empty (`head == nullptr`) or has only one node (`head->next == nullptr`), it is already sorted. Return `head`.
2. **Find Middle (Divide):** Use the Tortoise and Hare approach to find the midpoint of the linked list. 
   - *Crucial detail:* Initialize `fast = head->next` instead of `head`. This ensures that in a list with an even number of nodes, `slow` points to the *first* middle node, effectively splitting the list evenly and preventing infinite recursion.
3. **Split:** Disconnect the list into two halves. Let `left = head` and `right = middle->next`. Set `middle->next = nullptr` to break the link.
4. **Conquer:** Recursively call `sortList` on both the `left` and `right` halves.
5. **Merge:** Merge the two sorted halves back together. Use a `dummy` node to simplify the merging process. Iterate through both lists, always appending the smaller node to the `temp` pointer until one list is exhausted. Finally, append the remainder of the non-empty list.

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
    ListNode* findMiddle(ListNode* head){
        // Initialize fast to head->next to handle even length lists correctly
        ListNode* slow = head, *fast = head->next;
        
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* list1, ListNode* list2){
        ListNode dummy(0);
        ListNode* temp = &dummy;
        
        while(list1 != nullptr && list2 != nullptr){
            if(list1->val <= list2->val){
                temp->next = list1;
                list1 = list1->next;
            }
            else {
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }

        // Attach any remaining nodes
        if(list1 != nullptr) {
            temp->next = list1;
        } else {
            temp->next = list2;
        }
        
        return dummy.next;
    }

    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;

        // 1. Find the middle
        ListNode* middle = findMiddle(head);

        // 2. Split the list into two halves
        ListNode* right = middle->next;
        middle->next = nullptr;
        ListNode* left = head;

        // 3. Sort both halves recursively
        left = sortList(left);
        right = sortList(right);

        // 4. Merge the sorted halves
        return merge(left, right);
    }
};
```

---

## Output
**Input:** 4 -> 2 -> 1 -> 3
**Output:** 1 2 3 4

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Optimal (Recursive Merge Sort) | O(N log N) | O(log N) |

*(where N is the number of nodes. The list is divided in half log N times. The merging step takes O(N) at each level. The O(log N) space complexity comes from the recursive call stack. True O(1) space would require a bottom-up iterative merge sort, but the recursive top-down approach is standard and acceptable).*

---

## Key Takeaway
Merge Sort is the go-to sorting algorithm for Linked Lists. The most common pitfall is infinite recursion when dividing the list: always ensure your `findMiddle` function returns the *first* middle node for even-length lists (by setting `fast = head->next`) so the split properly reduces the list size!
