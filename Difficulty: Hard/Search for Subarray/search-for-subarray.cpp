class Solution {
  public:
    void constructLps(vector<int> &pat, vector<int> &lps) {
        lps[0] = 0;
        int i = 1, len = 0;
        while(i<pat.size()){
            if(pat[i] == pat[len]){
                len++;
                lps[i] = len;
                i++;
            }
            else{
                if(len!=0)
                    len = lps[len-1];
                else{
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    vector<int> search(vector<int> &txt, vector<int> &pat) {
        int n = txt.size(), m = pat.size();
    
        vector<int> lps(m), res;
        constructLps(pat, lps);
        int i = 0, j = 0;
        while(i<n){
            if (txt[i]==pat[j]){
                i++; j++;
    
                if(j==m){
                    res.push_back(i-j);
                    j = lps[j-1];
                }
            }
            else{
                if(j!=0) j = lps[j-1];
                else     i++;
            }
        }
        
        return res;
    }
};