class Solution {
public:
    void solve(int i,vector<int>&nums,int target,vector<vector<int>> &ans,vector<int>&temp,int sum){
        if(i>=nums.size()) return;
        if(sum>target) return;
        if(sum==target){
            ans.push_back(temp);
            return;
        }
        // take condition
        temp.push_back(nums[i]);
        solve(i,nums,target,ans,temp,sum+nums[i]);
        temp.pop_back();
        solve(i+1,nums,target,ans,temp,sum);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0,nums,target,ans,temp,0);
        return ans;
    }
};
