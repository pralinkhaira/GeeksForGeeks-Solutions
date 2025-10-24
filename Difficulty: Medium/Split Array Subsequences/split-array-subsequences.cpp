class Solution {
  public:
    bool isPossible(vector<int>& arr, int k) {
        // code here
        unordered_map<int, int> mp, skip;
        for (int i: arr) mp[i]++;
        for (int i=0; i<arr.size(); i++) {
            if (skip[arr[i]]>0 || mp[arr[i]-1]>0) continue;
            int start=arr[i];
            while (mp[start]>0) {
                mp[start]--;
                if (start!=arr[i]) skip[start]++;
                start++;
            }
            if ((start-arr[i])<k) return false;
        } return true;
    }
};