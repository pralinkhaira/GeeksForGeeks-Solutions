class Solution {
    public int kthMissing(int[] arr, int k) {
        // code here
        ArrayList<Integer> res=new ArrayList<>();
        int j=0;
        int l=arr[arr.length-1];
        for(int i=1;res.size()<k;i++){
            if(j<arr.length && arr[j]==i){ j++;}
            else{
                res.add(i);
            }
        }
        return res.get(k-1);
        
    }
}