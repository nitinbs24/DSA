#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data1,Node* next1){
        data=data1;
        next=next1;
    }

    Node(int data1){
        data=data1;
        next=nullptr;
    }
};
class Soultion{
    public:
    Node* insertHead(Node*head,int data){
        Node* newNode=new Node(data,head);
        return newNode;
    }

    void printList(Node* head){
        Node* temp=head;
        while(temp!=nullptr){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};

int main(){
    Soultion sol;

    Node* head=new Node(2);
    head->next=new Node(3);

    cout<<"original List:\n";
    sol.printList(head);

    head=sol.insertHead(head, 1);

    cout<<"Inserting 1:\n";
    sol.printList(head);
}