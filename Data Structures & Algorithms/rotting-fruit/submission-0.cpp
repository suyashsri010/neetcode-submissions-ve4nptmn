class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    visited[i][j]=true;
                }
            }
        }
        int time = 0;
        int drow[]={0,-1,0,1}, dcol[]={-1,0,1,0};
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            q.pop();
            time = max(time,t);
            for(int i=0;i<4;i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !visited[nrow][ncol] && grid[nrow][ncol]==1){
                    q.push({{nrow,ncol},t+1});
                    visited[nrow][ncol] = true;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !visited[i][j]) return -1;
            }
        }
        return time;
    }
};
