# Problem: All in One Traversal (Pre, In, Post Order in Single Pass)

## Problem Statement
Given a binary tree, compute all three DFS traversals — **Preorder**, **Inorder**, and **Postorder** — simultaneously in a **single traversal** using an iterative approach.

**Link:** https://www.geeksforgeeks.org/morris-traversal-for-preorder/  
**Difficulty:** Medium  
**Topic:** Binary Trees, Stack, DFS Traversal

---

## Approach

### Optimal — Single Stack with State Tracking

The key insight is to simulate **all three traversals at once** using a stack of `(Node*, state)` pairs, where `state` encodes *when* a node is being visited:

| State | Action |
|---|---|
| `1` | First visit → record in **pre**, increment state to `2`, push back, then push **left child** (state 1) |
| `2` | Second visit → record in **in**, increment state to `3`, push back, then push **right child** (state 1) |
| `3` | Third visit → record in **post**, discard node |

**Why does this work?**
- In preorder, a node is processed the **1st time** it's encountered.
- In inorder, a node is processed **after its left subtree** is done (2nd visit).
- In postorder, a node is processed **after both subtrees** are done (3rd visit).

The stack essentially replaces the recursion call stack, and the state variable replaces the implicit position in the recursive function.

**Step-by-step trace on the sample tree:**
```
        1
       / \
      2   3
     / \
    4   5
```
- Push `(1,1)` → pre=[1], push `(1,2)`, push `(2,1)`
- Pop `(2,1)` → pre=[1,2], push `(2,2)`, push `(4,1)`
- Pop `(4,1)` → pre=[1,2,4], push `(4,2)`, no left
- Pop `(4,2)` → in=[4], push `(4,3)`, no right
- Pop `(4,3)` → post=[4]
- Pop `(2,2)` → in=[4,2], push `(2,3)`, push `(5,1)`
- Pop `(5,1)` → pre=[1,2,4,5], push `(5,2)`, no left
- Pop `(5,2)` → in=[4,2,5], push `(5,3)`, no right
- Pop `(5,3)` → post=[4,5]
- Pop `(2,3)` → post=[4,5,2]
- Pop `(1,2)` → in=[4,2,5,1], push `(1,3)`, push `(3,1)`
- Pop `(3,1)` → pre=[1,2,4,5,3], push `(3,2)`, no left
- Pop `(3,2)` → in=[4,2,5,1,3], push `(3,3)`, no right
- Pop `(3,3)` → post=[4,5,2,3,1]
- Pop `(1,3)` → post=[4,5,2,3,1] ✅

---

## Code
```cpp
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

class Solution{
    public:
    vector<vector<int>> preInPostTrav(Node* root){
        
        if(root==NULL) return {};
        
        stack<pair<Node*,int>> st;
        vector<int> pre,in,post;

        st.push({root,1});

        while(!st.empty()){
            auto it=st.top();
            st.pop();

            if(it.second==1){
                pre.push_back(it.first->data);
                it.second=2;
                st.push(it);
                if(it.first->left!=NULL){
                    st.push({it.first->left,1});
                }
            }
            else if(it.second==2){
                in.push_back(it.first->data);
                it.second=3;
                st.push(it);
                if(it.first->right!=NULL) st.push({it.first->right,1});
            }
            else{
                post.push_back(it.first->data);
            }
        }

        vector<vector<int>> result;
        result.push_back(pre);
        result.push_back(in);
        result.push_back(post);

        return result;
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
```
```
Preorder traversal:  1 2 4 5 3
Inorder traversal:   4 2 5 1 3
Postorder traversal: 4 5 2 3 1
```

---

## Complexity
| Approach | Time | Space |
|---|---|---|
| Single Stack (Optimal) | O(N) | O(N) |

*(Each node is pushed and popped exactly 3 times → 3N operations = O(N))*

---

## Key Takeaway
By attaching a **visit counter (state 1/2/3)** to each stack entry, you can simulate all three DFS traversals in a single pass — state 1 = preorder moment, state 2 = inorder moment, state 3 = postorder moment.
