class Solution {
public:
    void dfs(int node,vector<vector<int>>& adjlist,vector<bool> &visited){
        visited[node] = true;
        for(int neighbour: adjlist[node]){
            if(!visited[neighbour]){
                dfs(neighbour,adjlist,visited);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adjlist(n);

        for(auto &edge: edges){

            int u = edge[0];
            int v = edge[1];

            adjlist[u].push_back(v);
            adjlist[v].push_back(u);

        }

        int count = 0;

        vector<bool> visited(n,false);

        for(int i=0; i<n ;i++){
            if(!visited[i]){
                count++;
                dfs(i,adjlist,visited);
            }
        }

        return count;

    }
};
