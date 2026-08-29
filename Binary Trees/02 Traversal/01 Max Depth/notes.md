# Problem: Maximum Depth of Binary Tree

## Problem Statement
Given the `root` of a binary tree, return its maximum depth. A binary tree's **maximum depth** (or height) is the number of nodes along the longest path from the root node down to the farthest leaf node.

**Link:** https://leetcode.com/problems/maximum-depth-of-binary-tree/  
**Difficulty:** Easy  
**Topic:** Binary Trees, DFS, Recursion

---

## Approach

### Approach: Recursive Postorder / Divide and Conquer (Optimal)
The maximum depth of a binary tree rooted at `root` can be broken down into subproblems:
1. **Base Case:** If `root` is `NULL`, the depth is `0`.
2. **Subtree Depths:**
   - Recursively calculate the maximum depth of the left subtree: `lh = maxDepth(root->left)`.
   - Recursively calculate the maximum depth of the right subtree: `rh = maxDepth(root->right)`.
3. **Combine:** The maximum depth at the current node is `1 + max(lh, rh)` (1 accounts for the current node itself).

This follows a **postorder traversal pattern** (Left → Right → Root / Bottom-Up evaluation) because we compute the depths of child subtrees first before computing the answer for the current root.

---

## Code
```cpp
#include <bits/stdc++.h>
using namespace std;

// Node structure for the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;
    // Constructor to initialize
    // the node with a value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution{
public:
    // Function to find the
    // maximum depth of a binary tree
    int maxDepth(Node* root){
        // If the root is NULL
        // (empty tree), depth is 0
        if(root == NULL){
            return 0;
        }
        
        // Recursive call to find the
        // maximum depth of the left subtree
        int lh = maxDepth(root->left);
        
        // Recursive call to find the
        // maximum depth of the right subtree
        int rh = maxDepth(root->right);
        
        // Return the maximum depth of the
        // tree, adding 1 for the current node
        return 1 + max(lh, rh);
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
    
    Solution solution;
    int depth = solution.maxDepth(root);

    cout << "Maximum depth of the binary tree: " << depth << endl;

    return 0;
}
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
*(Longest path: 1 → 2 → 5 → 6 → 7, length = 5)*

**Console Output:**
```
Maximum depth of the binary tree: 5
```

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Recursive DFS (Optimal) | O(N) | O(H) |

*where $N$ is the number of nodes in the binary tree and $H$ is the height of the tree ($O(\log N)$ for balanced trees, $O(N)$ for skewed trees due to recursive call stack).*

---

## Key Takeaway
The height of any binary tree node is `1 + max(height(left), height(right))`. This bottom-up postorder structure forms the foundational building block for many tree problems (e.g., Balanced Binary Tree, Diameter of Binary Tree).
