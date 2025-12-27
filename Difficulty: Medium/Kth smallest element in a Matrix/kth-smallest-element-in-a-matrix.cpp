class Solution {
  public:
    int kthSmallest(vector<vector<int>> &mat, int k) {
        // code here
        int n=mat.size();
        priority_queue<int>q;
  for(int i=0;i<n;i++)
  {
      for(int j=0;j<n;j++)
      {
          q.push(mat[i][j]);
          if(q.size()>k)
          {
              q.pop();
          }
      }
  }
  return q.top();
    }
};