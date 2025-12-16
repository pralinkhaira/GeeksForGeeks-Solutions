class Solution {
  public:
    bool areRotations(string &s1, string &s2) {
        // code here
        string tmp = s2 + "#" + s1 + s1;
        int n = tmp.length(), m = s2.length();
        vector<int> p(n, 0);
        for(int i = 1, k = 0; i < n; i++) {
            while(k > 0 && tmp[k] != tmp[i]) k = p[k - 1];
            if(tmp[i] == tmp[k]) ++k;
            p[i] = k;
            if(i > m && p[i] == m) return true; 
        }
        return false;
    }
};