# Problem: Check if a Binary Tree is Height-Balanced

## Problem Statement
Given a binary tree, determine if it is **height-balanced**. A height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differs by more than one (`|height(left) - height(right)| <= 1`).

**Link:** https://leetcode.com/problems/balanced-binary-tree/  
**Difficulty:** Easy  
**Topic:** Binary Trees, DFS, Recursion

---

## Approach

### Approach 1: Top-Down Recursion (Brute Force - Implemented)
For every node in the binary tree:
1. Calculate the height of the left subtree (`leftHeight = getHeight(root->left)`).
2. Calculate the height of the right subtree (`rightHeight = getHeight(root->right)`).
3. If `|leftHeight - rightHeight| <= 1` and both left and right subtrees are balanced recursively (`isBalanced(root->left) && isBalanced(root->right)`), return `true`.
4. Otherwise, return `false`.

> **Downside:** For every node visited by `isBalanced`, `getHeight` traverses all descendant nodes. This redundant recalculation of subtree heights leads to an $O(N^2)$ worst-case time complexity.

---

### Approach 2: Bottom-Up Postorder (Optimal - O(N))
Instead of calculating height repeatedly from the top down, compute the height **bottom-up**:
1. At each node, compute the height of the left and right subtrees.
2. If any subtree is unbalanced (returns `-1`), propagate `-1` immediately upwards.
3. If `|leftHeight - rightHeight| > 1`, return `-1` to signal unbalance.
4. Otherwise, return the true height `1 + max(leftHeight, rightHeight)`.
5. The tree is balanced if the root's check does not return `-1`.

---

## Code

### Approach 1: Top-Down (Code from `solution.cpp`)
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
    // Function to check if a binary tree is balanced
    bool isBalanced(Node* root) {
        // If the tree is empty, it's balanced
        if (root == nullptr) {
            return true;
        }

        // Calculate the height of left and right subtrees
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);

        // Check if the absolute difference in heights
        // of left and right subtrees is <= 1
        if (abs(leftHeight - rightHeight) <= 1 &&
            isBalanced(root->left) &&  // Recursively check the left subtree
            isBalanced(root->right)) { // Recursively check the right subtree
            return true;
        }

        // If any condition fails, the tree is unbalanced
        return false;
    }

    // Function to calculate the height of a subtree
    int getHeight(Node* root) {
        // Base case: if the current node is NULL,
        // return 0 (height of an empty tree)
        if (root == nullptr) {
            return 0;
        }

        // Recursively calculate the height of left and right subtrees
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);

        // Return the maximum height of left and right subtrees
        // plus 1 (to account for the current node)
        return max(leftHeight, rightHeight) + 1;
    }
};

// Main function
int main() {
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->left->right->right->right = new Node(7);

    // Creating an instance of the Solution class
    Solution solution;

    // Checking if the tree is balanced
    if (solution.isBalanced(root)) {
        cout << "The tree is balanced." << endl;
    } else {
        cout << "The tree is not balanced." << endl;
    }

    return 0;
}
```

### Approach 2: Optimal Bottom-Up O(N)
```cpp
class SolutionOptimal {
public:
    int checkHeight(Node* root) {
        if (root == nullptr) return 0;

        int leftHeight = checkHeight(root->left);
        if (leftHeight == -1) return -1; // Left subtree is unbalanced

        int rightHeight = checkHeight(root->right);
        if (rightHeight == -1) return -1; // Right subtree is unbalanced

        if (abs(leftHeight - rightHeight) > 1) return -1; // Current node is unbalanced

        return 1 + max(leftHeight, rightHeight);
    }

    bool isBalanced(Node* root) {
        return checkHeight(root) != -1;
    }
};
```

---

## Output
**Input Tree:**
```
        1
       / \
      2   3
     / \
    4   5
         \
          6
           \
            7
```
*(Left subtree of root has height 4, right subtree has height 1 → difference = 3 > 1)*

**Console Output:**
```
The tree is not balanced.
```

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Approach 1 (Top-Down Brute Force) | O(N²) | O(H) |
| Approach 2 (Bottom-Up Optimal) | O(N) | O(H) |

*where $N$ is the number of nodes and $H$ is the height of the tree ($O(\log N)$ for balanced trees, $O(N)$ for skewed trees).*

---

## Key Takeaway
Top-down height calculations lead to redundant work ($O(N^2)$). By evaluating balance **bottom-up** during the postorder height computation and returning a sentinel value (`-1`) on imbalance, we reduce the complexity to a single pass ($O(N)$).
