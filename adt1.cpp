#include <bits/stdc++.h>

using namespace std;



class Node{
public:

	void* key;
	Node* next;

};

class SinglyLinkedList{

public:
	Node* head;
	Node* tail;


	SinglyLinkedList(){
		head=NULL;
		tail=NULL;

	}

	void pushFront(void* key,int bytes);
	void popFront();

};


void SinglyLinkedList::pushFront(void* key,int bytes){


Node* newNode=new Node;

newNode->key=static_cast <void*> (malloc(bytes));

memcpy(newNode->key,(char*) key,bytes);

newNode->next=NULL;

newNode->next=head;

head=newNode;

}

int main(){
	SinglyLinkedList* l1=new SinglyLinkedList;

	if(l1->head==NULL){
		cout<<"list is empty\n";
	}

	char data1,data2;
	cin>>data1;
	cin>>data2;

	l1->pushFront(&data1,sizeof(char));
	l1->pushFront(&data2,sizeof(char));


	Node* curr=l1->head;

	while(curr !=NULL){
		cout<<*((char*)curr->key)<<"-->";
		curr=curr->next;
	}
	cout<<"null"<<endl;


	///new linked list another data type
	SinglyLinkedList* l2=new SinglyLinkedList;

	double dat;
	cin>>dat;

	l2->pushFront(&dat,sizeof(double));


	Node* current=l2->head;

	while(current=NULL){
		cout<<*((double*)current->key)<<"-->";
		current=current->next;
	}
	cout<<"null"<<endl;








}





















