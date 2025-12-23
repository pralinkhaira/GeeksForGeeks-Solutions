class Solution {
    int findFirst(int u, int n, int[] arr) {
        int l=0, h=n-1, res=n;

        while(l<=h) {
            int mid = l+(h-l)/2;

            if(arr[mid]>=u) {
                res=mid;
                h=mid-1;
            } else {
                l=mid+1;
            }
        }
        
        return res;
    }

    int findLast(int v, int n, int[] arr) {
        int l=0, h=n-1, res=-1;

        while(l<=h) {
            int mid = l+(h-l)/2;

            if(arr[mid]<=v) {
                res=mid;
                l=mid+1;
            } else {
                h=mid-1;
            }
        }

        return res;
    }
    
    public ArrayList<Integer> cntInRange(int[] arr, int[][] queries) {
        int n = arr.length, m = queries.length;
        Arrays.sort(arr);
        ArrayList<Integer> ans = new ArrayList<>();

        for(int[] query: queries) {
            int u = query[0], v = query[1];
            int firstOccurrence = findFirst(u, n, arr);
            int secondOccurrence = findLast(v, n, arr);

            ans.add(secondOccurrence - firstOccurrence + 1);
        }

        return  ans;
    }
}