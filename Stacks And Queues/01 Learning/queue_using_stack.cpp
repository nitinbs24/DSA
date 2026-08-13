#include <bits/stdc++.h>
using namespace std;

class StackQueue {
private:
    stack <int> st1, st2;

public: 
    StackQueue () {
        
    }
    
    void push(int x) {
        while (!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }
        
        st1.push(x);
        
        while (!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }
    }
    
    int pop() {
        if (st1.empty()) {
            cout << "Stack is empty";
            return -1;
        }
        
        int topElement = st1.top();
        st1.pop();
        
        return topElement;
    }
    
    int peek() {
        if (st1.empty()) {
            cout << "Stack is empty";
            return -1;
        }
        
        return st1.top();
    }
    
    bool isEmpty() {
        return st1.empty();
    }
};

int main() {
    StackQueue q;
    
    vector<string> commands = {"StackQueue", "push", "push", 
                               "pop", "peek", "isEmpty"};
    vector<vector<int>> inputs = {{}, {4}, {8}, {}, {}, {}};

    for (int i = 0; i < commands.size(); ++i) {
        if (commands[i] == "push") {
            q.push(inputs[i][0]);
            cout << "null ";
        } else if (commands[i] == "pop") {
            cout << q.pop() << " ";
        } else if (commands[i] == "peek") {
            cout << q.peek() << " ";
        } else if (commands[i] == "isEmpty") {
            cout << (q.isEmpty() ? "true" : "false") << " ";
        } else if (commands[i] == "StackQueue") {
            cout << "null ";
        }
    }
    
    return 0;
}