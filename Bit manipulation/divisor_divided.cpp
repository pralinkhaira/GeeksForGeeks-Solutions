#include <bits/stdc++.h>
using namespace std;

// brute force - work for +ve divisor and dividend
// we can make it for -ve by putting condition
int divideTwoInteger(int dividend, int divisor)
{
     int sign = 1;
     if (dividend < 0 && divisor > 0)
          sign = -1;
     if (dividend > 0 && divisor < 0)
          sign = -1;

     dividend = dividend > 0 ? dividend : (dividend * -1);
     divisor = divisor > 0 ? divisor : (divisor * -1);

     int sum = 0, cnt = 0;
     while (sum + divisor <= dividend)
     {
          cnt++;
          sum += divisor;
     }
     return (cnt * sign);
}

int main()
{

     return 0;
}