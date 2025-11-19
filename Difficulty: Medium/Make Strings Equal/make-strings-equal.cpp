class Solution {
public:
    int minCost(string &s,string &t,vector<vector<char>> &transform,
                vector<int> &cost) {
        
        int n=s.size();
        
        // 26x26 distance matrix
        const int INF=1e9;
        vector<vector<int>> dist(26,vector<int>(26,INF));
        
        for(int i=0;i<26;i++){
            dist[i][i]=0;
        }
            
        
        // fill direct transform costs
        for(int i=0;i<transform.size();i++) {
            int u=transform[i][0]-'a';
            int v=transform[i][1]-'a';
            dist[u][v]=min(dist[u][v],cost[i]);
        }
        
        // Floyd–Warshall for 26 letters
        for(int k=0;k<26;k++) {
            for(int i=0;i<26;i++) {
                for(int j=0;j<26;j++) {
                    if(dist[i][k]<INF && dist[k][j]<INF)
                        dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
        
        long long ans=0;
        
        // For each position, find the best common char
        for(int i=0;i<n;i++) {
            int u=s[i]-'a';
            int v=t[i]-'a';
            
            int best=INF;
            
            for(int k=0;k<26;k++) {
                if(dist[u][k] < INF && dist[v][k] < INF) {
                    best=min(best,dist[u][k]+dist[v][k]);
                }
            }
            
            if(best==INF){
                return -1;
            }
            
            ans+=best;
        }
        
        return ans;
    }
};