# Problem: Diameter of Binary Tree

## Problem Statement
Given the `root` of a binary tree, return the length of the **diameter** of the tree.

The **diameter** of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root. The length of a path between two nodes is represented by the number of edges between them.

**Link:** https://leetcode.com/problems/diameter-of-binary-tree/  
**Difficulty:** Easy  
**Topic:** Binary Trees, DFS, Recursion

---

## Approach

### Approach 1: Brute Force (Top-Down - O(N²))
The diameter of a binary tree can be viewed as the maximum value of `leftHeight + rightHeight` across all nodes in the tree.
1. At each node:
   - Calculate the height of the left subtree: `lh = getHeight(node->left)`.
   - Calculate the height of the right subtree: `rh = getHeight(node->right)`.
   - The diameter passing through this node is `lh + rh`.
2. Recursively find the diameter of the left and right subtrees.
3. Return `max({lh + rh, diameter(node->left), diameter(node->right)})`.

> **Downside:** For every node, `getHeight` traverses all its subtrees. In a skewed tree, this recalculation leads to an $O(N^2)$ time complexity.

---

### Approach 2: Bottom-Up Postorder (Optimal - O(N))
Instead of calculating the height separately for every node from the top down, we can compute the diameter **simultaneously** while calculating the subtree heights in a single bottom-up postorder traversal:
1. Initialize a variable `diameter = 0` (or pass by reference).
2. For each node during DFS postorder traversal:
   - Recursively compute the left subtree height: `leftHeight = calculateHeight(node->left)`.
   - Recursively compute the right subtree height: `rightHeight = calculateHeight(node->right)`.
   - The longest path passing through the current node as the turning point is `leftHeight + rightHeight`.
   - Update the global maximum: `diameter = max(diameter, leftHeight + rightHeight)`.
   - Return the height of the current node to its parent: `1 + max(leftHeight, rightHeight)`.
3. After the traversal finishes, `diameter` holds the maximum diameter in the entire tree.

---

## Code

### Approach 1: Brute Force (Top-Down O(N²))
```cpp
class SolutionBruteForce {
public:
    int getHeight(Node* root) {
        if (root == nullptr) return 0;
        return 1 + max(getHeight(root->left), getHeight(root->right));
    }

    int diameterOfBinaryTree(Node* root) {
        if (root == nullptr) return 0;

        // Longest path passing through current node
        int currentDiameter = getHeight(root->left) + getHeight(root->right);

        // Max diameter in left and right subtrees
        int leftDiameter = diameterOfBinaryTree(root->left);
        int rightDiameter = diameterOfBinaryTree(root->right);

        return max(currentDiameter, max(leftDiameter, rightDiameter));
    }
};
```

### Approach 2: Optimal Bottom-Up O(N) (From `solution.cpp`)
```cpp
#include <iostream>
#include <algorithm>

using namespace std;

// Node structure for
// the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;
    // Constructor to initialize
    // the node with a value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Global variable to
    // store the diameter
    int diameter = 0;  

    // Function to calculate
    // the height of a subtree
    int calculateHeight(Node* node) {
        if (node == nullptr) {
            return 0;
        }

        // Recursively calculate the
        // height of left and right subtrees
        int leftHeight = calculateHeight(node->left);
        int rightHeight = calculateHeight(node->right);

        // Calculate the diameter at the current
        // node and update the global variable
        diameter = max(diameter, leftHeight + rightHeight);

        // Return the height
        // of the current subtree
        return 1 + max(leftHeight, rightHeight);
    }

    // Function to find the
    // diameter of a binary tree
    int diameterOfBinaryTree(Node* root) {
        // Start the recursive
        // traversal from the root
        calculateHeight(root);

        // Return the maximum diameter
        // found during traversal
        return diameter;
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

    // Calculate the diameter of the binary tree
    int diameter = solution.diameterOfBinaryTree(root);

    cout << "The diameter of the binary tree is: " << diameter << endl;

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
*(Longest path between node 7 and node 3: `7 → 6 → 5 → 2 → 1 → 3`, length = 5 edges)*

**Console Output:**
```
The diameter of the binary tree is: 5
```

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Approach 1 (Top-Down Brute Force) | O(N²) | O(H) |
| Approach 2 (Bottom-Up Optimal) | O(N) | O(H) |

*where $N$ is the number of nodes in the binary tree and $H$ is the height of the tree ($O(\log N)$ for balanced trees, $O(N)$ for skewed trees due to recursion stack).*

---

## Key Takeaway
At any node $u$, the longest path that uses $u$ as its highest turning point has length equal to $\text{height}(u.\text{left}) + \text{height}(u.\text{right})$. By updating the maximum diameter during the bottom-up height computation (postorder traversal), we avoid redundant height calculations and achieve an optimal $O(N)$ time complexity.
