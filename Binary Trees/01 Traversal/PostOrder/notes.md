# Problem: Binary Tree Postorder Traversal

## Problem Statement
Given the `root` of a binary tree, return the postorder traversal of its nodes' values. In Postorder traversal, nodes are visited in the order: **Left Subtree → Right Subtree → Root**.

**Link:** https://leetcode.com/problems/binary-tree-postorder-traversal/  
**Difficulty:** Easy  
**Topic:** Binary Trees, DFS, Stack, Iterative Traversal

---

## Approach

### Approach: Iterative Traversal Using 2 Stacks (Implemented)
Postorder traversal visits nodes in `Left → Right → Root` order. The reverse of postorder is `Root → Right → Left`. We can use two stacks (`st1` and `st2`) to achieve this iteratively:

1. **Initialize:** If the `root` is `NULL`, return an empty result. Push `root` to `st1`.
2. **Transfer to `st2`:** While `st1` is not empty:
   - Pop the top node from `st1` and push it onto `st2`.
   - Push the node's **left child** to `st1` (if it exists).
   - Push the node's **right child** to `st1` (if it exists).
   *(Since left child is pushed before right child into `st1`, right child will be popped and pushed to `st2` first. Thus, `st2` stores elements in `Root → Right → Left` order).*
3. **Extract Result:** Pop elements from `st2` one by one into the `postorder` array. Because popping from `st2` reverses the order, we get `Left → Right → Root`.

---

## Code
```cpp
#include <bits/stdc++.h>
using namespace std;

// Node structure for the binary tree
struct Node {
    int data;   // Value of the node
    Node* left; // Pointer to the left child
    Node* right; // Pointer to the right child
    
    // Constructor to initialize the node with a value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to return the postOrder traversal of a binary tree using two stacks
vector<int> postOrder(Node* root) {
    vector<int> postorder; // Vector to store the postorder traversal

    // If the tree is empty, return an empty traversal
    if(root == NULL){
        return postorder;
    }

    // Two stacks for iterative traversal
    stack<Node*> st1, st2;

    // Push the root node onto the first stack
    st1.push(root);

    // Iterative traversal to populate st2 with nodes in postorder
    while(!st1.empty()){
        // Get the top node from st1
        root = st1.top();
        st1.pop();

        // Push the node onto st2
        st2.push(root);

        // Push left child onto st1 if exists
        if(root->left != NULL){
            st1.push(root->left);
        }

        // Push right child onto st1 if exists
        if(root->right != NULL){
            st1.push(root->right);
        }
    }

    // Populate the postorder traversal vector by popping st2
    while(!st2.empty()){
        postorder.push_back(st2.top()->data);
        st2.pop();
    }

    // Return the postorder traversal
    return postorder;
}

// Function to print the elements of a vector
void printVector(const vector<int>& vec) {
    // Iterate through the vector and print each element
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

// Main function
int main()
{
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Getting postorder traversal
    vector<int> result = postOrder(root);

    // Printing the postorder traversal result
    cout << "Postorder traversal: ";
    printVector(result);

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
Postorder traversal: 4 5 2 3 1 
```

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Approach 1 (Iterative using 2 Stacks) | O(N) | O(2N) ≈ O(N) |

*where $N$ is the number of nodes in the binary tree. `st1` takes up to $O(H)$ space during traversal, and `st2` holds all $N$ nodes before generating the final output.*

---

## Key Takeaway
Postorder is `Left → Right → Root`, which is the reverse of `Root → Right → Left`. By using a first stack to generate the modified preorder (`Root → Right → Left`) and feeding it into a second stack, popping from the second stack naturally yields the postorder traversal without recursion.
