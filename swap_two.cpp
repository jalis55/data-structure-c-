#include <bits/stdc++.h>

using namespace std;


int swap(int* x,int* y){
	int t;
	t=*x;
	*x=*y;
	*y=t;
}




int main(){
	int a,b;
	a=10;
	b=20;

	swap(&a,&b);
	cout<<a<<" " <<b<<endl;
}