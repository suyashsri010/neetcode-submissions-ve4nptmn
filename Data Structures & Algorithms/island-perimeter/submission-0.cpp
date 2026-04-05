class Solution {
public:
    void dfs(vector<vector<int>>& grid,vector<vector<bool>> &visited,int i,int j, int &perimeter){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]==0){
            perimeter+=1;
            return;
        }
        if(visited[i][j]) return;
        visited[i][j]=true;
        dfs(grid,visited,i-1,j,perimeter);
        dfs(grid,visited,i,j+1,perimeter);
        dfs(grid,visited,i+1,j,perimeter);
        dfs(grid,visited,i,j-1,perimeter);
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int perimeter = 0;
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j] && grid[i][j]){
                    dfs(grid,visited,i,j,perimeter);
                }
            }
        }
        return perimeter;
    }
};