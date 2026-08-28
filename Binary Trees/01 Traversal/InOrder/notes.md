# Problem: Binary Tree Inorder Traversal

## Problem Statement
Given the `root` of a binary tree, return the inorder traversal of its nodes' values. In Inorder traversal, nodes are visited in the order: **Left Subtree → Root → Right Subtree**.

**Link:** https://leetcode.com/problems/binary-tree-inorder-traversal/  
**Difficulty:** Easy  
**Topic:** Binary Trees, DFS, Recursion

---

## Approach

### Approach 1: Recursive DFS (Implemented)
In an inorder traversal, we explore the left subtree completely before visiting the current node, and then visit the right subtree:
1. **Base Case:** If the current node (`root`) is `NULL` (`nullptr`), return immediately.
2. **Traverse Left Subtree:** Recursively call `recursiveInorder(root->left, arr)` to process all nodes to the left.
3. **Process Current Node (Root):** Append `root->data` to the result vector `arr`.
4. **Traverse Right Subtree:** Recursively call `recursiveInorder(root->right, arr)` to process all nodes to the right.

---

## Code
```cpp
#include <bits/stdc++.h>
using namespace std;

// TreeNode structure for the binary tree
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    // Constructor to initialize
    // the TreeNode with a value
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution{
    private:
    // Function to perform inorder traversal
    // of the tree and store values in 'arr'
    void recursiveInorder(TreeNode* root, vector<int> &arr){
        // If the current Tree is NULL
        // (base case for recursion), return
        if(root == nullptr){
            return;
        }
        // Recursively traverse the left subtree
        recursiveInorder(root->left, arr);
        // Push the current TreeNode's
        // value into the vector
        arr.push_back(root->data);
        // Recursively traverse 
        // the right subtree
        recursiveInorder(root->right, arr);
    }
    
    public:
    // Function to initiate inorder traversal
    // and return the resulting vector
    vector<int> inorder(TreeNode* root){
        // Create an empty vector to
        // store inorder traversal values
        vector<int> arr;
        // Call the inorder traversal function
        recursiveInorder(root, arr);
        // Return the resulting vector
        // containing inorder traversal values
        return arr;
    }
};

// Main function
int main()
{
    // Creating a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    Solution sol = Solution();
    // Getting inorder traversal
    vector<int> result = sol.inorder(root);

    // Displaying the inorder traversal result
    cout << "Inorder Traversal: ";
    // Output each value in the
    // inorder traversal result
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;

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
```
**Console Output:**
```
Inorder Traversal: 4 2 5 1 3 
```

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Approach 1 (Recursive DFS) | O(N) | O(H) |

*where $N$ is the total number of nodes in the tree, and $H$ is the height of the tree ($O(\log N)$ for balanced binary trees, $O(N)$ for skewed trees due to recursive call stack).*

---

## Key Takeaway
Inorder traversal visits nodes in the sequence **Left → Root → Right**. Notably, performing an inorder traversal on a **Binary Search Tree (BST)** yields the elements in strictly non-decreasing sorted order.
