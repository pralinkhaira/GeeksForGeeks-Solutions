class Solution {
    void pushZerosToEnd(int[] arr) {
        // code here
        int n = arr.length;
        int i = 0, j = 0;
        while(j<n){
            if(arr[j]==0) j++;
            else {
                int temp = arr[j];
                arr[j++] = arr[i];
                arr[i++] = temp;
            }
        }
    }
}