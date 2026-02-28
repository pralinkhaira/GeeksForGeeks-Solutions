class Solution {
  public:
    vector<int> removeDuplicates(vector<int> &arr) {
        set<int>s(arr.begin(), arr.end());
        vector<int>ans(s.begin(), s.end());
        return ans;
    }
};