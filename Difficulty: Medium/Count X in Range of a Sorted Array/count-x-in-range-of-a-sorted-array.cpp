class Solution {
  public:
    vector<int> countXInRange(vector<int>& arr, vector<vector<int>>& queries) {
        ios_base::sync_with_stdio(false);
        vector <int> res;
        
        for(auto query : queries){
            int l = query[0];
            int r = query[1];
            int x = query[2];
            
            auto low = lower_bound(arr.begin()+l, arr.begin()+r+1, x);
            auto high = upper_bound(arr.begin()+l, arr.begin()+r+1, x);
            int freq = high - low;
            res.push_back(freq);
        }
        
        return res;
    }
};