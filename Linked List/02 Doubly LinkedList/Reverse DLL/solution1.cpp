#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node* front;
    Node* back;

    Node(int val,Node* front1,Node* back1){
        data=val;
        front=front1;
        back=back1;
    }

    Node(int val){
        data=val;
        front=nullptr;
        back=nullptr;
    }
};

class Solution{

    public:
    
    Node* arrayToDLL(vector<int>& arr){

        Node* head=new Node(arr[0]);
        Node* prev=head;

        for(int i=1;i<arr.size();i++){
            Node* temp=new Node(arr[i],nullptr,prev);
            prev->front=temp;
            prev=temp;
        }
        return head;
    }

    void printList(Node* head){
        Node* temp=head;

        while(temp!=nullptr){
            cout<<temp->data<<" ";
            temp=temp->front;
        }
        cout<<endl;
    }

    Node* reverseList(Node* head){
        
        if(head==nullptr || head->front==nullptr) return head;
        
        stack<int> st;

        Node*temp=head;

        while(temp!=nullptr){
            st.push(temp->data);
            temp=temp->front;
        }

        temp=head;

        while(temp!=nullptr){
            temp->data=st.top();
            st.pop();
            temp=temp->front;
        }

        return head;
    }
};

int main(){

    Solution sol;

    vector<int> arr {1,2,3,4,5};

    Node* head=sol.arrayToDLL(arr);

    cout<<"Before Reverse:\n";
    sol.printList(head);

    head=sol.reverseList(head);

    cout<<"After Reverse:\n";
    sol.printList(head);
    
}