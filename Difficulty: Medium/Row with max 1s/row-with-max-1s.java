class Solution {
    public int rowWithMax1s(int arr[][]) {
        int index = Integer.MAX_VALUE , ans = Integer.MAX_VALUE , row = 0;
       for(int [] ar : arr){
           int firstOne = getFirstOccurrenceOfOne(ar);
           if(firstOne < index){
               index = firstOne;
               ans = row;
           }
           row++;
       }
        return ans;
    }
    
    public int getFirstOccurrenceOfOne(int [] arr){
        int l = 0 , r = arr.length - 1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(arr[mid] == 1){
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return r;
    }
}