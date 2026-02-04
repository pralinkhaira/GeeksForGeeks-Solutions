class Solution {
  public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        
        int t=0;
        
        priority_queue<int> pq_right;
        priority_queue<int,vector<int>,greater<int>> pq_left;
        
        for(auto i:right){
            if(i<n){
                pq_right.push(i);
            }
        }
        
        for(auto i:left){
            if(i>0){
                pq_left.push(i);
            }
        }
        
        while(!pq_right.empty() || !pq_left.empty()){
            t++;
            if(!pq_right.empty()){
                int top=pq_right.top();
                if(top+t>=n){
                    pq_right.pop();
                }
            }
            if(!pq_left.empty()){
                int top=pq_left.top();
                if(top-t<=0){
                    pq_left.pop();
                }
            }
        }
        
        return t;
    }
};