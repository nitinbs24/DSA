#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data=val;
        next=nullptr;
    }

    Node(int val,Node* next1){
        data=val;
        next=next1;
    }
};

class Solution{
    public:
    Node* insertHead(Node*head,int data){
        Node* newNode=new Node(data,head);
        return newNode;
    }

    bool findList(Node* head,int target){
        Node* temp=head;
        bool found = false;
        while(temp!=nullptr){
            if(temp->data==target){
                found=true;
                break;
            }
            temp=temp->next;
        }
        return found;
    }
};

int main(){
    Node* head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(2);
    int target=6;
    Solution sol;
    cout<<sol.findList(head,target)<<endl;
}