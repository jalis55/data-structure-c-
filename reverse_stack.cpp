#include <bits/stdc++.h>

using namespace std;



class Stack{

public:
	int top;
	unsigned capacity;

	char* arr;



};

Stack* createStack(unsigned capacity){

	Stack* stk=new Stack();

	stk->capacity=capacity;
	stk->top=-1;
	stk->arr=new char[(stk->capacity * sizeof(char))];
	return stk;

}

int isFull(Stack* stk){
	return stk->top==stk->capacity-1;
}

int isEmpty(Stack* stk){
	return stk->top==-1;
}

void push(Stack* stk,char item){
	if(isFull){
		return;
	}
	stk->arr[++stk->top]=item;
}

char pop(Stack* stk){
	if(isEmpty){
		return -1;
	}
	return stk->arr[stk->top--];
}

void reverse(char str[]){

	int size=strlen(str);

	Stack* stack=createStack(size);

	for(int i=0;i<size;i++){
		push(stack,str[i]);
	}

	for(int i=0;i<size;i++){
		str[i]=pop(stack);
	}


}


int main(){
	char str[]="JALIS";

	reverse(str);
	cout<<"reverse string is:"<< str;
	return 0;
}

