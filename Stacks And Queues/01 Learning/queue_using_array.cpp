#include<iostream>
#include<vector>
using namespace std;

class ArrayQueue{
    int* queueArray;
    int start,end;
    int curSize,maxSize;

public:
    ArrayQueue(){
        queueArray=new int[10];
        start=-1;
        end=-1;
        curSize=0;
        maxSize=10;
    }

    void push(int data){
        if(curSize==maxSize){
            cout<<"Queue is Full..Exiting..\n";
            exit(1);
        }
        
        if(start==-1){
            start=0;
            end=0;
        }
        else{
            end=(end+1)%maxSize;
        }
        queueArray[end]=data;
        curSize++;
    }

    int pop(){
        if(start==-1){
            cout<<"Queue is empty..Exiting..\n";
            exit(1);
        }

        int popped=queueArray[start];

        if(curSize==1){
            start=-1;
            end=-1;
        }
        else{
            start=(start+1)%maxSize;
        }
        curSize--;
        return popped;
    }

    int peek(){
        if(start==-1){
            cout<<"Queue Empty..Exiting..\n";
            exit(1);
        }
        return queueArray[start];
    }

    bool isEmpty(){
        return (curSize==0);
    }
};

int main() {
    ArrayQueue queue;
    vector<string> commands = {"ArrayQueue", "push", "push", 
                               "peek", "pop", "isEmpty"};
    vector<vector<int>> inputs = {{}, {5}, {10}, {}, {}, {}};

    for (int i = 0; i < commands.size(); ++i) {
        if (commands[i] == "push") {
            queue.push(inputs[i][0]);
            cout << "null ";
        } else if (commands[i] == "pop") {
            cout << queue.pop() << " ";
        } else if (commands[i] == "peek") {
            cout << queue.peek() << " ";
        } else if (commands[i] == "isEmpty") {
            cout << (queue.isEmpty() ? "true" : "false") << " ";
        } else if (commands[i] == "ArrayQueue") {
            cout << "null ";
        }
    }

    return 0;
}