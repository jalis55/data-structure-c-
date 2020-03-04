#include <bits/stdc++.h>

using namespace std;

int f(int x, int *py, int **ppz) 
{ 
  int y, z; 
  **ppz += 1; 
  cout<<**ppz<<endl;
   z  = **ppz; 
  *py += 2; 
  cout<<*py<<endl;
   y = *py; 
   x += 3; 
   cout<<x<<endl;
   return x + y + z; 
} 
int main() 
{ 
   int c, *b, **a; 
   c = 4; 
   b = &c; 
   a = &b; 
   //cout << f(c, b, a) << endl; 
  int x = 20, *y, *z; 
      
    // Assume address of x is 500 and  
    // integer is 4 byte size  
    y = &x;  
    z = y; 
    *y++;  
    *z++; 
    x++;

    cout<<x<<y<<z;
   return 0;
}