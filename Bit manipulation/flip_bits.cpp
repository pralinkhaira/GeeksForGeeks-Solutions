

#include <bits/stdc++.h>
using namespace std;

// brute force
int flipBits(int A, int B)
{
     // Write your code here.
     // Convert integers A and B to binary strings
     string strA = "", strB = "";

     while (A > 0)
     {
          strA = (A % 2 == 1 ? '1' : '0') + strA;
          A /= 2;
     }

     while (B > 0)
     {
          strB = (B % 2 == 1 ? '1' : '0') + strB;
          B /= 2;
     }

     // Equalize the lengths of the binary strings
     int n1 = strA.size();
     int n2 = strB.size();

     while (n1 < n2)
     {
          strA = '0' + strA;
          n1++;
     }

     while (n2 < n1)
     {
          strB = '0' + strB;
          n2++;
     }

     // Compare the binary strings and count the differing bits
     int cnt = 0;
     for (int i = 0; i < n1; i++)
     {
          if (strA[i] != strB[i])
          {
               cnt++;
          }
     }

     return cnt;
}

int main()
{

     return 0;
}