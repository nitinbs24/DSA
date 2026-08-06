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

    int countList(Node* head){
        Node* temp=head;
        int count=0;
        while(temp!=nullptr){
            count++;
            temp=temp->next;
        }
        return count;
    }
};

int main(){
    Node* head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(2);

    Solution sol;
    cout<<sol.countList(head)<<endl;
}