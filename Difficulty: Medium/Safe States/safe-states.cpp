class Solution {
    bool dfs(vector<vector<int>>& adj, vector<bool>& safe, vector<int>& vis, int u) {
        
        vis[u] = 1;
        int check = 0;
        
        for(int v : adj[u]) {
            if(safe[v] == true) check++;
            
            else if(!vis[v]) {
                if(dfs(adj, safe, vis, v)) {
                    safe[v] = true;
                    check++;
                }
            }
        }
        int paths = adj[u].size();
        return check == paths; // if all the paths are safe then the current node is a safe node, otherwise not safe
    }
  public:
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        
        vector<int> outDeg(V, 0);
        vector<int> vis(V, 0);
        
        for(auto it: edges) {
            adj[it[0]].push_back(it[1]);
            outDeg[it[0]]++;
        }
        
        vector<bool> safe(V, false);
        for(int i = 0; i < V; i++) {
            if(outDeg[i] == 0) safe[i] = true;
        }
        
        for(int i = 0; i < V; i++) {
            if(!vis[i] && !safe[i]) {
                safe[i] = dfs(adj, safe, vis, i); // if not already known about this node, then check its all the paths using dfs
            } 
        }
        
        vector<int> safeNodes;
        for(int i = 0; i < V; i++) {
            if(safe[i]) safeNodes.push_back(i);
        }
        
        return safeNodes;
    }
    
};