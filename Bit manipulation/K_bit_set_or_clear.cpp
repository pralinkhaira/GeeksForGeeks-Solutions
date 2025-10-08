#include <bits/stdc++.h>
using namespace std;

// brute force approach
bool isKthBitSet(int n, int k)
{
     string str = "";
     while (n > 0)
     {
          if (n % 2)
          {
               str.push_back('1');
          }
          else
          {
               str.push_back('0');
          }
          n /= 2;
     }

     if (str[k - 1] == '1')
     {
          return true;
     }
     return false;
}

// optimal solution

// using left shift O(1)
bool isKthBitSet(int n, int k)
{
     int m = 1 << (k - 1);

     if (m & n)
     {
          return true;
     }

     return false;
}

// using right shift
bool isKthBitSet(int n, int k)
{

     if ((n >> (k - 1)) & 1)
     {
          return true;
     }

     return false;
}

int main()
{
     bool a = isKthBitSet(7, 1);

     return 0;
}