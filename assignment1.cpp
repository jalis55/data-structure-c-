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
	bool findKey(int val);

	bool isEmpty();

	void erase(int val);

	void addBefore(int node_value,int val);
	void addAfter(int node_value,int val);


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

//finding a value

bool SinglyLinkedList::findKey(int val){
	Node* cur=head;
	while(cur != NULL){
		if(cur->key==val){
			return true;
		}
		cur=cur->next;

	}
	return false;
}

//erase a key from the list

void SinglyLinkedList::erase(int val){
	if(head==NULL){
		cout<<"Invalid......list is empty"<<endl;
		return;
	}
	Node* cur=head;

	Node* temp=NULL;

	if(cur->key=val){
		temp=cur;
		head=temp->next;
		delete temp;
		cout<<"Item has deleted"<<endl;
		return;
	}



	while(cur!=NULL){
		if(cur->key==val){
			temp=cur;
			cur=temp->next;
			delete temp;
			cout<<"Item has deleted"<<endl;
			return;
		}

	}
	cout<<"Item can not be delete"<<endl;
	return;
}

//check empty linked list

bool SinglyLinkedList::isEmpty(){
	if(head==NULL){
		return true;
	}
	return false;
}
//add before a linked list node

void SinglyLinkedList::addBefore(int node_value,int val){
	if(head==NULL){
		cout<<"Invalid.....List is empty";
	}

	Node* node=NULL;
	Node* cur=head;
	while(cur !=NULL){
		if(cur->key==node_value){
			node=cur;
			break;
		}
		cur=cur->next;
	}
	if(node==NULL){
		cout<<"Node does not exits"<<endl;
		return;
	}

	Node* newNode=new Node();
	newNode->key=val;
	if(node==head){
		newNode->next=node;
		head=newNode;
	}

	while(cur!=node){
		cur=cur->next;
	}
	Node* prevNode=cur;
	newNode->next=node;
	prevNode->next=newNode;
	cout<<"added successfully"<<endl;
	return;

	

}

//add after a linked list node

void SinglyLinkedList::addAfter(int node_value,int val){
	if(head==NULL){
		cout<<"Invalid.....List is empty";
	}

	Node* node=NULL;
	Node* cur=head;
	while(cur !=NULL){
		if(cur->key==node_value){
			node=cur;
			break;
		}
		cur=cur->next;
	}
	if(node==NULL){
		cout<<"Node does not exits"<<endl;
		return;
	}
	Node* newNode=new Node();
	newNode->key=val;
	newNode->next=node->next;
	node->next=newNode;

	if(tail==node){
		tail=newNode;
	}
	cout<<"added successfully"<<endl;
	return;

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


void printDash(){

	cout<<"-------------------------"<<endl;

}


int main(){

	SinglyLinkedList* s=new SinglyLinkedList();

	
Menu:
	printDash();
	cout<<"Singly Linked List"<<endl;
	printDash();
	cout<<"(1) push front...  (2) pop front... (3) top front...\n(4) push back... (5) pop back...(6) top back..."<<endl;
	cout<<"(7) find key...  (8) erase key... (9) empty...\n(10) add before... (11) add after..(12) print...\n(13)exit..."<<endl;
	printDash();
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
			int key_value;
			cout<<"Enter search key:";
			cin>>key_value;
			if(s->findKey(key_value)){
				cout<<"Item exists in the list"<<endl;
			}
			else{
				cout<<"Item does not exits in the list"<<endl;

			}
			goto Menu;

		}
		if(choice==8){
			int item;
			cout<<"Enter item for delete:";
			cin>>item;
			s->erase(item);


			goto Menu;





		}
		if(choice==9){
						if(s->isEmpty()){
				cout<<"Empty linked list"<<endl;
			}
			else{
				cout<<"Linked is not empty"<<endl;
			}
			goto Menu;

		}
		if(choice==10){
			int a,b;
			cout<<"Enter node value:";
			cin>>a;
			cout<<"\nEnter new node value:";
			cin>>b;
			
			s->addBefore(a,b);

			goto Menu;


		}
		if(choice==11){
			int a,b;
			cout<<"Enter node value:";
			cin>>a;
			cout<<"\nEnter new node value:";
			cin>>b;
			
			s->addAfter(a,b);

			goto Menu;


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