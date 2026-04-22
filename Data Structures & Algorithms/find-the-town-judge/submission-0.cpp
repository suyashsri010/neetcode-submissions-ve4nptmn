class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> incoming(n+1,0),outgoing(n+1,0);
        for(auto &vec: trust){
            outgoing[vec[0]]++;
            incoming[vec[1]]++;
        }
        for(int i=1;i<=n;i++){
            if(outgoing[i]==0 && incoming[i]==n-1) return i;
        }
        return -1;
    }
};