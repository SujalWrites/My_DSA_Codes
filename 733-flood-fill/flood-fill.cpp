class Solution {
public:
    void dfs(int row, int col,vector<vector<int>> &image,int delrow[], int delcol[],int iniColor,int newColor,vector<vector<int>>& ans){
        ans[row][col]=newColor;
        int n=image.size();
        int m=image[0].size();
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==iniColor && ans[nrow][ncol]!=newColor){
                dfs(nrow,ncol,image,delrow,delcol,iniColor,newColor,ans);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int x, int y, int newColor) {
        int iniColor=image[x][y];
        vector<vector<int>> ans = image;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        dfs(x,y,image,delrow,delcol,iniColor,newColor,ans);
        return ans;
    }
};