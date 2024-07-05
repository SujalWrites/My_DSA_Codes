class Solution {
public:


    int findCheapestPrice(int n, vector<vector<int>>& trains, int source, int destination, int K) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it:trains){
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int,pair<int,int>>> q;
        // {stops,{node,cost}}
        q.push({0,{source,0}});
        vector<int> dist(n,1e9);
        dist[source]=0;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int stops=it.first;
            int node=it.second.first;
            int cost=it.second.second;
            if(stops>K) continue;
            for(auto iter:adj[node]){
                int adjNode=iter.first;
                int edWeight=iter.second;
                if(cost+edWeight<dist[adjNode] && stops<=K){
                    dist[adjNode]=cost+edWeight;
                    q.push({stops+1,{adjNode,cost+edWeight}});
                }
            }
        }
        if(dist[destination]==1e9) return -1;
        return dist[destination];
    }
};

