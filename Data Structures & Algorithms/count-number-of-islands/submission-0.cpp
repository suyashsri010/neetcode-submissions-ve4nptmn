class Solution {
public:
    void dfs(vector<vector<char>>& grid,vector<vector<bool>> &visited,int i, int j){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]=='0' || visited[i][j]) return;
        visited[i][j]=true;
        dfs(grid,visited,i+1,j);
        dfs(grid,visited,i,j+1);
        dfs(grid,visited,i-1,j);
        dfs(grid,visited,i,j-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        int count = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    count ++;
                    dfs(grid,visited,i,j);
                }
            }
        }
        return count;
    }
};
