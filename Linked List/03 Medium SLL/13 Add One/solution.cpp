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
};

class Solution{

    public:

    Node* reverseList(Node* head){
        Node* prev=nullptr;
        Node* curr=head;
        
        while(curr!=nullptr){
            Node* nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
        }
        return prev;
    }

    Node* addOne(Node* head){
        
        head=reverseList(head);

        int carry=1;
        Node* curr=head;

        while(curr && carry){
            int sum=curr->data+carry;
            curr->data=sum%10;
            carry=sum/10;
        
            if(!curr->next && carry){
                curr->next=new Node(carry);
                carry=0;
            }
            curr=curr->next;
        }
        head=reverseList(head);
        return head;
    }
};

int main(){
    Node* head=new Node(9);
    head->next=new Node(9);

    Solution sol;
    head=sol.addOne(head);

    Node* temp=head;
    while(temp){
        cout<<temp->data;
        temp=temp->next;
    }
    cout<<endl;

}