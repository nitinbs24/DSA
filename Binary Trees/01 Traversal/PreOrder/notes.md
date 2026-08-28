# Problem: Binary Tree Preorder Traversal

## Problem Statement
Given the `root` of a binary tree, return the preorder traversal of its nodes' values. In Preorder traversal, nodes are visited in the order: **Root → Left Subtree → Right Subtree**.

**Link:** https://leetcode.com/problems/binary-tree-preorder-traversal/  
**Difficulty:** Easy  
**Topic:** Binary Trees, DFS, Recursion

---

## Approach

### Approach 1: Recursive DFS (Implemented)
In a preorder traversal, we process the current node before traversing its subtrees:
1. **Base Case:** If the current node (`root`) is `NULL` (`nullptr`), return immediately.
2. **Process Current Node (Root):** Add `root->data` to the result vector `arr`.
3. **Traverse Left Subtree:** Recursively call `preorder(root->left, arr)`.
4. **Traverse Right Subtree:** Recursively call `preorder(root->right, arr)`.

---

## Code
```cpp
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void preorder(Node* root, vector<int> &arr){
        if(root == nullptr){
            return;
        }

        // 1. Visit Root
        arr.push_back(root->data);

        // 2. Visit Left Subtree
        preorder(root->left, arr);

        // 3. Visit Right Subtree
        preorder(root->right, arr);
    }

    vector<int> preOrder(Node* root){
        vector<int> arr;
        preorder(root, arr);
        return arr;
    }
};

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution sol;

    vector<int> result = sol.preOrder(root);

    cout << "Preorder Traversal: ";
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
Preorder Traversal: 1 2 4 5 3 
```

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Approach 1 (Recursive DFS) | O(N) | O(H) |

*where $N$ is the number of nodes in the binary tree and $H$ is the height of the tree ($O(\log N)$ for balanced trees, $O(N)$ for skewed trees due to recursive call stack).*

---

## Key Takeaway
Preorder traversal visits the **Root node first**, followed by the entire **Left subtree**, and finally the **Right subtree** (`Root → Left → Right`).
