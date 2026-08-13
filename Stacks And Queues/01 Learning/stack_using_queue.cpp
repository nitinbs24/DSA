#include<iostream>
#include<queue>
using namespace std;

class QueueStack{
    queue<int> q;

    public:
    void push(int data){
        int s=q.size();

        q.push(data);

        for(int i=0;i<s;i++){
            q.push(q.front());
            q.pop();
        }
    }

    int pop(){
        int popped=q.front();

        q.pop();

        return popped;
    }

    int top(){
        return q.front();
    }

    bool isEmpty(){
        return q.empty();
    }
};

int main() {
    QueueStack st;
    
    // List of commands
    vector<string> commands = {"QueueStack", "push", "push", "pop", "top", "isEmpty"};
    // List of inputs
    vector<vector<int>> inputs = {{}, {4}, {8}, {}, {}, {}};

    for (int i = 0; i < commands.size(); ++i) {
        if (commands[i] == "push") {
            st.push(inputs[i][0]);
            cout << "null ";
        } else if (commands[i] == "pop") {
            cout << st.pop() << " ";
        } else if (commands[i] == "top") {
            cout << st.top() << " ";
        } else if (commands[i] == "isEmpty") {
            cout << (st.isEmpty() ? "true" : "false") << " ";
        } else if (commands[i] == "QueueStack") {
            cout << "null ";
        }
    }

    return 0;
}