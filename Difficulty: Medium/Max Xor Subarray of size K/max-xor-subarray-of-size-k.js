class Solution {
    maxSubarrayXOR(arr, k) {
        // code here
        let ans =Number.MIN_VALUE;
        let n = arr.length;
        let ind = 0;
        let xor=0;
        while(ind<k){
            xor^=arr[ind];
            ind++;
        }
        ans = Math.max(xor,ans);
        for(let i=1;i<n-k+1;i++){
            //remove i-1
            let val = arr[i-1];
            xor^=val;
            //add i+k-1 
            val = arr[i+k-1];
            xor^=val;
            //calculate max xor
            ans = Math.max(xor,ans);
        }
        return ans;
    }
}