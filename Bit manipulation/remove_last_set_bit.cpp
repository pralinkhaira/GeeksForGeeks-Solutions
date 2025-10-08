#include <bits/stdc++.h>
using namespace std;

// brute force
int remove_last_set_bit(int num)
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
     int idx = -1;
     for (int i = 0; i < str.size(); i++)
     {
          if (str[i] == '1')
          {
               str[i] = '0';
               idx = i;
               break;
          }
     }

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
int remove_last_set_bit02(int num)
{
     int ans = (num & (num - 1));
     return ans;
}
int main()
{
     int a = remove_last_set_bit02(7);
     cout << a;

     return 0;
}