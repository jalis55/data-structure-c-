#include <bits/stdc++.h>

using namespace std;


main(){
	

	int marks [3][2]={{22,33},{31,21},{22,30}};


	int *ptr=marks[0];

	//cout<<*(ptr+1*2+1)<<endl;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout<<*(ptr+i*2+j)<<endl;
		}
	}

}