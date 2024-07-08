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
bool isValid(int newr , int newc , int n){
    return (newr>=0 && newr<n && newc>=0 && newc<n);
}
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DisjointSet ds(n*n);
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==0) continue;
                int dr[]={-1,0,1,0};
                int dc[]={0,-1,0,1};
                for(int i=0;i<4;i++){
                    int newr=row+dr[i];
                    int newc=col+dc[i];
                    if(isValid(newr,newc,n)&&grid[newr][newc]==1){
                        int nodeNo=row*n + col;
                        int adjNodeNo=newr*n + newc;
                        ds.unionBySize(nodeNo,adjNodeNo);
                    }
                }
            }
        }
        int mx=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==1)continue;
                int dr[]={-1,0,1,0};
                int dc[]={0,-1,0,1};
                set<int> components;
                for(int i=0;i<4;i++){
                    int newr=row+dr[i];
                    int newc=col+dc[i];
                    if(isValid(newr,  newc,  n)){
                        if(grid[newr][newc]==1){
                            components.insert(ds.findUpar(newr*n + newc));
                        }
                    }
                }
                int sizeTotal=1;
                for(auto it:components){
                    sizeTotal+=ds.size[it];
                }
                    mx=max(mx,sizeTotal);
                }
        }
        for(int cellNo=0;cellNo<n;cellNo++){
            mx=max(mx,ds.size[ds.findUpar(cellNo)]);
        }
        return mx;
    }
};