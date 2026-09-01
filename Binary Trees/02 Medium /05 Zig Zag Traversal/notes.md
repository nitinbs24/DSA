# Problem: Binary Tree Zigzag Level Order Traversal

## Problem Statement
Given the `root` of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

**Link:** [LeetCode - Binary Tree Zigzag Level Order Traversal](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/)  
**Difficulty:** Medium  
**Topic:** Binary Trees / BFS

---

## Approach

### Optimal Approach: Breadth First Search (BFS) with Direction Flag

1. **Standard BFS Traversal:**
   - Use a `queue<TreeNode*>` to perform a level order traversal of the binary tree.
   - Start by pushing the `root` node into the queue (if `root` is not `nullptr`).

2. **Direction Flag:**
   - Maintain a boolean flag `leftToRight = true` to keep track of the traversal direction for the current level.

3. **Level Processing with Direct Indexing:**
   - For each level, determine the number of nodes currently in the queue (`int size = q.size()`).
   - Create a vector `level` of pre-allocated size `size`.
   - Process all `size` nodes of the current level:
     - Pop the front node from the queue.
     - Determine the position in `level` to place the node's value:
       - If `leftToRight` is `true`, place it at index `i`.
       - If `leftToRight` is `false`, place it at index `size - 1 - i` (filling from right to left).
     - Push the non-null left and right children into the queue for the next level.
   - Toggle the direction flag (`leftToRight = !leftToRight`) after processing the level.
   - Append the `level` vector to the `result`.

4. **Return:**
   - Return the 2D vector `result` containing the zigzag level order traversal.

---

## Code
```cpp
#include <bits/stdc++.h>
using namespace std;

// Structure to represent a binary tree node
struct TreeNode {
    int val;                // Value of the node
    TreeNode* left;         // Pointer to left child
    TreeNode* right;        // Pointer to right child
    // Constructor to initialize node with a given value
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Function to perform zigzag (spiral) level order traversal of a binary tree
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // Vector to store the final zigzag traversal result
        vector<vector<int>> result;
        // If the tree is empty, return an empty result
        if (!root) return result;

        // Queue to store nodes level by level (BFS)
        queue<TreeNode*> q;
        q.push(root);

        // Boolean flag to control traversal direction: true for left-to-right, false for right-to-left
        bool leftToRight = true;

        // Loop until all levels are processed
        while (!q.empty()) {
            // Get the number of nodes at the current level
            int size = q.size();

            // Temporary vector to store the current level's values in correct zigzag order
            vector<int> level(size);

            // Process each node in the current level
            for (int i = 0; i < size; i++) {
                // Get the front node from the queue
                TreeNode* node = q.front();
                q.pop();

                // Determine index where this node's value should be placed based on traversal direction
                int index = leftToRight ? i : size - 1 - i;
                level[index] = node->val;

                // If left child exists, add it to the queue
                if (node->left) q.push(node->left);
                // If right child exists, add it to the queue
                if (node->right) q.push(node->right);
            }

            // After finishing this level, toggle the direction for the next level
            leftToRight = !leftToRight;

            // Add this level's data to the final result
            result.push_back(level);
        }

        // Return the zigzag traversal result
        return result;
    }
};

int main() {
    // Create binary tree:
    //        1
    //      /   \
    //     2     3
    //    / \     \
    //   4   5     6
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    // Create Solution object
    Solution sol;

    // Get zigzag traversal result
    vector<vector<int>> ans = sol.zigzagLevelOrder(root);

    // Print result in desired format
    cout << "[";
    for (auto &level : ans) {
        cout << "[";
        for (int i = 0; i < level.size(); i++) {
            cout << level[i];
            if (i != level.size() - 1) cout << ", ";
        }
        cout << "]";
    }
    cout << "]" << endl;

    return 0;
}
```

---

## Output

### Example:
**Input Tree:**
```text
        1
      /   \
     2     3
    / \     \
   4   5     6
```

**Level Breakdown:**
- Level 0 (Left $\to$ Right): `[1]`
- Level 1 (Right $\to$ Left): `[3, 2]`
- Level 2 (Left $\to$ Right): `[4, 5, 6]`

**Output:**
```text
[[1][3, 2][4, 5, 6]]
```

---

## Complexity

| Approach | Time | Space |
|---|---|---|
| BFS with Index Placement (Optimal) | O(N) | O(N) |

- **Time Complexity:** $O(N)$ where $N$ is the total number of nodes in the binary tree since each node is visited and processed once.
- **Space Complexity:** $O(N)$ for the queue (at most the maximum width of the tree, which is up to $N/2$) and the output array.

---

## Key Takeaway
Instead of reversing level vectors after a standard BFS traversal (which incurs extra overhead), pre-allocate each level vector and directly write elements at index `i` or `size - 1 - i` based on a toggled direction flag.
