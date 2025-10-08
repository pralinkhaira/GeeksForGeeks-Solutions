#include <bits/stdc++.h>
using namespace std;

int toggle_ith_bit(int num, int k)
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
     str[k - 1] == '1' ? str[k - 1] = '0' : str[k - 1] = '1'; // toggle step
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
int toggle_ith_bit02(int num, int k)
{
     int ans = 1 << (k - 1);
     ans = num ^ ans;
     return ans;
}

int main()
{
     int a = toggle_ith_bit02(5, 2);
     cout << a;

     return 0;
}