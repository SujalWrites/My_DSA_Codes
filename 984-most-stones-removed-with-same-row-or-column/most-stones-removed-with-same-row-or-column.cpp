class DisjointSet{
public:
    vector<int> rank, size, parent;
    DisjointSet(int n){
        rank.resize(n+1, 0);
        size.resize(n+1, 1);
        parent.resize(n+1);
        for(int i=0; i<=n; i++){
            parent[i] = i;
        }
    }
    int findpar(int node){
        if(parent[node]==node) return node;
        return parent[node] = findpar(parent[node]);
    }
    void unionbyrank(int u, int v){
        int ulp_u = findpar(u);
        int ulp_v = findpar(v);
        if(ulp_u==ulp_v) return;
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v]<rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionbysize(int u, int v){
        int ulp_u = findpar(u);
        int ulp_v = findpar(v);
        if(ulp_u==ulp_v) return;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxrow = 0;
        int maxcol = 0;
        for(auto it : stones){
            maxrow = max(maxrow, it[0]);
            maxcol = max(maxcol, it[1]);
        }
        DisjointSet ds(maxrow+maxcol+1);
        unordered_map<int,int> stonenodes;
        int stonecnt = 0;
        for(auto it : stones){
            int noderow = it[0];
            int nodecol = it[1]+maxrow+1;
            ds.unionbysize(noderow, nodecol);
            stonenodes[noderow] = 1;
            stonenodes[nodecol] = 1;
        }
        int n = stones.size();
        int cnt = 0;
        for(auto it : stonenodes){
            if(ds.findpar(it.first)==it.first) cnt++;
        }
        return n - cnt;
    }
};