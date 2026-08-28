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
        
        stack <pair<Node*,int>> st;
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

int main()
{
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Create object of Solution class
    Solution sol;
    
    // Getting the pre-order, in-order,
    // and post-order traversals
    vector<int> pre, in, post;
    vector<vector<int>> traversals = sol.preInPostTrav(root);

    // Extracting the traversals
    // from the result
    pre = traversals[0];
    in = traversals[1];
    post = traversals[2];

    // Printing the traversals
    cout << "Preorder traversal: ";
    for (int val : pre) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Inorder traversal: ";
    for (int val : in) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Postorder traversal: ";
    for (int val : post) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}