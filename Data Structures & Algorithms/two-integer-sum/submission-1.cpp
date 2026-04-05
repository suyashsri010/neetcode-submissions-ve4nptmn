class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]=i;
        }
        for(int i=0;i<n;i++){
            int num = nums[i];
            int tar = target-num;
            if(mp.find(tar)!=mp.end()){
                if(mp[tar]!=i) return{i,mp[tar]};
            }
        }
        return {};
    }
};
