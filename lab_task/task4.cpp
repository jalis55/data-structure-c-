/*
Name:JALIS MAHAMUD TARIF
ID:1521001042
*/




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
        if(top==0){
            return -1;
        }
        top--;
        return A[top];
    }
    int peek(){
        return A[top-1];
    }


};
int main(){
    Stack* s1=new Stack;
    int a,sum=0;

    s1->push(1);
    s1->push(2);
    s1->push(4);
    s1->push(3);
    s1->push(5);

    while(1){
        a=s1->pop();
        if(a==-1){
            break;
        }
        if(a%2==0){
            sum=sum+(a*a);
        }


    }
    cout<<sum;

}
