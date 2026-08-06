#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data=val;
        next=NULL;
    }
};

class Soultion{

    public:
    Node* deleteTail(Node* head){
        Node* current=head;

        while(current->next->next!=NULL) current=current->next;

        delete current->next;
        current->next=NULL;

        return head;
    }

    void printList(Node* head){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};

int main(){
    
    Soultion sol;

    Node* head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);

    cout<<"Before Deletion:\n";
    sol.printList(head);

    head=sol.deleteTail(head);

    cout<<"After Deletion:\n";
    sol.printList(head);
}

