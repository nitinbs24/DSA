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