# Problem: Binary Tree Level Order Traversal

## Problem Statement
Given the `root` of a binary tree, return the level order traversal of its nodes' values (i.e., from left to right, level by level).

**Link:** https://leetcode.com/problems/binary-tree-level-order-traversal/  
**Difficulty:** Medium  
**Topic:** Binary Trees, Breadth-First Search (BFS), Queue

---

## Approach

### Approach: Iterative BFS using Queue (Optimal)
Level Order Traversal is inherently a **Breadth-First Search (BFS)** problem. We use a **FIFO queue** to visit nodes level by level:

1. **Edge Case:** If `root` is `NULL`, return an empty result list `ans`.
2. **Initialization:** Push the `root` node to a queue `q`.
3. **Level-by-Level Processing:** While the queue is not empty:
   - Determine `size = q.size()`, which represents the number of nodes at the current level.
   - Loop `size` times:
     - Pop the front node (`node = q.front()`).
     - Add `node->data` to the `level` vector.
     - If `node->left != NULL`, push `node->left` to `q`.
     - If `node->right != NULL`, push `node->right` to `q`.
   - After processing all nodes of the current level, add `level` to `ans`.
4. **Return:** Return `ans` containing vectors for each level.

---

## Code
```cpp
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data1){
        data=data1;
        left=NULL;
        right=NULL;
    }
};

class Solution{
    public:
    vector<vector<int>> levelOrder(Node* root){
        
        vector<vector<int>> ans;

        if(root==NULL) return ans;
        queue<Node*> q;

        q.push(root);

        while(!q.empty()){
            int size=q.size();

            vector<int> level;

            for(int i=0;i<size;i++){
                Node* node=q.front();
                q.pop();

                level.push_back(node->data);

                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
            }

            ans.push_back(level);
        }
        return ans;
    }
};

void printVector(const vector<int>& vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution solution; 

    vector<vector<int>> result = solution.levelOrder(root); 

    cout << "Level Order Traversal of Tree: "<< endl;

    for (const vector<int>& level : result) {
        printVector(level);
    }

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
Level Order Traversal of Tree: 
1 
2 3 
4 5 
```

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Approach 1 (Queue BFS) | O(N) | O(N) |

*where $N$ is the total number of nodes in the binary tree. In the worst case (full/complete binary tree), the queue holds up to $\lceil N/2 \rceil$ nodes at the maximum width level ($O(N)$ space).*

---

## Key Takeaway
By capturing `size = q.size()` before processing a level, we can cleanly separate nodes level-by-level without needing extra delimiter markers or sentinel values (like `NULL`) in the queue.
