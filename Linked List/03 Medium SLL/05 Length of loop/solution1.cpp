#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

class Solution {
    public:
    int lengthOfLoop(Node* head){
        Node* temp=head;
        int count=0;
        unordered_map<Node*,int> freq;
        while(temp!=nullptr){
            if(freq.find(temp)!=freq.end()){
                return count-freq[temp];
            }
            freq[temp]=count;
            count++;
            temp=temp->next;
        }
        return 0;
    }

};

int main() {
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    fifth->next = second;

    Solution obj;
    int loopLength = obj.lengthOfLoop(head);

    if (loopLength > 0) {
        cout << "Length of the loop: " << loopLength << endl;
    } else {
        cout << "No loop found in the linked list." << endl;
    }

    return 0;
}
