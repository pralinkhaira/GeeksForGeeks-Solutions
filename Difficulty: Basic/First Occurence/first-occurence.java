class Solution {
    int firstOccurence(String txt, String pat) {
        // code here
        int n = txt.length();
        int m = pat.length();
        for(int i=0; i<=n-m;i++){
            if(txt.substring(i,i + m).equals(pat)){
                return i;
            }
        }
        return -1;
    }
}

