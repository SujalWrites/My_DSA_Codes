class Solution {
public:
    void dfs(int par, int node, vector<int>& vis,
        int tin[], int low[],vector<int> adj[],vector<vector<int>> &bridge,int &timer){
        
        vis[node]=1;
        low[node]=tin[node]=timer;
        timer++;
        for(auto it:adj[node])
        {
            if(par==it) continue;
            if(vis[it]==0)
            {
                dfs(node,it,vis,tin,low,adj,bridge,timer);
                
                //if lowest insertion of adjNode after DFS
                // is greater lowest insertion of Node 
            //then we can not reach it then by any other path
                // so it will be a bridge 
                if(low[it] > tin[node])bridge.push_back({node,it});
            }
            low[node]=min(low[node],low[it]);
        }
    }
    vector<vector<int>> criticalConnections(int v, vector<vector<int>>& edges) {
        vector<int> vis(v,0);

        int tin[v]; // time of insertion

        int low[v]; // lowest time of insertion,
        // i.e. it will find out lowest time of insertion 
        // among its neighour but will not consider its parent

        
        vector<vector<int>> bridge;
        int timer=1;
        vector<int> adj[v];
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        dfs(-1,0,vis,tin,low,adj,bridge,timer);
        return bridge;
    }
};