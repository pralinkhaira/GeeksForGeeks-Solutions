class Solution {
  public:
    bool sameFreq(string& s) {
        vector<int> freq(26,0);
        for(auto& c:s){
            freq[c-'a']++;
        }
        int c1=-1, cnt1=0, c2=-1, cnt2=0;
        for(int i=0;i<26;i++){
            if(freq[i]==0) continue;
            else if(freq[i]==c1) cnt1++;
            else if(freq[i]==c2) cnt2++;
            else if(c1==-1) {
                c1=freq[i];
                cnt1++;
            }
            else if(c2==-1) {
                c2=freq[i];
                cnt2++;
            }
            else return false;
        }
        if(c2==-1) return true;
        if(c1<c2){
            if(c1==1 && cnt1==1) return true;
            if(c2-c1==1 && cnt2==1) return true;
        } else {
            if(c2==1 && cnt2==1) return true;
            if(c1-c2==1 && cnt1==1) return true;
        }
        return false;
        
    }
};