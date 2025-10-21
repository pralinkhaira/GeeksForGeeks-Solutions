class Solution {
  public:
    vector<int> topKFreq(vector<int> &arr, int k) {
        vector<pair<int, int>> freq(1e5 + 7, {0, 0});
        
        for (int num : arr) {
            freq[num].first = num;
            freq[num].second++;
        }

        vector<pair<int, int>> filtered;
        for (auto& p : freq) {
            if (p.second > 0) {
                filtered.push_back(p);
            }
        }

        sort(filtered.begin(), filtered.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.second == b.second)
                return a.first > b.first;
            return a.second > b.second;
        });

        vector<int> ans;
        for (int i = 0; i < k && i < filtered.size(); i++) {
            ans.push_back(filtered[i].first);
        }

        return ans;
    }
};