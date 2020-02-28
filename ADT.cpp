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

//creating a node


Node* newNode=new Node;

newNode->key=static_cast<void*> (malloc(bytes));

memcpy(newNode->key,(char*) key,bytes );
newNode->next=NULL;

newNode->next=head;
head=newNode;



}



int main(){

SinglyLinkedList* list1=new SinglyLinkedList;
//SinglyLinkedList* list2=new SinglyLinkedList;
if(list1->head==NULL){
    cout<<"empty"<<endl;

}
char key;
cout<<"enter value"<<endl;
cin>>key;

list1->pushFront(&key,sizeof(char));

Node* current=list1->head;
while(current!=NULL){
    cout<<*((char*)current->key)<<"->";
    current=current->next;
}
cout<<"NULL"<<endl;


}
