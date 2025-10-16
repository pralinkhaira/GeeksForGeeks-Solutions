class Solution {
    public static int findEquilibrium(int arr[]) {
        int total = 0;
        for(int i = 0; i<arr.length;i++){
            total+=arr[i];
        }
        int current = 0;
        for(int i = 0;i<arr.length;i++){
            if(current == total - (current+arr[i])){;
                return i;
            }
            current+=arr[i];
        }
        return -1;
    }
}