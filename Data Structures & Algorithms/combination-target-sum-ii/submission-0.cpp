class Solution {
public:
    void solve(int i,int sum,int target,vector<int>& candidates,vector<int>& temp,vector<vector<int>>& ans){
        if(sum==target){
            ans.push_back(temp);
            return;
        }
        if(i>=candidates.size() || sum>target) return;
        // take condition
        temp.push_back(candidates[i]);
        solve(i+1,sum+candidates[i],target,candidates,temp,ans);
        temp.pop_back();
        while(i+1<candidates.size() && candidates[i]==candidates[i+1]) i++;
        solve(i+1,sum,target,candidates,temp,ans);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int i = 0, sum = 0;
        sort(candidates.begin(),candidates.end());
        solve(i,sum,target,candidates,temp,ans);
        return ans;
    }
};
