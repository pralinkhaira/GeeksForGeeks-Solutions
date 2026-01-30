class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        // code here
        queue<int> q1 , q2;
        int n = q.size();
        
        for(int i=0;i<(n+1)/2;i++){
            q1.push(q.front());
            q.pop();
        }
        
        while(!q.empty()){
            q2.push(q.front());
            q.pop();
        }
        
        while(!q1.empty() && !q2.empty()){
            q.push(q1.front());
            q.push(q2.front());
            q1.pop();
            q2.pop();
        }
    }
};