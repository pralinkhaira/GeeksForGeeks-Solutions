class Solution {
  public:
    virtual bool checkCycle(int i, vector<vector<int>> &adj, vector<bool> &f1, vector<bool> &f2){
      f1[i]=true;       
      f2[i]=true;
      
      for(int x: adj[i]){
          if(!f1[x]){
              if(checkCycle(x, adj, f1, f2))
                return true;
          }
          else if(f2[x])
            return true;
      }
      
      f2[i] = false;
      return false;
     
    }
    
    virtual void setIndeg(int i, vector<vector<int>> &adj, vector<int> &indeg){
      queue<pair<int, int>> q;
      q.push({i, 0});
      while(!q.empty()){
        auto z = q.front();
        q.pop();
        
        int x = z.first;
        int cost = z.second;
        
        for(int m: adj[x]){
            if(indeg[m] < (cost+1)){
                indeg[m] = cost+1;
                q.push({m, cost+1});
            }
              
        }
        
      }
      return;         
    }
  
    virtual vector<int> findOrder(int n, vector<vector<int>> &prerequisites) {
      vector<vector<int>> adj(n);
      vector<int> indeg(n, 0);
      for(auto z: prerequisites){
          adj[z[1]].push_back(z[0]);
      }
      
    //   for(int i=0;i<n;i++){
    //       cout<<i<<" - ";
    //       for(auto z: adj[i])
    //         cout<<z<<" ";
    //       cout<<endl;    
    //   }
      
      
      vector<int> ans;
      
      vector<bool> f1(n, false);
      vector<bool> f2(n, false);
      
      for(int i=0;i<n;i++){
        if(checkCycle(i, adj, f1, f2))
          return ans;
      }
      
      
      queue<int> store;
      for(int i=0;i<n;i++){
        if(indeg[i] == 0)
          store.push(i);
      }
      
      if(store.empty())
        return ans;
      
      //fixing Indeg
      while(!store.empty()){
          int i = store.front();
          store.pop();
          setIndeg(i, adj, indeg);
      }
      
      queue<int> kk;
      for(int i=0;i<n;i++){
          if(indeg[i] == 0)
            kk.push(i);
      }
      
      while(!kk.empty()){
        int i = kk.front();
        kk.pop();
        
        ans.push_back(i);
        for(int x=0;x<n;x++){
            indeg[x]--;
            if(indeg[x] == 0)
              kk.push(x);
        }
        
      }
      
      
      return ans;
    }
};