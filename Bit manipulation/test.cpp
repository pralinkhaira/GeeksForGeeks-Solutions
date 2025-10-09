#include <bits/stdc++.h>
using namespace std;

// Striver 2nf video

void swap(int &a, int &b)
{
     a = a ^ b;
     b = a ^ b;
     a = a ^ b;
}

// right most bit is one and start counting from there
void check_i_bit_set_or_not(int n, int k)
{
     // 1st approach  // number is shift
     // if ((n >> (k - 1)) & 1)
     // {
     //      cout << "Kth bit is set" << endl;
     // }
     // else
     // {
     //      cout << "Kth bit is not set" << endl;
     // }

     // 2nd approach // 1 is shift
     if (n & (1 << (k - 1)))
     {
          cout << "Kth bit is set" << endl;
     }
     else
     {
          cout << "Kth bit is not set" << endl;
     }
}

// right most bit is one and start counting from there
int set_ith_bit(int n, int k)
{
     return n | (1 << (k - 1));
}

int clear_ith_bit(int n, int k)
{

     return n & ~(1 << (k - 1));
}

int toggle_ith_bit(int n, int k)
{
     return n ^ (1 << (k - 1));
}

int remove_last_set_bit(int n)
{
     if (n == 0)
          return 0;
     //  1st approach - time-O(logn)
     // int org = n;
     // int k = 1;
     // while (org == n)
     // {
     //      n = n & (~k);
     //      k = k << 1;
     // }
     // return n;

     // 2nd approach - time-O(1)
     int org = n;
     return n & (n - 1);
}

bool check_num_is_power_of_2(int n)
{
     if (n & n - 1)
          return false;
     return true;
}

int count_the_num_set_bits(int n)
{
     int ans = 0;

     // 1nd approach
     // while (n)
     // {
     //      // if (n & 1)
     //      //      ans++;
     //      ans += n & 1; // same as above
     //      n = n >> 1;
     // }

     // 2nd approach ->optimal
     while (n)
     {
          ans++;
          n = n & n - 1;
     }
     return ans;
}

int main()
{

     // int a = ~(-6);

     // int x = 3, y = 8;
     // swap(x, y);
     // cout << x << " " << y << endl;

     // check_i_bit_set_or_not(13, 2);
     // cout << set_ith_bit(13, 2);
     // cout << clear_ith_bit(13, 3);
     // cout << toggle_ith_bit(13, 2);

     // cout << remove_last_set_bit(6) << endl;

     // cout << check_num_is_power_of_2(32) << endl;

     cout << count_the_num_set_bits(13) << endl;
}