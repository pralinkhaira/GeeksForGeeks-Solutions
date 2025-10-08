#include <bits/stdc++.h>
using namespace std;
// brute force
bool isPowerOfTwo(int n)
{
     string str = "";
     while (n >= 1)
     {
          if (n % 2)
          {
               str += '1';
          }
          else
          {
               str += '0';
          }
          n /= 2;
     }
     int cnt = 0;
     for (int i = 0; i < str.size(); i++)
     {
          if (str[i] == '1')
          {
               cnt++;
          }
     }
     if (cnt == 1)
     {
          return true;
     }
     return false;
}

// optimal solution
bool isPowerOfTwo(int n)
{
     if (n <= 0)
     {
          return false;
     }
     if ((n & (n - 1)) == 0)
     {
          return true;
     }
     return false;
}
int main()
{

     return 0;
}