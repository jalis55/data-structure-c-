#include<bits/stdc++.h>

using namespace std;


class Node
{
public:
	int key;
	Node* next;
	Node* prev;
	
};


class doublyLinked{
public:
	Node* head;

	doublyLinked(){
		head=NULL;
	}

	int insert(int val);
	bool display();


};


int doublyLinked::insert(int val){
	Node* newNode=new Node();

	newNode->key=val;
	newNode->prev=NULL;
	newNode->next=head;

	if(head!=NULL){
		head->prev=newNode;
	}
	head=newNode;

}

bool doublyLinked::display(){

	Node* tail=head;
	while(tail->next!=NULL){
		tail=tail->next;
	}

	while(tail !=head){
		if(tail->key != head->key){
			return false;
		}
		tail=tail->prev;
		head=head->next;

	}
	return true;
}


int main(){
	doublyLinked* dl=new doublyLinked();


	dl->insert(1);
	dl->insert(2);
	dl->insert(1);

	if(dl->display()){
		cout<<"palindrome"<<endl;

	}
	else{
		cout<<"not";
	}

}