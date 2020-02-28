#include <bits/stdc++.h>


using namespace std;


class Node
{
public:

	int key;
	Node* next;
	
};

class SinglyLinkedList
{
public:
	Node* head;
	Node* tail;


	SinglyLinkedList(){
		head=NULL;
		tail=NULL;
	}

	void pushFront(int key);
	void popFront();
	int* topFront();
	void pushBack(int key);
	void popBack();

	int* topBack();
	void printList();

	//~SinglyLinkedList();
	
};

//push from operation
void SinglyLinkedList::pushFront(int key){
	Node* newNode=new Node();

	newNode->key=key;
	if(head==NULL && tail==NULL){
		head=newNode;
		tail=head;
	}
	else{
			newNode->next=head;
			head=newNode;

	}



	cout<<"operation completed"<<endl;


}

//pop front operation
void SinglyLinkedList::popFront(){
	if(head==NULL){
		cout<<"Invalid operation"<<endl;
		

	}

	Node* temp=head;
	head=head->next;
	delete temp;

	cout<<"operation completed"<<endl;
}
//top front operation
int* SinglyLinkedList::topFront(){
	return &(head->key);
}

//push back operation

void SinglyLinkedList::pushBack(int value){
	Node* newNode=new Node();

	newNode->key=value;
	if(head==NULL && tail==NULL){
		head=newNode;
	}
	tail->next=newNode;
	tail=newNode;

	cout<<"operation completed"<<endl;

}

//pop back operation
void SinglyLinkedList::popBack(){
	Node* cur=head;
	while(cur->next->next!=NULL){
		cur=cur->next;
	}
	Node* temp=cur->next;
	cur->next=NULL;
	tail=cur;
	delete temp;
	cout<<"operation completed"<<endl;
}

//top back operation

int* SinglyLinkedList::topBack(){

	return &(tail->key);

}


//printing entire linked list
void SinglyLinkedList::printList(){

	
	Node* curr=head;

	while(curr != NULL){
		cout<<curr->key<<" ";

		curr=curr->next;
	}
	cout<<"\noperation completed"<<endl;
}


void printDots(){

	cout<<"-------------------------"<<endl;

}


int main(){

	SinglyLinkedList* s=new SinglyLinkedList();

	
Menu:
	printDots();
	cout<<"Singly Linked List"<<endl;
	printDots();
	cout<<"(1) push front...  (2) pop front... (3) top front...\n(4) push back... (5) pop back...(6) top back..."<<endl;
	cout<<"(7) find key...  (8) erase key... (9) empty...\n(10) add before... (11) add after..(12) print...\n(13)exit..."<<endl;
	printDots();
	int choice;
	cout<<"Enter choice: ";
	cin>>choice;

		if(choice==1){
			int value;
			cout<<"Enter key: ";
			cin>>value;
			s->pushFront(value);

			goto Menu;

		}
		if(choice==2){
			s->popFront();
			goto Menu;

		}
		if(choice==3){
			cout<<*(s->topFront())<<endl;
			goto Menu;

		}
		if(choice==4){
			int value;
			cout<<"Enter key: ";
			cin>>value;
			s->pushBack(value);

			goto Menu;

		}
		if(choice==5){
			s->popBack();
			goto Menu;


		}
		if(choice==6){
			cout<<*(s->topBack())<<endl;
			goto Menu;

		}
		if(choice==7){

		}
		if(choice==8){

		}
		if(choice==9){

		}
		if(choice==10){

		}
		if(choice==11){

		}
		if(choice==12){
			s->printList();
			goto Menu;
		}
		if(choice==13){
			exit(1);

		}
		else{
			cout<<"Invalid option..Try again"<<endl;
			goto Menu;
		}
		







}