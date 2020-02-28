#include <bits/stdc++.h>

using namespace std;


main(){
	int a=5;

	cout<<"value of a is:"<<a<<endl;
	cout<<"address of is:"<<&a<<endl;
	cout<<"============================="<<endl;


	int* b;
	cout<<"value of b is:"<<b<<endl;
	cout<<"address of b is:"<<&b<<endl;
	cout<<"============================="<<endl;

	b=&a;

	cout<<"value of a is:"<<*b<<endl;
	cout<<"address of is:"<<&b<<endl;
	cout<<"============================="<<endl;


	int **c=&b;

	cout<<"value of c is:"<<c<<endl;

	**c=*b+a;
	cout<<**c<<endl;

	cout<<"something new"<<endl;


	cout<<a;
	

	


}