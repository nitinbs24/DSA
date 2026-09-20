# Problem: Boundary Traversal of Binary Tree

## Problem Statement
Given the `root` of a Binary Tree, return its **boundary traversal** in the **anti-clockwise** direction starting from the root node.

The boundary traversal consists of the following components visited in order:
1. **Root Node:** Include the root if it is not a leaf node (if the tree has only 1 node, it is the only node in the traversal).
2. **Left Boundary:** The path from the root's left child going downwards, excluding all leaf nodes.
3. **Leaf Nodes:** All leaf nodes from left to right across the entire tree.
4. **Right Boundary:** The path from the bottom-most node back up to the root's right child (i.e. reversed order), excluding all leaf nodes.

**Link:** [GeeksforGeeks - Tree Boundary Traversal](https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1) / [LeetCode 545 - Boundary of Binary Tree](https://leetcode.com/problems/boundary-of-binary-tree/)  
**Difficulty:** Medium  
**Topic:** Binary Trees, DFS, Tree Traversal

---

## Approach

### Modular 3-Stage Traversal (Left Boundary + Leaves + Right Boundary)
To avoid boundary conflicts and duplicates (especially avoiding counting leaf nodes twice or adding the root twice), we decouple the traversal into three independent modular subroutines:

1. **Root Node:**
   - If `root == nullptr`, return an empty result.
   - If `root` is not a leaf (`!isLeaf(root)`), add `root->data` to `ans`.

2. **Left Boundary (`addLeftBoundary`):**
   - Start from `curr = root->left`.
   - While `curr != nullptr`:
     - If `curr` is not a leaf, push `curr->data` to `ans`.
     - Prefer moving left: if `curr->left` exists, move `curr = curr->left`.
     - Otherwise, if `curr->left` is null, move right: `curr = curr->right`.
   - The loop terminates when a leaf node is reached (leaf nodes are handled separately in the next stage).

3. **Leaf Nodes (`addLeafBoundary`):**
   - Perform a simple pre-order/in-order recursive DFS traversal.
   - If the current node is a leaf (`isLeaf(root)`), append `root->data` to `ans` and return.
   - Recurse on `root->left`, then on `root->right`.
   - This naturally visits all leaves strictly in left-to-right order.

4. **Right Boundary (`addRightBoundary`):**
   - Start from `curr = root->right`.
   - We must traverse the right boundary in **bottom-up** order (anti-clockwise).
   - Use a temporary vector/stack `temp`.
   - While `curr != nullptr`:
     - If `curr` is not a leaf, push `curr->data` to `temp`.
     - Prefer moving right: if `curr->right` exists, move `curr = curr->right`.
     - Otherwise, if `curr->right` is null, move left: `curr = curr->left`.
   - Reverse `temp` and append its elements to `ans`.

---

## Code

### Solution: Anti-Clockwise Boundary Traversal
```cpp
#include<iostream>
#include<vector>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val): data(val),left(nullptr),right(nullptr){}
};

class Solution{
    public:
    bool isLeaf(Node* root){
        return !root->left && !root->right;
    }

    void addLeftBoundary(Node* root, vector<int>& ans){
        Node* curr=root->left;

        while(curr){

            if(!isLeaf(curr)) ans.push_back(curr->data);

            if(curr->left) curr=curr->left;
            else curr=curr->right;
        }
    }

    void addRightBoundary(Node* root, vector<int>& ans){
        Node* curr=root->right;
        vector<int> temp;
        while(curr){

            if(!isLeaf(curr)) temp.push_back(curr->data);

            if(curr->right) curr=curr->right;
            else curr=curr->left;
        }

        for(int i=temp.size()-1;i>=0;i--){
            ans.push_back(temp[i]);
        }
    }

    void addLeafBoundary(Node* root, vector<int>& ans){

        if(isLeaf(root)){
            ans.push_back(root->data);
            return;
        } 

        if(root->left) addLeafBoundary(root->left, ans);

        if(root->right) addLeafBoundary(root->right, ans);
    }

    vector<int> printBoundary(Node* root){
        vector<int> ans;
        if(!root){
            return ans;
        }
        if(!isLeaf(root)) ans.push_back(root->data);

        addLeftBoundary(root,ans);
        addLeafBoundary(root,ans);
        addRightBoundary(root,ans);

        return ans;
    }
};

int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);

    Solution sol;

    vector<int> ans = sol.printBoundary(root);

    for(auto num: ans){
        cout<<num<<" ";
    }
    cout<<endl;
}
```

---

## Output

**Sample Tree Structure:**
```
        1
       / \
      2   3
     / \ / \
    4  5 6  7
```

**Sample Output:**
```
1 2 4 5 6 7 3
```
*(Explanation:*
- *Root: 1*
- *Left Boundary (excl. leaves): 2*
- *Leaves (left to right): 4, 5, 6, 7*
- *Right Boundary (bottom to top, excl. leaves): 3*
- *Anti-clockwise result: [1, 2, 4, 5, 6, 7, 3])*

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Optimal (Modular 3-Stage Traversal) | O(N) | O(H) |

*(Where N is the total number of nodes in the binary tree and H is the height of the tree.*
- *Left boundary traversal takes O(H) time.*
- *Leaf nodes DFS visits all nodes, taking O(N) time.*
- *Right boundary traversal takes O(H) time.*
- *Auxiliary space is O(H) for the DFS recursion call stack and the temporary right boundary vector.)*

---

## Key Takeaway
Break boundary traversal into 3 distinct, non-overlapping tasks: **Left Boundary** (top-down, preferring left), **All Leaves** (left-to-right via standard DFS), and **Right Boundary** (bottom-up using temporary stack/reversal, preferring right). Crucially, **exclude leaf nodes** in both left and right boundary functions to guarantee that no node is duplicated.
