class Solution {
  public:
    int andInRange(int l, int r) {
        // code here
        int diff=r-l;
        int ans=0,num=0,num2=0;
        for(int i=0;i<32;i++){
            // start from LSB -> MSB, till each bit position find that number in l.
            if(l&1)num+=(1<<i);

            // if both bits are set (i.e. 1) in l and r, then check whether both number are in valid range or not.
            if((l&1) && (r&1)){
                int nn=(int)log2(num)+1;  // finding total no of bits in num + 1, to find highest number which will have 1 at that bit position.
                if((1<<nn)-num >= diff)ans+=(1<<i);  // if diff of l and r lies in the range, then add 2^i in ans.
            }

            l/=2;r/=2;
        }
        return ans;
    }
};
