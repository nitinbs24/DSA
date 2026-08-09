#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data1){
        data=data1;
        next=nullptr;
    }

    Node(int data1, Node* next1){
        data=data1;
        next=next1;
    }
};

class Solution{
    public:
    void print(Node* head){
        Node* temp=head;
        while(temp!=nullptr){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

    Node* counter(Node* head){
        Node* zeroDummy=new Node(-1);
        Node* oneDummy=new Node(-1);
        Node* twoDummy=new Node(-1);

        Node* zeroTail=zeroDummy;
        Node* oneTail=oneDummy;
        Node* twoTail=twoDummy;

        Node* curr=head;

        while(curr!=nullptr){
            if(curr->data==0){
                zeroTail->next=curr;
                zeroTail=zeroTail->next;
            }
            else if(curr->data==1){
                oneTail->next=curr;
                oneTail=oneTail->next;
            }
            else {
                twoTail->next=curr;
                twoTail=twoTail->next;
            }
            curr=curr->next;
        }
        zeroTail->next=oneDummy->next?oneDummy->next:twoDummy->next;
        oneTail->next=twoDummy->next;
        twoTail->next=nullptr;
        
        delete oneDummy;
        delete twoDummy;

        return zeroDummy->next;
        
    }
};

int main(){
    Node* head=new Node(0);
    head->next=new Node(1);
    head->next->next=new Node(2);
    head->next->next->next=new Node(0);
    head->next->next->next->next=new Node(1);
    head->next->next->next->next->next=new Node(2);

    cout<<"Before:\n";
    Solution sol;
    sol.print(head);

    head=sol.counter(head);

    cout<<"After:\n";
    sol.print(head);
}
