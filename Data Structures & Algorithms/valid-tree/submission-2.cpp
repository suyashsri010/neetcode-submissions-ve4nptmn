class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>> adjlist(n);
        if(edges.size()!=n-1) return false;
        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];

            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
        }

        vector<bool> visited(n,false);

        queue<pair<int,int>> q;
        visited[0] = true;
        q.push({0,-1});

        while(!q.empty()){
            auto [node,par] = q.front();
            q.pop();
            for(int neighbour: adjlist[node]){
                if(visited[neighbour] && neighbour!=par) return false;
                else if(!visited[neighbour]){
                    q.push({neighbour,node});
                    visited[neighbour] = true;
                }
            }
        }

        for(int i=0;i<n;i++){
            if(!visited[i]) return false;
        }
        
        return true;

    }
};
