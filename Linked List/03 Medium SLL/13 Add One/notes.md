# Problem: Add 1 to a number represented as linked list

## Problem Statement
Given a linked list where each node represents a single digit of a non-negative integer, add 1 to the integer. The most significant digit comes first and each of their nodes contains a single digit. Add one to it and return the head of the modified linked list.

**Link:** [GeeksforGeeks / LeetCode](https://www.geeksforgeeks.org/add-1-to-a-number-represented-as-linked-list/)  
**Difficulty:** Medium  
**Topic:** Linked List

---

## Approach
### Approach 1 (Optimal) - Reverse, Add, Reverse
Since the least significant digit is at the end of the linked list but we only have forward pointers, the easiest way to perform addition is to reverse the list first.

1. **Reverse the List:** Reverse the entire linked list so that the head points to the least significant digit (the "ones" place).
2. **Add One:** Traverse the reversed list while maintaining a `carry` variable (initialized to `1` because we want to add one).
   - At each node, calculate the sum of the node's current value and the `carry`.
   - Update the node's data to `sum % 10` and the new `carry` to `sum / 10`.
   - If you reach the last node and the `carry` is still `1` (e.g., adding 1 to 999), append a new node with the carry value (`1`) to the end of the list.
3. **Reverse Again:** Reverse the list one more time to restore the original most-significant-digit-first ordering and return the new head.

---

## Code
```cpp
class Solution{
    public:
    Node* reverseList(Node* head){
        Node* prev = nullptr;
        Node* curr = head;
        
        while (curr != nullptr) {
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    Node* addOne(Node* head){
        // Step 1: Reverse the linked list
        head = reverseList(head);

        int carry = 1;
        Node* curr = head;

        // Step 2: Add 1 and process carry
        while (curr && carry) {
            int sum = curr->data + carry;
            curr->data = sum % 10;
            carry = sum / 10;
        
            // If we are at the last node and still have a carry, append a new node
            if (!curr->next && carry) {
                curr->next = new Node(carry);
                carry = 0;
            }
            curr = curr->next;
        }
        
        // Step 3: Reverse the list back to its original order
        head = reverseList(head);
        return head;
    }
};
```

---

## Output
```
Input: 9 -> 9 (represents 99)
Output: 100
```

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Approach 1 (Reverse, Add, Reverse) | O(N) | O(1) |

- **Time Complexity:** O(N). We reverse the list (O(N)), traverse it once to add the carry (O(N)), and reverse it again (O(N)). Overall time is O(N).
- **Space Complexity:** O(1). All modifications are done in-place without using extra memory (excluding the single node added in cases like `99 + 1 = 100`).

---

## Key Takeaway
Whenever you need to process a linked list from the end to the beginning (like standard arithmetic addition), a great strategy is to **reverse the list**, do the processing sequentially from the new head, and then **reverse it back**!
