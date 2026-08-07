#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int data1, Node* next1, Node* prev1){
        data=data1;
        next=next1;
        prev=prev1;
    }

    Node(int data1){
        data=data1;
        next=nullptr;
        prev=nullptr;
    }
};

int main(){
    vector<int> nums {69,1,2,3,4};
    Node* y=new Node(nums[0]);

    cout<<y<<endl;
    cout<<y->data<<endl;
}