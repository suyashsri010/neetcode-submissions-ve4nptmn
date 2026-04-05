class Solution {
public:
    int dfs(vector<vector<int>>& grid,vector<vector<bool>> &visited,int i, int j){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]==0 || visited[i][j]){
            return 0;
        }
        visited[i][j]=true;
        return 1+dfs(grid,visited,i,j-1)+dfs(grid,visited,i-1,j)+dfs(grid,visited,i,j+1)+dfs(grid,visited,i+1,j);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        int max_area = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    int area = dfs(grid,visited,i,j);
                    max_area = max(max_area,area);
                }
            }
        }
        return max_area;
    }
};
