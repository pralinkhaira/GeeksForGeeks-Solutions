class DisJointSet{
  public:
    vector<int> par, rank;
    DisJointSet(int V){
      par.resize(V);
      iota(par.begin(), par.end(), 0);
      rank.resize(V, 0);
    }
    
    virtual int parent(int i){
      if(par[i] == i)
        return i;
      return par[i] = parent(par[i]);    
    }
    
    virtual void unionSet(int u, int v){
      int pu = parent(u);    
      int pv = parent(v);
      
      if(pu != pv){
        if(rank[pu] < rank[pv]){
          par[pu] = pv;    
        }
        else if(rank[pu] > rank[pv]){
          par[pv] = pu;    
        }
        else{
            par[pv] = pu;
            rank[pu]++;
        }
      }
    }
    
};
class Solution {
  public:
    virtual int minConnect(int V, vector<vector<int>>& edges) {
      int e = edges.size();
      if(e < (V-1))
        return -1;
        
      DisJointSet *ds = new DisJointSet(V);
      int tempEdges=0;
      
      for(auto z: edges){
        if((ds->parent(z[0])) == (ds->parent(z[1])))
          tempEdges++;
        else
          ds->unionSet(z[0], z[1]);
      }
      
      int comp=0;
      for(int i=0;i<V;i++){
          if((ds->parent(i)) == i)
            comp++;
      }
      
      int req = comp-1;
      
      return (req<=tempEdges)? req: -1;
              
    }
};