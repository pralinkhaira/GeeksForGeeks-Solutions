#include <bits/stdc++.h>
using namespace std;

int set_ith_bit(int num, int k)
{
     string str = "";
     while (num > 0)
     {
          if (num % 2)
          {
               str += "1";
          }
          else
          {
               str += "0";
          }
          num /= 2;
     }
     str[k - 1] = '1';
     int res = 1;
     num = 0;
     for (int i = 0; i < str.size(); i++)
     {
          num += (str[i] - '0') * res;
          res *= 2;
     }
     return num;
}

// optimal solution
int set_ith_bit02(int num, int k)
{
     int ans = 1 << (k - 1);
     ans = num | ans;

     return ans;
}

int unset_ith_bit02(int num, int k)
{
     int ans = ~(1 << (k - 1));
     ans = num & ans;
     return ans;
}

int main()
{
     int a = unset_ith_bit02(6, 2);
     cout << a;
     // cout << __builtin_popcount(7);
     return 0;
}