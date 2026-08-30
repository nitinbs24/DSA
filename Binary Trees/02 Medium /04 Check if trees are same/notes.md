# Problem: Same Tree (Check if Two Binary Trees are Identical)

## Problem Statement
Given the roots of two binary trees `node1` and `node2`, write a function to check if they are the same or not.

Two binary trees are considered **identical** if they are structurally identical, and the corresponding nodes have the same value.

**Link:** https://leetcode.com/problems/same-tree/  
**Difficulty:** Easy  
**Topic:** Binary Trees, DFS, Recursion

---

## Approach

### Approach 1: Recursive Preorder Traversal (Simultaneous DFS - Optimal)
We traverse both trees simultaneously in a preorder (Root → Left → Right) fashion:

1. **Base Cases:**
   - **Both nodes are `NULL`:** Both branches have terminated simultaneously without mismatch $\rightarrow$ return `true`.
   - **One node is `NULL` and the other is not:** Structural mismatch $\rightarrow$ return `false`.
2. **Current Node & Subtree Validation:**
   - Check if current values match: `node1->data == node2->data`.
   - Recursively check if the left subtrees are identical: `isIdentical(node1->left, node2->left)`.
   - Recursively check if the right subtrees are identical: `isIdentical(node1->right, node2->right)`.
3. **Combine:** Return `true` if and only if all three conditions are satisfied (`&&`).

---

### Approach 2: Iterative BFS (Level Order with Queue)
Instead of recursion, use a queue to traverse both trees level by level:
1. Push `{root1, root2}` into a queue.
2. While the queue is not empty:
   - Pop `{n1, n2}`.
   - If both are `NULL`, continue.
   - If one is `NULL` or `n1->data != n2->data`, return `false`.
   - Push `{n1->left, n2->left}` and `{n1->right, n2->right}` into the queue.
3. If the queue becomes empty without finding any discrepancy, return `true`.

---

## Code

### Approach 1: Recursive DFS (Code from `solution.cpp`)
```cpp
#include <bits/stdc++.h>
using namespace std;

// Node structure for the binary tree
struct Node {
    int data;       // Data stored in the node
    Node* left;     // Pointer to the left child
    Node* right;    // Pointer to the right child

    // Constructor to initialize the node with a value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Function to check if two binary trees are identical
    bool isIdentical(Node* node1, Node* node2) {
        // Case 1: If both nodes are NULL, they are identical
        if (node1 == NULL && node2 == NULL) {
            return true;
        }
        
        // Case 2: If only one of the nodes is NULL, they are not identical
        if (node1 == NULL || node2 == NULL) {
            return false;
        }

        // Check if the current nodes have the same data value
        // and recursively check their left and right subtrees
        return ((node1->data == node2->data)
                && isIdentical(node1->left, node2->left)
                && isIdentical(node1->right, node2->right));
    }
};

int main() {
    // Creating the first binary tree (Node1)
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);

    // Creating the second binary tree (Node2)
    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);

    // Creating an instance of the Solution class
    Solution solution;

    // Check if the two binary trees are identical and output the result
    if (solution.isIdentical(root1, root2)) {
        cout << "The binary trees are identical." << endl;
    } else {
        cout << "The binary trees are not identical." << endl;
    }

    return 0;
}
```

### Approach 2: Iterative BFS (Queue-based)
```cpp
class SolutionIterative {
public:
    bool isIdentical(Node* root1, Node* root2) {
        queue<pair<Node*, Node*>> q;
        q.push({root1, root2});

        while (!q.empty()) {
            auto [n1, n2] = q.front();
            q.pop();

            if (n1 == nullptr && n2 == nullptr) continue;
            if (n1 == nullptr || n2 == nullptr) return false;
            if (n1->data != n2->data) return false;

            q.push({n1->left, n2->left});
            q.push({n1->right, n2->right});
        }

        return true;
    }
};
```

---

## Output
**Input Trees:**

Tree 1 (`root1`):
```
      1
     / \
    2   3
   /
  4
```

Tree 2 (`root2`):
```
      1
     / \
    2   3
   /
  4
```

**Console Output:**
```
The binary trees are identical.
```

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Approach 1 (Recursive DFS) | O(min(N, M)) | O(min(H1, H2)) |
| Approach 2 (Iterative BFS) | O(min(N, M)) | O(min(W1, W2)) |

*where:*
- *$N$ and $M$ are the number of nodes in tree 1 and tree 2 respectively.*
- *$H_1$ and $H_2$ are the heights of tree 1 and tree 2 (space used by the recursion stack: $O(\log N)$ best/balanced case, $O(N)$ worst/skewed case).*
- *$W_1$ and $W_2$ are the maximum widths of the trees (queue memory).*

---

## Key Takeaway
Simultaneous traversal makes comparing two trees straightforward: handle structural base cases (`both NULL` $\rightarrow$ `true`, `one NULL` $\rightarrow$ `false`), compare current node values, and use the boolean `&&` operator to short-circuit immediately if any mismatch is encountered.
