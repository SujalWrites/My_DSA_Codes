class DisjointSet{
    public:
	vector<int> parent, rank, size;
    DisjointSet(int n){
        // Works for both 0 based nodes and 1 based nodes
        rank.resize(n+1, 0);
        size.resize(n+1, 1);
        parent.resize(n+1);
        for(int i=0; i<n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findUpar(int node){
        if(node == parent[node])
            return node;
        // Path compression
        return parent[node] = findUpar(parent[node]);
    }
    void unionByRank(int u, int v){
        // If the ultimate parent of both are same no need to do union
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);
        if(ulp_u == ulp_v)
           return;
        if(rank[ulp_u] < rank[ulp_v])
            parent[ulp_u] = ulp_v;
        else if(rank[ulp_v] < rank[ulp_u])
            parent[ulp_v] = ulp_u;
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionBySize(int u, int v){
        // If the ultimate parent of both are same no need to do union
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);
        if(ulp_u == ulp_v)
           return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& edges) {
        DisjointSet ds(n);
        int cntExtras=0;
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            if(ds.findUpar(u)==ds.findUpar(v)){
                cntExtras++;
            }
            else{
                ds.unionBySize(u,v);
            }
        }
        int cntC=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i){
                cntC++;
            }
        }
        int ans=cntC-1;
        if(cntExtras>=ans) return ans;
        return -1;
    }
};