#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int key;
    Node* next;
    Node(int key){
        this->key = key;
        this->next = NULL;
    }
};

class Stack{
    public:
    Node* top;
    Stack(){
        top = NULL;
    }
    void push(int key);
    int pop();
    int peek();
    bool isEmpty();
};

void Stack::push(int key){
    Node* newNode = new Node (key);
    newNode->next = top;
    top = newNode;
}


int Stack::pop(){
    Node* temp = top;
    int value = temp->key;
    top = top->next;
    //cout << "Popping: " << temp->key << endl;
    delete temp;
    return value;
}

int Stack::peek(){
    return top->key;
}

bool Stack::isEmpty(){
    if(top==NULL)
        return true;
    else
        return false;
}


class Queue{
    Node* front;
    Node* rear;
    Queue(){
        front = NULL;
        rear = NULL;
    }
    void enqueue(int key);
    int dequeue();
    int peek();
    bool isEmpty();
};

void Queue::enqueue(int key){
    // write your code
}
int Queue::dequeue(){
    // write your code
}
int Queue::peek(){
    //write your code
}
bool Queue::isEmpty(){
    //write your code
}

int main(){
    /*---------STACK PART --------*/
    Stack* s1 = new Stack();

    cout << "Stack Empty: " << s1->isEmpty() << endl;

    s1->push(100);
    s1->push(200);
    s1->push(300);
    s1->push(400);
    s1->push(500);

    Node* current = s1->top;
    while(current!=NULL){
        cout << current->key << " ";
        current = current->next;
    }
    cout << "\n";

    cout << "Top element: " << s1->peek() << endl;

    cout << "Popping:" << s1->pop() << endl;
    cout << "Popping:" << s1->pop() << endl;

     cout << "Top element: " << s1->peek() << endl;

    current = s1->top;
    while(current!=NULL){
        cout << current->key << " ";
        current = current->next;
    }



}