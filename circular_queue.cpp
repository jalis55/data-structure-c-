#include<bits/stdc++.h>
#define SIZE 5
using namespace std;




class Queue{
public:

	int front,rear;
	int* arr;
	Queue(){
		front=0;
		rear=0;
		arr=new int[SIZE];
	}

	int enqueue(int item);

	int dequeue();

	bool isFull();
	bool isEmpty();
	void peek();
};

bool Queue::isFull(){
	return (rear+1)% (SIZE+1) ==front;
	
}
bool Queue::isEmpty(){
	
	return front==rear;
}

int Queue::enqueue(int item){

	if(isFull()){
		cout<<"Queue is full"<<endl;
	}
	arr[rear]=item;
	rear=(rear+1)%(SIZE+1);

}

int Queue::dequeue(){
	if(isEmpty()){
		cout<<"Queue is empty"<<endl;
		return 0;
	}

	int item=arr[front];
	front=(front+1)%(SIZE+1);
	return item;


}

void Queue::peek(){
	cout<<"Top of the Queue is:"<<arr[front]<<endl;
}

int main(){
	Queue* q1=new Queue();
	q1->enqueue(5);
	q1->enqueue(1);
	q1->enqueue(2);
	q1->enqueue(3);
	q1->enqueue(4);
	//q1->enqueue(5);
	q1->peek();

	q1->dequeue();
	q1->dequeue();
	q1->dequeue();
	q1->dequeue();
	q1->peek();

	//q1->dequeue();



}








