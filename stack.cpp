#include <bits/stdc++.h>
//#define SIZE 5;
using namespace std;


class Stack{

public:
    int A[5];
    int top;

    Stack(){
     top=0;
    }

    void push(int key){
        A[top++]=key;
    }
    int pop(){
        top--;
        return A[top];
    }
    int peek(){
        return A[top-1];
    }

};
int main(){
    Stack* s1=new Stack;

    s1->push(1);
    s1->push(2);
    s1->push(4);
    s1->push(3);

    s1->pop();
    s1->pop();
    cout<<s1->peek()<<endl;
}