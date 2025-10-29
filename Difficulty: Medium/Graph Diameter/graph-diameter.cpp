class Solution {
  public:
    int diameter(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>>adj(V);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<bool>vis(V,false);
        
        int node=0;
        int dist=0;
        queue<int>q;
        q.push(0);
        
        while(!q.empty()){
           // dist++;
            int n=q.size();
            
            for(int i=0;i<n;i++){
                int x=q.front();
                vis[x]=true;
                q.pop();
                for(int i=0;i<adj[x].size();i++){
                    int y=adj[x][i];
                    if(vis[y]==false){
                        q.push(y);
                        node=y;
                    }
                }
            }
        }
        
        vector<bool>vis2(V,0);
        
        q.push(node);
        
        while(!q.empty()){
            dist++;
            int n=q.size();
            
            for(int i=0;i<n;i++){
                int x=q.front();
                vis2[x]=true;
                q.pop();
                for(int i=0;i<adj[x].size();i++){
                    int y=adj[x][i];
                    if(vis2[y]==false){
                        q.push(y);
                        node=y;
                    }
                }
            }
        }
        
        return dist-1;
    }
};
