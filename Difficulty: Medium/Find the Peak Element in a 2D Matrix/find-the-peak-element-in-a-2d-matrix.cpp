class Solution {
  public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        // code here
        
        int row = mat.size();
        int col = mat[0].size();
        
        int start = 0;
        int end = col-1;
        
        while(start<=end){ 
            int mid = start+((end-start)/2); // 
            
            int maxi = INT_MIN;
            int i;
            for(int k=0;k<row;k++){
                if(maxi<mat[k][mid]){
                    maxi = mat[k][mid];
                    i=k;
                }
            }
            
            if( mid+1 < col && mat[i][mid+1]>mat[i][mid])start=mid+1;
            else if(mid-1 >=0 && mat[i][mid-1]>mat[i][mid])end=mid-1;
            else return {i,mid};
        }
        
        return {-1,-1};
        
    }
};