class Solution {
public:
    bool canFinish(int v, vector<vector<int>>& edges) {
        vector<vector<int>> adj(v);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v= edges[i][1];
            adj[u].push_back(v);
        }
        vector<int> inDegree(v+1,0);
        for(int i=0;i<v;i++){
            for(auto it:adj[i]){
                inDegree[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<v;i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }
        vector<int> topo;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:adj[node]){
                inDegree[it]--;
                if(inDegree[it]==0){
                    q.push(it);
                }
            }
        }
        if(topo.size()==v) return true;
        return false;
    }
};