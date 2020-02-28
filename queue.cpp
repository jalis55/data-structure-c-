#include <bits/stdc++.h>
#define SIZE 5
using namespace std;



class Queue{

public:
	int front,rear;

	unsigned capacity;

	int* arr;


	Queue(){
		front=0;
		rear=0;
		arr=new int[SIZE];
	}

	int enqueue(int item);
	int dequeue();
	void peek();
	bool isEmpty();
	bool isFull();
};

bool Queue::isFull(){
	return front==SIZE;
}

bool Queue::isEmpty(){
	return front==rear;
}



int Queue::enqueue(int item){
	if(isFull()){
		cout<<"Queue is full";
		return 0;
	}
	arr[rear++]=item;

}

int Queue::dequeue(){
	if(isEmpty()){
		cout<<"Queue is empty";
		return 0;
	}
	
	return arr[front++];

}

void Queue::peek(){
	cout<<"Top of the Queue is: "<<arr[front]<<endl;
}

int main(){
	Queue* q1=new Queue();
	q1->enqueue(1);
	q1->enqueue(2);
	q1->enqueue(3);
	q1->enqueue(4);
	q1->peek();
	q1->dequeue();
	q1->dequeue();
	q1->dequeue();
	q1->dequeue();
	q1->dequeue();
	q1->peek();

}



