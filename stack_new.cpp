#include <bits/stdc++.h>

using namespace std;


class Node{

public:
	int key;
	Node* next;

	Node(int key){
		this->key=key;
		this->next=NULL;
	}

};


class Stack{
	
public:

	Node* top;
	Stack(){
		top=NULL;
	}
	void push(int key);
	int pop();
	int peek();
	bool isEmpty();
	bool isFull();
	//void traverse();



};

void Stack::push(int key){


	Node* newNode=new Node(key);


	top=newNode;
}
int Stack::pop(){
	if(top==NULL){
		
	}
}
int Stack::peek(){
	return top->key;
}

// void Stack::traverse(){
// 	Node* cur=top;
// 	while(cur !=NULL){
// 		cout<<cur->key;
// 		cur=cur->next;
// 	}
// }


int main(){
	Stack* s1=new Stack();
	s1->push(5);
	s1->push(11);
	s1->push(55);
	cout<<s1->peek();
	//s1->traverse();

	s1->pop();

}










