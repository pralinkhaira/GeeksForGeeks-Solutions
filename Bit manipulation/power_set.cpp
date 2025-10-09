

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets(vector<int> &nums)
{
     vector<vector<int>> ans;
     int n = nums.size();
     int subsets = 1 << n;
     for (int no = 0; no < subsets; no++)
     {
          vector<int> list;
          for (int i = 0; i < n; i++)
          {
               if (no & (1 << i))
               {
                    list.push_back(nums[i]);
               }
          }
          ans.push_back(list);
     }
     return ans;
}

int main()
{

     return 0;
}