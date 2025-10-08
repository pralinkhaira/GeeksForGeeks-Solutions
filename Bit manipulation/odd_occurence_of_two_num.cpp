#include <bits/stdc++.h>
using namespace std;

// brute force approach
vector<int> twoOddNum(vector<int> arr)
{

     map<int, int> mpp;
     for (int i = 0; i < arr.size(); i++)
     {
          mpp[arr[i]]++;
     }
     vector<int> ans;

     for (auto it : mpp)
     {
          if (it.second % 2)
          {
               ans.push_back(it.first);
          }
     }
     reverse(ans.begin(), ans.end());

     return ans;
}

int log2(int n)
{
     int cnt = 0;
     while (n != 1)
     {
          cnt++;
          n = n / 2;
     }
     return cnt;
}

int main()
{
     cout << log2(32);

     return 0;
}