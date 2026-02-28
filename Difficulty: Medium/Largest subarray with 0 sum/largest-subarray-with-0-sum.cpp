class Solution {
  public:
    int maxLength(vector<int>& arr) {
        unordered_map<int,int> mp;
        long long int sum = 0;
        int len = 0;
        for(int i = 0;i<arr.size();i++){
            sum += arr[i];
            if(sum == 0){
                len = max(len, i+1);
            }
            
            unordered_map<int,int>::iterator it = mp.find(sum);
            if(it!=mp.end()){
                len = max(len, i-it->second);
            }
            else{
                mp[sum] = i;
            }
        }
        return len;
    }
};