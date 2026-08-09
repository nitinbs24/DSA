# Problem: Sort 0s 1s and 2s

## Problem Statement
Given a linked list of `0`s, `1`s, and `2`s, sort it in ascending order. 

**Link:** [GeeksforGeeks](https://www.geeksforgeeks.org/sort-a-linked-list-of-0s-1s-or-2s/) (Standard Problem)
**Difficulty:** Medium  
**Topic:** Linked List

---

## Approach
### Approach 1 (Optimal) - Dummy Nodes
Instead of modifying the values of the nodes (which is often discouraged in linked list problems as the actual data could be complex objects), we can rearrange the pointers. 

1. Create three dummy nodes: `zeroDummy`, `oneDummy`, and `twoDummy`. 
2. Maintain three tail pointers: `zeroTail`, `oneTail`, and `twoTail`, all initially pointing to their respective dummy nodes.
3. Traverse the original linked list. Depending on the value of the current node (`0`, `1`, or `2`), append the node to the respective list and move the corresponding tail pointer forward.
4. After traversing the list, connect the three lists:
   - Link the end of the `0`s list (`zeroTail->next`) to the start of the `1`s list. If the `1`s list is empty, link it to the start of the `2`s list.
   - Link the end of the `1`s list (`oneTail->next`) to the start of the `2`s list.
   - Set the end of the `2`s list (`twoTail->next`) to `nullptr` to terminate the list properly.
5. Store the head of the newly combined list (`zeroDummy->next`).
6. Finally, free the allocated dummy nodes to prevent memory leaks and return the new head.

---

## Code
```cpp
class Solution{
    public:
    Node* counter(Node* head){
        Node* zeroDummy=new Node(-1);
        Node* oneDummy=new Node(-1);
        Node* twoDummy=new Node(-1);

        Node* zeroTail=zeroDummy;
        Node* oneTail=oneDummy;
        Node* twoTail=twoDummy;

        Node* curr=head;

        while(curr!=nullptr){
            if(curr->data==0){
                zeroTail->next=curr;
                zeroTail=zeroTail->next;
            }
            else if(curr->data==1){
                oneTail->next=curr;
                oneTail=oneTail->next;
            }
            else {
                twoTail->next=curr;
                twoTail=twoTail->next;
            }
            curr=curr->next;
        }
        zeroTail->next=oneDummy->next?oneDummy->next:twoDummy->next;
        oneTail->next=twoDummy->next;
        twoTail->next=nullptr;
        
        Node* newHead = zeroDummy->next;
        
        delete zeroDummy; // Cleaning up dummy nodes
        delete oneDummy;
        delete twoDummy;

        return newHead;
    }
};
```
*(Note: The code above includes cleanup for all three dummy nodes.)*

---

## Output
```
Before:
0 1 2 0 1 2 
After:
0 0 1 1 2 2 
```

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Approach 1 (Optimal) | O(N) | O(1) |

- **Time Complexity:** O(N), as we are traversing the linked list of length N exactly once.
- **Space Complexity:** O(1), since we are only using a few dummy nodes and pointers to rearrange the existing nodes in place.

---

## Key Takeaway
Using dummy nodes significantly simplifies pointer manipulation and gracefully handles edge cases, such as when one of the sublists (like `0`s or `1`s) is empty. When rearranging linked lists, always ensure to re-link correctly and properly terminate the list!
