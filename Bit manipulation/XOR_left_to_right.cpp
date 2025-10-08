#include <bits/stdc++.h>
using namespace std;

// brute force
int findXOR(int L, int R)
{

     int ans = 0;
     for (int i = L; i <= R; i++)
     {
          ans = ans ^ i;
     }
     return ans;
}

// optimal solution

vector<int> twoOddNum02(vector<int> arr)
{
     // Write your code here.
     int x = 0;
     for (int i = 0; i < arr.size(); i++)
     {
          x = x ^ arr[i];
     }
     int temp = (x & x - 1) ^ x;
     // temp=log2(temp);

     int ans1 = 0, ans2 = 0;

     for (int i = 0; i < arr.size(); i++)
     {
          if (arr[i] & temp)
          {
               ans1 = ans1 ^ arr[i];
          }
          else
          {
               ans2 = ans2 ^ arr[i];
          }
     }

     if (ans1 < ans2)
     {
          swap(ans1, ans2);
     }
     return {ans1, ans2};
}

int funct(int n)
{
     if (n % 4 == 1)
     {
          return 1;
     }
     else if (n % 4 == 2)
     {
          return n + 1;
     }
     else if (n % 4 == 3)
     {
          return 0;
     }
     else if (n % 4 == 0)
     {
          return n;
     }
}

int findXOR(int L, int R)
{

     int a = funct(L - 1);
     int b = funct(R);
     return a ^ b;
}

int main()
{

     return 0;
}