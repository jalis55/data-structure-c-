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
	void printList();

	//~SinglyLinkedList();
	
};

void SinglyLinkedList::pushFront(int key){
	Node* newNode=new Node();

	newNode->key=key;
	newNode->next=head;
	head=newNode;

	cout<<"operation completed"<<endl;


}

void SinglyLinkedList::popFront(){
	Node* temp=head;
	head=head->next;
	delete temp;

	cout<<"operation completed"<<endl;
}

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
			//main();
			s->pushFront(value);

			goto Menu;

		}
		if(choice==2){
			s->popFront();
			goto Menu;

		}
		if(choice==3){

		}
		if(choice==4){

		}
		if(choice==5){

		}
		if(choice==6){

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
		







}