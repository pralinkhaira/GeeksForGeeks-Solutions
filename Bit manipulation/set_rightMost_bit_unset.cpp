

#include <bits/stdc++.h>
using namespace std;

// brute force
int setBits(int num)
{
     string str = "";
     int n = num;
     while (n >= 1)
     {
          if (n % 2 == 1)
          {
               str.push_back('1');
          }
          else
          {
               str.push_back('0');
          }
          n = n / 2;
     }
     int idx = -1;
     for (int i = 0; i < str.size(); i++)
     {
          if (str[i] == '0')
          {
               idx = i;
               str[i] = '1';
               break;
          }
     }
     if (idx == -1)
     {
          return num;
     }
     int res = 1;
     num = 0;
     for (int i = 0; i < str.size(); i++)
     {
          int a = str[i] - '0';
          num += res * a;
          res *= 2;
     }
     return num;
}

int main()
{

     return 0;
}