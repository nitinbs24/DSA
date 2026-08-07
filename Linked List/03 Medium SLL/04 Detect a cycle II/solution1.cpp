#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

class Solution {
public:

    ListNode* detectCycle(ListNode* head) {

        unordered_set<ListNode*> visited;

        while (head != NULL) {

            if (visited.find(head) != visited.end()) {
                return head;
            }

            visited.insert(head);
            head = head->next;
        }
        return NULL;
    }
};


int main() {

    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);

    head->next->next->next->next = head->next;

    Solution obj;
    ListNode* startNode = obj.detectCycle(head);

    if (startNode)
        cout << "Cycle starts at node with value: " << startNode->val << endl;
    else
        cout << "No cycle found." << endl;

    return 0;
}
