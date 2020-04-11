/*
Name:JALIS MAHAMUD TARIF
ID:1521001042
*/



#include <bits/stdc++.h>
using namespace std;

int str_to_int(char ar[], int n){
	//base Case
	if(n == 0){
		return ar[n] - '0';
	}
	//recursive function call
	int int_val = str_to_int(ar,n-1);
	int val = ar[n] - '0';
	return int_val * 10 + val;
}

int main(){
	char arr[20];
	cout<<"Enter String:"<<endl;
	cin>>arr;
	int len=0;

	for(int i =0;arr[i] != '\0';i++){
		len++;
	}
	cout<<"After converting the String in Integer:";
	cout<<str_to_int(arr,len-1)<<endl;

	return 0;
}
