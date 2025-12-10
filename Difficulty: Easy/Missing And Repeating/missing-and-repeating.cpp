class Solution {
    public:
    vector<int> findTwoElement(vector<int>& arr) {
        int n = arr.size();
        
        // Create a frequency array
        vector<int> freq(n + 1, 0);
        
        for(int i = 0; i < n; i++) {
            freq[arr[i]]++;
        }
        
        int repeating = -1, missing = -1;
        
        for(int i = 1; i <= n; i++) {
            if(freq[i] == 2) {
                repeating = i;
            } else if(freq[i] == 0) {
                missing = i;
            }
        }
        
        return {repeating, missing};
    }
};