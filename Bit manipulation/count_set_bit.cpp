#include <bits/stdc++.h>
using namespace std;

int func(int n)
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
     return cnt;
}

int countSetBits(int n)
{
     int sum = 0;
     for (int i = 0; i <= n; i++)
     {
          sum += func(i);
     }
     return sum;
}

int funct(int n)
{
     int cnt = 0;
     while (n != 0)
     {
          n = n & (n - 1);
          cnt++;
     }

     return cnt;
}
// optimal solution`
// cnt set bits of  from 1 to N numbers
int countSetBits02(int n)
{
     // Write your code here
     int cnt = 0;
     for (int i = 1; i <= n; i++)
     {
          cnt += funct(i);
     }

     return cnt;
}

int cntsetBits(int n)
{
     int cnt = 0;
     while (n > 0)
     {
          if (n & 1)
          {
               cnt++;
          }
          n = n / 2;
     }
}

int main()
{
     cout << cntsetBits(7);

     return 0;
}