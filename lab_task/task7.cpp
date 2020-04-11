/*
Name:JALIS MAHAMUD TARIF
ID:1521001042
*/




#include<bits/stdc++.h>

using namespace std;

int dec_to_bin(int n)
{
    if (n == 0)
        return 0;
    else
        return (n % 2 + 10 *
                dec_to_bin(n / 2));
}

int main()
{
    int dec_val;
    cout<<"Enter decimal number:";
    cin>>dec_val;

    cout<<dec_to_bin(dec_val);
    return 0;
}
