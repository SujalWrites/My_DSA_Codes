class Solution {
public:
    void dfs(vector<vector<int>> &isConnected, int cur, vector<bool> &visited)
    {
        if (visited[cur] == true)
            return;
        visited[cur] = true;
        for (int i = 0; i < isConnected.size(); i++)
        {
            if (isConnected[cur][i])
                dfs(isConnected, i, visited);
        }
    }

    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int ans = 0;
        vector<bool> visited(isConnected.size(), false);

        for (int i = 0; i < isConnected.size(); i++)
        {
            if (visited[i] == false)
            {
                ans++;
                dfs(isConnected, i, visited);
            }
        }
        return ans;
    }

};