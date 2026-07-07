class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        queue<tuple<int,int,int>> q; // (i,j,dist)

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    q.push({i,j,0});
                }
            }
        }

        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};

        while(!q.empty()){
            auto [row,col,dist] = q.front();
            q.pop();

            for(int i=0;i<4;i++){
                int nrow = row+drow[i];
                int ncol = col+dcol[i];

                if(nrow<0 || nrow>=m || ncol<0 || ncol>=n || grid[nrow][ncol]==-1 || dist+1>=grid[nrow][ncol]) continue;
                else{
                    grid[nrow][ncol] = 1 + dist;
                    q.push({nrow,ncol,1+dist});
                }
            }

        }
    }
};
