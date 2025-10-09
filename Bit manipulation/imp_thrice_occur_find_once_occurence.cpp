#include <bits/stdc++.h>
using namespace std;
// q.> single number II

// bruteforce
// is using of hashMapp

// better solution

int one_occurence_IN_thrice_occurenced(vector<int> num)
{
     int ans = 0, cnt;
     for (int bitIdx = 0; bitIdx <= 31; bitIdx++)
     {
          cnt = 0;
          for (int i = 0; i < num.size(); i++)
          {
               if (num[i] & (1 << bitIdx))
               {
                    cnt++;
               }
          }
          if (cnt % 3 == 1)
          {
               ans = ans | (1 << bitIdx);
          }
     }

     return ans;
}

// optimal solution
int one_occurence_IN_thrice_occurenced02(vector<int> nums)
{
     sort(nums.begin(), nums.end());
     for (int i = 0; i < nums.size(); i += 3)
     {
          if (nums[i] != nums[i + 1])
          {
               return nums[i];
          }
     }
     return nums[nums.size() - 1];
}

int main()
{

     vector<int> b = {1, 4, 4, 4, 6, 6, 6};
     cout << one_occurence_IN_thrice_occurenced02(b);

     return 0;
}